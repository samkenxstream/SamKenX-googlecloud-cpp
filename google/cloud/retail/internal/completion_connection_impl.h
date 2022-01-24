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
// source: google/cloud/retail/v2/completion_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RETAIL_INTERNAL_COMPLETION_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RETAIL_INTERNAL_COMPLETION_CONNECTION_IMPL_H

#include "google/cloud/retail/completion_connection.h"
#include "google/cloud/retail/completion_connection_idempotency_policy.h"
#include "google/cloud/retail/completion_options.h"
#include "google/cloud/retail/internal/completion_retry_traits.h"
#include "google/cloud/retail/internal/completion_stub.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace retail_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class CompletionServiceConnectionImpl
    : public retail::CompletionServiceConnection {
 public:
  ~CompletionServiceConnectionImpl() override = default;

  CompletionServiceConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<retail_internal::CompletionServiceStub> stub,
      Options const& options);

  StatusOr<google::cloud::retail::v2::CompleteQueryResponse> CompleteQuery(
      google::cloud::retail::v2::CompleteQueryRequest const& request) override;

  future<StatusOr<google::cloud::retail::v2::ImportCompletionDataResponse>>
  ImportCompletionData(
      google::cloud::retail::v2::ImportCompletionDataRequest const& request)
      override;

 private:
  std::unique_ptr<retail::CompletionServiceRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<retail::CompletionServiceRetryPolicyOption>()) {
      return options.get<retail::CompletionServiceRetryPolicyOption>()->clone();
    }
    return retry_policy_prototype_->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<retail::CompletionServiceBackoffPolicyOption>()) {
      return options.get<retail::CompletionServiceBackoffPolicyOption>()
          ->clone();
    }
    return backoff_policy_prototype_->clone();
  }

  std::unique_ptr<retail::CompletionServiceConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<
            retail::CompletionServiceConnectionIdempotencyPolicyOption>()) {
      return options
          .get<retail::CompletionServiceConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return idempotency_policy_->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<retail_internal::CompletionServiceStub> stub_;
  std::unique_ptr<retail::CompletionServiceRetryPolicy const>
      retry_policy_prototype_;
  std::unique_ptr<BackoffPolicy const> backoff_policy_prototype_;
  std::unique_ptr<retail::CompletionServiceConnectionIdempotencyPolicy>
      idempotency_policy_;

  std::unique_ptr<PollingPolicy> polling_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<retail::CompletionServicePollingPolicyOption>()) {
      return options.get<retail::CompletionServicePollingPolicyOption>()
          ->clone();
    }
    return polling_policy_prototype_->clone();
  }

  std::unique_ptr<PollingPolicy const> polling_policy_prototype_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace retail_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RETAIL_INTERNAL_COMPLETION_CONNECTION_IMPL_H
