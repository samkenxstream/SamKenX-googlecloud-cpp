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
// source: google/cloud/ids/v1/ids.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IDS_INTERNAL_IDS_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IDS_INTERNAL_IDS_CONNECTION_IMPL_H

#include "google/cloud/ids/ids_connection.h"
#include "google/cloud/ids/ids_connection_idempotency_policy.h"
#include "google/cloud/ids/ids_options.h"
#include "google/cloud/ids/internal/ids_retry_traits.h"
#include "google/cloud/ids/internal/ids_stub.h"
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
namespace ids_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class IDSConnectionImpl : public ids::IDSConnection {
 public:
  ~IDSConnectionImpl() override = default;

  IDSConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<ids_internal::IDSStub> stub, Options const& options);

  StreamRange<google::cloud::ids::v1::Endpoint> ListEndpoints(
      google::cloud::ids::v1::ListEndpointsRequest request) override;

  StatusOr<google::cloud::ids::v1::Endpoint> GetEndpoint(
      google::cloud::ids::v1::GetEndpointRequest const& request) override;

  future<StatusOr<google::cloud::ids::v1::Endpoint>> CreateEndpoint(
      google::cloud::ids::v1::CreateEndpointRequest const& request) override;

  future<StatusOr<google::cloud::ids::v1::OperationMetadata>> DeleteEndpoint(
      google::cloud::ids::v1::DeleteEndpointRequest const& request) override;

 private:
  std::unique_ptr<ids::IDSRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<ids::IDSRetryPolicyOption>()) {
      return options.get<ids::IDSRetryPolicyOption>()->clone();
    }
    return retry_policy_prototype_->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<ids::IDSBackoffPolicyOption>()) {
      return options.get<ids::IDSBackoffPolicyOption>()->clone();
    }
    return backoff_policy_prototype_->clone();
  }

  std::unique_ptr<ids::IDSConnectionIdempotencyPolicy> idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<ids::IDSConnectionIdempotencyPolicyOption>()) {
      return options.get<ids::IDSConnectionIdempotencyPolicyOption>()->clone();
    }
    return idempotency_policy_->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<ids_internal::IDSStub> stub_;
  std::unique_ptr<ids::IDSRetryPolicy const> retry_policy_prototype_;
  std::unique_ptr<BackoffPolicy const> backoff_policy_prototype_;
  std::unique_ptr<ids::IDSConnectionIdempotencyPolicy> idempotency_policy_;

  std::unique_ptr<PollingPolicy> polling_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<ids::IDSPollingPolicyOption>()) {
      return options.get<ids::IDSPollingPolicyOption>()->clone();
    }
    return polling_policy_prototype_->clone();
  }

  std::unique_ptr<PollingPolicy const> polling_policy_prototype_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace ids_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IDS_INTERNAL_IDS_CONNECTION_IMPL_H
