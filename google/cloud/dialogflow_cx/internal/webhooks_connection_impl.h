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
// source: google/cloud/dialogflow/cx/v3/webhook.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_INTERNAL_WEBHOOKS_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_INTERNAL_WEBHOOKS_CONNECTION_IMPL_H

#include "google/cloud/dialogflow_cx/internal/webhooks_retry_traits.h"
#include "google/cloud/dialogflow_cx/internal/webhooks_stub.h"
#include "google/cloud/dialogflow_cx/webhooks_connection.h"
#include "google/cloud/dialogflow_cx/webhooks_connection_idempotency_policy.h"
#include "google/cloud/dialogflow_cx/webhooks_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class WebhooksConnectionImpl : public dialogflow_cx::WebhooksConnection {
 public:
  ~WebhooksConnectionImpl() override = default;

  WebhooksConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<dialogflow_cx_internal::WebhooksStub> stub,
      Options options);

  Options options() override { return options_; }

  StreamRange<google::cloud::dialogflow::cx::v3::Webhook> ListWebhooks(
      google::cloud::dialogflow::cx::v3::ListWebhooksRequest request) override;

  StatusOr<google::cloud::dialogflow::cx::v3::Webhook> GetWebhook(
      google::cloud::dialogflow::cx::v3::GetWebhookRequest const& request)
      override;

  StatusOr<google::cloud::dialogflow::cx::v3::Webhook> CreateWebhook(
      google::cloud::dialogflow::cx::v3::CreateWebhookRequest const& request)
      override;

  StatusOr<google::cloud::dialogflow::cx::v3::Webhook> UpdateWebhook(
      google::cloud::dialogflow::cx::v3::UpdateWebhookRequest const& request)
      override;

  Status DeleteWebhook(
      google::cloud::dialogflow::cx::v3::DeleteWebhookRequest const& request)
      override;

 private:
  std::unique_ptr<dialogflow_cx::WebhooksRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<dialogflow_cx::WebhooksRetryPolicyOption>()) {
      return options.get<dialogflow_cx::WebhooksRetryPolicyOption>()->clone();
    }
    return options_.get<dialogflow_cx::WebhooksRetryPolicyOption>()->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<dialogflow_cx::WebhooksBackoffPolicyOption>()) {
      return options.get<dialogflow_cx::WebhooksBackoffPolicyOption>()->clone();
    }
    return options_.get<dialogflow_cx::WebhooksBackoffPolicyOption>()->clone();
  }

  std::unique_ptr<dialogflow_cx::WebhooksConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options
            .has<dialogflow_cx::WebhooksConnectionIdempotencyPolicyOption>()) {
      return options
          .get<dialogflow_cx::WebhooksConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return options_
        .get<dialogflow_cx::WebhooksConnectionIdempotencyPolicyOption>()
        ->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<dialogflow_cx_internal::WebhooksStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_INTERNAL_WEBHOOKS_CONNECTION_IMPL_H
