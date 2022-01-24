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
// source: google/cloud/retail/v2/prediction_service.proto

#include "google/cloud/retail/internal/prediction_connection_impl.h"
#include "google/cloud/retail/internal/prediction_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace retail_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

PredictionServiceConnectionImpl::PredictionServiceConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<retail_internal::PredictionServiceStub> stub,
    Options const& options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      retry_policy_prototype_(
          options.get<retail::PredictionServiceRetryPolicyOption>()->clone()),
      backoff_policy_prototype_(
          options.get<retail::PredictionServiceBackoffPolicyOption>()->clone()),
      idempotency_policy_(
          options
              .get<retail::PredictionServiceConnectionIdempotencyPolicyOption>()
              ->clone()) {}

StatusOr<google::cloud::retail::v2::PredictResponse>
PredictionServiceConnectionImpl::Predict(
    google::cloud::retail::v2::PredictRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->Predict(request),
      [this](grpc::ClientContext& context,
             google::cloud::retail::v2::PredictRequest const& request) {
        return stub_->Predict(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace retail_internal
}  // namespace cloud
}  // namespace google
