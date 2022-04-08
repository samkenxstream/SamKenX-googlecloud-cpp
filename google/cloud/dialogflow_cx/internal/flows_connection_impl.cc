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
// source: google/cloud/dialogflow/cx/v3/flow.proto

#include "google/cloud/dialogflow_cx/internal/flows_connection_impl.h"
#include "google/cloud/dialogflow_cx/internal/flows_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

FlowsConnectionImpl::FlowsConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<dialogflow_cx_internal::FlowsStub> stub, Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options), dialogflow_cx_internal::FlowsDefaultOptions(
                                  FlowsConnection::options()))) {}

StatusOr<google::cloud::dialogflow::cx::v3::Flow>
FlowsConnectionImpl::CreateFlow(
    google::cloud::dialogflow::cx::v3::CreateFlowRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateFlow(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::dialogflow::cx::v3::CreateFlowRequest const& request) {
        return stub_->CreateFlow(context, request);
      },
      request, __func__);
}

Status FlowsConnectionImpl::DeleteFlow(
    google::cloud::dialogflow::cx::v3::DeleteFlowRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteFlow(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::dialogflow::cx::v3::DeleteFlowRequest const& request) {
        return stub_->DeleteFlow(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::dialogflow::cx::v3::Flow>
FlowsConnectionImpl::ListFlows(
    google::cloud::dialogflow::cx::v3::ListFlowsRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry =
      std::shared_ptr<dialogflow_cx::FlowsRetryPolicy const>(retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListFlows(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::dialogflow::cx::v3::Flow>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::dialogflow::cx::v3::ListFlowsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::dialogflow::cx::v3::ListFlowsRequest const&
                       request) { return stub->ListFlows(context, request); },
            r, function_name);
      },
      [](google::cloud::dialogflow::cx::v3::ListFlowsResponse r) {
        std::vector<google::cloud::dialogflow::cx::v3::Flow> result(
            r.flows().size());
        auto& messages = *r.mutable_flows();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::dialogflow::cx::v3::Flow> FlowsConnectionImpl::GetFlow(
    google::cloud::dialogflow::cx::v3::GetFlowRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->GetFlow(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::GetFlowRequest const& request) {
        return stub_->GetFlow(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::dialogflow::cx::v3::Flow>
FlowsConnectionImpl::UpdateFlow(
    google::cloud::dialogflow::cx::v3::UpdateFlowRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateFlow(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::dialogflow::cx::v3::UpdateFlowRequest const& request) {
        return stub_->UpdateFlow(context, request);
      },
      request, __func__);
}

future<StatusOr<google::protobuf::Struct>> FlowsConnectionImpl::TrainFlow(
    google::cloud::dialogflow::cx::v3::TrainFlowRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::protobuf::Struct>(
      background_->cq(), request,
      [stub](
          google::cloud::CompletionQueue& cq,
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::dialogflow::cx::v3::TrainFlowRequest const& request) {
        return stub->AsyncTrainFlow(cq, std::move(context), request);
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
      &google::cloud::internal::ExtractLongRunningResultMetadata<
          google::protobuf::Struct>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->TrainFlow(request), polling_policy(), __func__);
}

StatusOr<google::cloud::dialogflow::cx::v3::FlowValidationResult>
FlowsConnectionImpl::ValidateFlow(
    google::cloud::dialogflow::cx::v3::ValidateFlowRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->ValidateFlow(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::ValidateFlowRequest const&
                 request) { return stub_->ValidateFlow(context, request); },
      request, __func__);
}

StatusOr<google::cloud::dialogflow::cx::v3::FlowValidationResult>
FlowsConnectionImpl::GetFlowValidationResult(
    google::cloud::dialogflow::cx::v3::GetFlowValidationResultRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetFlowValidationResult(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::
                 GetFlowValidationResultRequest const& request) {
        return stub_->GetFlowValidationResult(context, request);
      },
      request, __func__);
}

future<StatusOr<google::cloud::dialogflow::cx::v3::ImportFlowResponse>>
FlowsConnectionImpl::ImportFlow(
    google::cloud::dialogflow::cx::v3::ImportFlowRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::dialogflow::cx::v3::ImportFlowResponse>(
      background_->cq(), request,
      [stub](
          google::cloud::CompletionQueue& cq,
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::dialogflow::cx::v3::ImportFlowRequest const& request) {
        return stub->AsyncImportFlow(cq, std::move(context), request);
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
          google::cloud::dialogflow::cx::v3::ImportFlowResponse>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->ImportFlow(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::dialogflow::cx::v3::ExportFlowResponse>>
FlowsConnectionImpl::ExportFlow(
    google::cloud::dialogflow::cx::v3::ExportFlowRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::dialogflow::cx::v3::ExportFlowResponse>(
      background_->cq(), request,
      [stub](
          google::cloud::CompletionQueue& cq,
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::dialogflow::cx::v3::ExportFlowRequest const& request) {
        return stub->AsyncExportFlow(cq, std::move(context), request);
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
          google::cloud::dialogflow::cx::v3::ExportFlowResponse>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->ExportFlow(request), polling_policy(), __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google
