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
// source:
// google/cloud/beyondcorp/appconnections/v1/app_connections_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_APPCONNECTIONS_V1_INTERNAL_APP_CONNECTIONS_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_APPCONNECTIONS_V1_INTERNAL_APP_CONNECTIONS_METADATA_DECORATOR_H

#include "google/cloud/beyondcorp/appconnections/v1/internal/app_connections_stub.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace beyondcorp_appconnections_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class AppConnectionsServiceMetadata : public AppConnectionsServiceStub {
 public:
  ~AppConnectionsServiceMetadata() override = default;
  explicit AppConnectionsServiceMetadata(
      std::shared_ptr<AppConnectionsServiceStub> child);

  StatusOr<
      google::cloud::beyondcorp::appconnections::v1::ListAppConnectionsResponse>
  ListAppConnections(grpc::ClientContext& context,
                     google::cloud::beyondcorp::appconnections::v1::
                         ListAppConnectionsRequest const& request) override;

  StatusOr<google::cloud::beyondcorp::appconnections::v1::AppConnection>
  GetAppConnection(grpc::ClientContext& context,
                   google::cloud::beyondcorp::appconnections::v1::
                       GetAppConnectionRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateAppConnection(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::beyondcorp::appconnections::v1::
          CreateAppConnectionRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateAppConnection(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::beyondcorp::appconnections::v1::
          UpdateAppConnectionRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteAppConnection(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::beyondcorp::appconnections::v1::
          DeleteAppConnectionRequest const& request) override;

  StatusOr<google::cloud::beyondcorp::appconnections::v1::
               ResolveAppConnectionsResponse>
  ResolveAppConnections(
      grpc::ClientContext& context,
      google::cloud::beyondcorp::appconnections::v1::
          ResolveAppConnectionsRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  void SetMetadata(grpc::ClientContext& context,
                   std::string const& request_params);
  void SetMetadata(grpc::ClientContext& context);

  std::shared_ptr<AppConnectionsServiceStub> child_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace beyondcorp_appconnections_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_APPCONNECTIONS_V1_INTERNAL_APP_CONNECTIONS_METADATA_DECORATOR_H
