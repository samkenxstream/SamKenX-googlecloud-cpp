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
// source: google/cloud/orchestration/airflow/service/v1/environments.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPOSER_INTERNAL_ENVIRONMENTS_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPOSER_INTERNAL_ENVIRONMENTS_CONNECTION_IMPL_H

#include "google/cloud/composer/environments_connection.h"
#include "google/cloud/composer/environments_connection_idempotency_policy.h"
#include "google/cloud/composer/environments_options.h"
#include "google/cloud/composer/internal/environments_retry_traits.h"
#include "google/cloud/composer/internal/environments_stub.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace composer_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class EnvironmentsConnectionImpl : public composer::EnvironmentsConnection {
 public:
  ~EnvironmentsConnectionImpl() override = default;

  EnvironmentsConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<composer_internal::EnvironmentsStub> stub,
      Options const& options);

  future<
      StatusOr<google::cloud::orchestration::airflow::service::v1::Environment>>
  CreateEnvironment(google::cloud::orchestration::airflow::service::v1::
                        CreateEnvironmentRequest const& request) override;

  StatusOr<google::cloud::orchestration::airflow::service::v1::Environment>
  GetEnvironment(google::cloud::orchestration::airflow::service::v1::
                     GetEnvironmentRequest const& request) override;

  StreamRange<google::cloud::orchestration::airflow::service::v1::Environment>
  ListEnvironments(google::cloud::orchestration::airflow::service::v1::
                       ListEnvironmentsRequest request) override;

  future<
      StatusOr<google::cloud::orchestration::airflow::service::v1::Environment>>
  UpdateEnvironment(google::cloud::orchestration::airflow::service::v1::
                        UpdateEnvironmentRequest const& request) override;

  future<StatusOr<
      google::cloud::orchestration::airflow::service::v1::OperationMetadata>>
  DeleteEnvironment(google::cloud::orchestration::airflow::service::v1::
                        DeleteEnvironmentRequest const& request) override;

 private:
  std::unique_ptr<composer::EnvironmentsRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<composer::EnvironmentsRetryPolicyOption>()) {
      return options.get<composer::EnvironmentsRetryPolicyOption>()->clone();
    }
    return retry_policy_prototype_->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<composer::EnvironmentsBackoffPolicyOption>()) {
      return options.get<composer::EnvironmentsBackoffPolicyOption>()->clone();
    }
    return backoff_policy_prototype_->clone();
  }

  std::unique_ptr<composer::EnvironmentsConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options
            .has<composer::EnvironmentsConnectionIdempotencyPolicyOption>()) {
      return options
          .get<composer::EnvironmentsConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return idempotency_policy_->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<composer_internal::EnvironmentsStub> stub_;
  std::unique_ptr<composer::EnvironmentsRetryPolicy const>
      retry_policy_prototype_;
  std::unique_ptr<BackoffPolicy const> backoff_policy_prototype_;
  std::unique_ptr<composer::EnvironmentsConnectionIdempotencyPolicy>
      idempotency_policy_;

  std::unique_ptr<PollingPolicy> polling_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<composer::EnvironmentsPollingPolicyOption>()) {
      return options.get<composer::EnvironmentsPollingPolicyOption>()->clone();
    }
    return polling_policy_prototype_->clone();
  }

  std::unique_ptr<PollingPolicy const> polling_policy_prototype_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace composer_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPOSER_INTERNAL_ENVIRONMENTS_CONNECTION_IMPL_H
