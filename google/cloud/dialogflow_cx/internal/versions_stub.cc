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
// source: google/cloud/dialogflow/cx/v3/version.proto

#include "google/cloud/dialogflow_cx/internal/versions_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dialogflow/cx/v3/version.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

VersionsStub::~VersionsStub() = default;

StatusOr<google::cloud::dialogflow::cx::v3::ListVersionsResponse>
DefaultVersionsStub::ListVersions(
    grpc::ClientContext& client_context,
    google::cloud::dialogflow::cx::v3::ListVersionsRequest const& request) {
  google::cloud::dialogflow::cx::v3::ListVersionsResponse response;
  auto status = grpc_stub_->ListVersions(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::cloud::dialogflow::cx::v3::Version>
DefaultVersionsStub::GetVersion(
    grpc::ClientContext& client_context,
    google::cloud::dialogflow::cx::v3::GetVersionRequest const& request) {
  google::cloud::dialogflow::cx::v3::Version response;
  auto status = grpc_stub_->GetVersion(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultVersionsStub::AsyncCreateVersion(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::dialogflow::cx::v3::CreateVersionRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::dialogflow::cx::v3::CreateVersionRequest const&
                 request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCreateVersion(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::cloud::dialogflow::cx::v3::Version>
DefaultVersionsStub::UpdateVersion(
    grpc::ClientContext& client_context,
    google::cloud::dialogflow::cx::v3::UpdateVersionRequest const& request) {
  google::cloud::dialogflow::cx::v3::Version response;
  auto status = grpc_stub_->UpdateVersion(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

Status DefaultVersionsStub::DeleteVersion(
    grpc::ClientContext& client_context,
    google::cloud::dialogflow::cx::v3::DeleteVersionRequest const& request) {
  google::protobuf::Empty response;
  auto status = grpc_stub_->DeleteVersion(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

future<StatusOr<google::longrunning::Operation>>
DefaultVersionsStub::AsyncLoadVersion(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::dialogflow::cx::v3::LoadVersionRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](
          grpc::ClientContext* context,
          google::cloud::dialogflow::cx::v3::LoadVersionRequest const& request,
          grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncLoadVersion(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::cloud::dialogflow::cx::v3::CompareVersionsResponse>
DefaultVersionsStub::CompareVersions(
    grpc::ClientContext& client_context,
    google::cloud::dialogflow::cx::v3::CompareVersionsRequest const& request) {
  google::cloud::dialogflow::cx::v3::CompareVersionsResponse response;
  auto status =
      grpc_stub_->CompareVersions(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultVersionsStub::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::longrunning::GetOperationRequest const& request,
             grpc::CompletionQueue* cq) {
        return operations_->AsyncGetOperation(context, request, cq);
      },
      request, std::move(context));
}

future<Status> DefaultVersionsStub::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return cq
      .MakeUnaryRpc(
          [this](grpc::ClientContext* context,
                 google::longrunning::CancelOperationRequest const& request,
                 grpc::CompletionQueue* cq) {
            return operations_->AsyncCancelOperation(context, request, cq);
          },
          request, std::move(context))
      .then([](future<StatusOr<google::protobuf::Empty>> f) {
        return f.get().status();
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google
