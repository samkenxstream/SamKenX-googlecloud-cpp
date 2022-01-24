// Copyright 2020 Google LLC
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
// source: google/iam/credentials/v1/iamcredentials.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_INTERNAL_IAM_CREDENTIALS_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_INTERNAL_IAM_CREDENTIALS_CONNECTION_IMPL_H

#include "google/cloud/iam/iam_credentials_connection.h"
#include "google/cloud/iam/iam_credentials_connection_idempotency_policy.h"
#include "google/cloud/iam/iam_credentials_options.h"
#include "google/cloud/iam/internal/iam_credentials_retry_traits.h"
#include "google/cloud/iam/internal/iam_credentials_stub.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace iam_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class IAMCredentialsConnectionImpl : public iam::IAMCredentialsConnection {
 public:
  ~IAMCredentialsConnectionImpl() override = default;

  IAMCredentialsConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<iam_internal::IAMCredentialsStub> stub,
      Options const& options);

  StatusOr<google::iam::credentials::v1::GenerateAccessTokenResponse>
  GenerateAccessToken(
      google::iam::credentials::v1::GenerateAccessTokenRequest const& request)
      override;

  StatusOr<google::iam::credentials::v1::GenerateIdTokenResponse>
  GenerateIdToken(google::iam::credentials::v1::GenerateIdTokenRequest const&
                      request) override;

  StatusOr<google::iam::credentials::v1::SignBlobResponse> SignBlob(
      google::iam::credentials::v1::SignBlobRequest const& request) override;

  StatusOr<google::iam::credentials::v1::SignJwtResponse> SignJwt(
      google::iam::credentials::v1::SignJwtRequest const& request) override;

 private:
  std::unique_ptr<iam::IAMCredentialsRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<iam::IAMCredentialsRetryPolicyOption>()) {
      return options.get<iam::IAMCredentialsRetryPolicyOption>()->clone();
    }
    return retry_policy_prototype_->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<iam::IAMCredentialsBackoffPolicyOption>()) {
      return options.get<iam::IAMCredentialsBackoffPolicyOption>()->clone();
    }
    return backoff_policy_prototype_->clone();
  }

  std::unique_ptr<iam::IAMCredentialsConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<iam::IAMCredentialsConnectionIdempotencyPolicyOption>()) {
      return options
          .get<iam::IAMCredentialsConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return idempotency_policy_->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<iam_internal::IAMCredentialsStub> stub_;
  std::unique_ptr<iam::IAMCredentialsRetryPolicy const> retry_policy_prototype_;
  std::unique_ptr<BackoffPolicy const> backoff_policy_prototype_;
  std::unique_ptr<iam::IAMCredentialsConnectionIdempotencyPolicy>
      idempotency_policy_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
namespace gcpcxxV1 = GOOGLE_CLOUD_CPP_NS;  // NOLINT(misc-unused-alias-decls)
}  // namespace iam_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_INTERNAL_IAM_CREDENTIALS_CONNECTION_IMPL_H
