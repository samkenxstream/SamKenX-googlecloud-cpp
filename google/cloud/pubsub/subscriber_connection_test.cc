// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/pubsub/subscriber_connection.h"
#include "google/cloud/pubsub/ack_handler.h"
#include "google/cloud/pubsub/exactly_once_ack_handler.h"
#include "google/cloud/pubsub/internal/defaults.h"
#include "google/cloud/pubsub/testing/fake_streaming_pull.h"
#include "google/cloud/pubsub/testing/mock_subscriber_stub.h"
#include "google/cloud/pubsub/testing/test_retry_policies.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/testing_util/scoped_log.h"
#include "google/cloud/testing_util/status_matchers.h"
#include "google/cloud/testing_util/validate_metadata.h"
#include <gmock/gmock.h>
#include <atomic>

namespace google {
namespace cloud {
namespace pubsub {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace {

using ::google::cloud::pubsub_testing::FakeAsyncStreamingPull;
using ::google::cloud::testing_util::ValidateMetadataFixture;
using ::testing::AtLeast;
using ::testing::Contains;
using ::testing::HasSubstr;
using ::testing::Pair;
using ::testing::UnorderedElementsAre;

std::shared_ptr<SubscriberConnection> MakeTestSubscriberConnection(
    Subscription subscription,
    std::shared_ptr<pubsub_internal::SubscriberStub> mock, Options opts = {}) {
  opts.set<GrpcCredentialOption>(grpc::InsecureChannelCredentials());
  opts = pubsub_internal::DefaultSubscriberOptions(
      pubsub_testing::MakeTestOptions(std::move(opts)));
  // The CI scripts set an environment variable that overrides this option. We
  // are not interested in this behavior for this test.
  opts.unset<google::cloud::UserProjectOption>();
  std::vector<std::shared_ptr<pubsub_internal::SubscriberStub>> children{
      std::move(mock)};
  return MakeTestSubscriberConnection(std::move(subscription), std::move(opts),
                                      std::move(children));
}

Options UserSuppliedThreadsOption(CompletionQueue const& cq) {
  return Options{}.set<GrpcCompletionQueueOption>(cq);
}

/// @test Verify key events are logged
TEST(SubscriberConnectionTest, MakeSubscriberConnectionSetupsLogging) {
  auto mock = std::make_shared<pubsub_testing::MockSubscriberStub>();
  Subscription const subscription("test-project", "test-subscription");
  EXPECT_CALL(*mock, AsyncModifyAckDeadline)
      .WillRepeatedly([](google::cloud::CompletionQueue&, auto,
                         google::pubsub::v1::ModifyAckDeadlineRequest const&) {
        return make_ready_future(Status{});
      });
  EXPECT_CALL(*mock, AsyncAcknowledge)
      .WillRepeatedly([](google::cloud::CompletionQueue&, auto,
                         google::pubsub::v1::AcknowledgeRequest const&) {
        return make_ready_future(Status{});
      });
  EXPECT_CALL(*mock, AsyncStreamingPull)
      .Times(AtLeast(1))
      .WillRepeatedly(FakeAsyncStreamingPull);

  testing_util::ScopedLog log;

  CompletionQueue cq;
  auto subscriber = MakeTestSubscriberConnection(
      subscription, mock,
      UserSuppliedThreadsOption(cq).set<TracingComponentsOption>(
          {"rpc", "rpc-streams"}));
  std::atomic_flag received_one{false};
  promise<void> waiter;
  auto handler = [&](Message const&, AckHandler h) {
    std::move(h).ack();
    if (received_one.test_and_set()) return;
    waiter.set_value();
  };
  std::thread t([&cq] { cq.Run(); });
  google::cloud::internal::OptionsSpan span(subscriber->options());
  auto response = subscriber->Subscribe({handler});
  waiter.get_future().wait();
  response.cancel();
  ASSERT_STATUS_OK(response.get());
  // We need to explicitly cancel any pending timers (some of which may be quite
  // long) left by the subscription.
  cq.CancelAll();
  cq.Shutdown();
  t.join();

  auto const log_lines = log.ExtractLines();
  EXPECT_THAT(log_lines, Contains(HasSubstr("AsyncStreamingPull")));
  EXPECT_THAT(log_lines, Contains(HasSubstr("Start")));
  EXPECT_THAT(log_lines, Contains(HasSubstr("Write")));
  EXPECT_THAT(log_lines, Contains(HasSubstr("Read")));
  EXPECT_THAT(log_lines, Contains(HasSubstr("Finish")));
}

/// @test Verify the metadata decorator is configured
TEST(SubscriberConnectionTest, MakeSubscriberConnectionSetupsMetadata) {
  auto mock = std::make_shared<pubsub_testing::MockSubscriberStub>();
  Subscription const subscription("test-project", "test-subscription");
  EXPECT_CALL(*mock, AsyncModifyAckDeadline)
      .WillRepeatedly([](google::cloud::CompletionQueue&, auto,
                         google::pubsub::v1::ModifyAckDeadlineRequest const&) {
        return make_ready_future(Status{});
      });
  EXPECT_CALL(*mock, AsyncAcknowledge)
      .WillRepeatedly([](google::cloud::CompletionQueue&, auto,
                         google::pubsub::v1::AcknowledgeRequest const&) {
        return make_ready_future(Status{});
      });

  EXPECT_CALL(*mock, AsyncStreamingPull)
      .Times(AtLeast(1))
      .WillRepeatedly(
          [&](google::cloud::CompletionQueue const& cq, auto context) {
            ValidateMetadataFixture fixture;
            auto metadata = fixture.GetMetadata(*context);
            EXPECT_THAT(
                metadata,
                UnorderedElementsAre(
                    Pair("x-goog-api-client",
                         google::cloud::internal::ApiClientHeader("generator")),
                    Pair("x-goog-request-params",
                         "subscription=" + subscription.FullName())));
            return FakeAsyncStreamingPull(cq, std::move(context));
          });

  auto subscriber = MakeTestSubscriberConnection(subscription, mock);
  std::atomic_flag received_one{false};
  promise<void> waiter;
  auto handler = [&](Message const&, AckHandler h) {
    std::move(h).ack();
    if (received_one.test_and_set()) return;
    waiter.set_value();
  };
  google::cloud::internal::OptionsSpan span(subscriber->options());
  auto response = subscriber->Subscribe({handler});
  waiter.get_future().wait();
  response.cancel();
  ASSERT_STATUS_OK(response.get());
}

}  // namespace
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub
}  // namespace cloud
}  // namespace google
