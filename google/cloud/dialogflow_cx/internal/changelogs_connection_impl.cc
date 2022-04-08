// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/dialogflow/cx/v3/changelog.proto

#include "google/cloud/dialogflow_cx/internal/changelogs_connection_impl.h"
#include "google/cloud/dialogflow_cx/internal/changelogs_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ChangelogsConnectionImpl::ChangelogsConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<dialogflow_cx_internal::ChangelogsStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options), dialogflow_cx_internal::ChangelogsDefaultOptions(
                                  ChangelogsConnection::options()))) {}

StreamRange<google::cloud::dialogflow::cx::v3::Changelog>
ChangelogsConnectionImpl::ListChangelogs(
    google::cloud::dialogflow::cx::v3::ListChangelogsRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry = std::shared_ptr<dialogflow_cx::ChangelogsRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListChangelogs(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::dialogflow::cx::v3::Changelog>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::dialogflow::cx::v3::ListChangelogsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](
                grpc::ClientContext& context,
                google::cloud::dialogflow::cx::v3::ListChangelogsRequest const&
                    request) { return stub->ListChangelogs(context, request); },
            r, function_name);
      },
      [](google::cloud::dialogflow::cx::v3::ListChangelogsResponse r) {
        std::vector<google::cloud::dialogflow::cx::v3::Changelog> result(
            r.changelogs().size());
        auto& messages = *r.mutable_changelogs();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::dialogflow::cx::v3::Changelog>
ChangelogsConnectionImpl::GetChangelog(
    google::cloud::dialogflow::cx::v3::GetChangelogRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetChangelog(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::GetChangelogRequest const&
                 request) { return stub_->GetChangelog(context, request); },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google
