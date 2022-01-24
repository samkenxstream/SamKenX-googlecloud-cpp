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
// source: google/appengine/v1/appengine.proto

#include "google/cloud/appengine/internal/applications_connection_impl.h"
#include "google/cloud/appengine/internal/applications_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace appengine_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ApplicationsConnectionImpl::ApplicationsConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<appengine_internal::ApplicationsStub> stub,
    Options const& options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      retry_policy_prototype_(
          options.get<appengine::ApplicationsRetryPolicyOption>()->clone()),
      backoff_policy_prototype_(
          options.get<appengine::ApplicationsBackoffPolicyOption>()->clone()),
      idempotency_policy_(
          options
              .get<appengine::ApplicationsConnectionIdempotencyPolicyOption>()
              ->clone()),
      polling_policy_prototype_(
          options.get<appengine::ApplicationsPollingPolicyOption>()->clone()) {}

StatusOr<google::appengine::v1::Application>
ApplicationsConnectionImpl::GetApplication(
    google::appengine::v1::GetApplicationRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetApplication(request),
      [this](grpc::ClientContext& context,
             google::appengine::v1::GetApplicationRequest const& request) {
        return stub_->GetApplication(context, request);
      },
      request, __func__);
}

future<StatusOr<google::appengine::v1::Application>>
ApplicationsConnectionImpl::CreateApplication(
    google::appengine::v1::CreateApplicationRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::appengine::v1::Application>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::appengine::v1::CreateApplicationRequest const& request) {
        return stub->AsyncCreateApplication(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::appengine::v1::Application>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateApplication(request), polling_policy(),
      __func__);
}

future<StatusOr<google::appengine::v1::Application>>
ApplicationsConnectionImpl::UpdateApplication(
    google::appengine::v1::UpdateApplicationRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::appengine::v1::Application>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::appengine::v1::UpdateApplicationRequest const& request) {
        return stub->AsyncUpdateApplication(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::appengine::v1::Application>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateApplication(request), polling_policy(),
      __func__);
}

future<StatusOr<google::appengine::v1::Application>>
ApplicationsConnectionImpl::RepairApplication(
    google::appengine::v1::RepairApplicationRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::appengine::v1::Application>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::appengine::v1::RepairApplicationRequest const& request) {
        return stub->AsyncRepairApplication(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::appengine::v1::Application>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->RepairApplication(request), polling_policy(),
      __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace appengine_internal
}  // namespace cloud
}  // namespace google
