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
// source: google/cloud/beyondcorp/appconnectors/v1/app_connectors_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_APPCONNECTORS_V1_INTERNAL_APP_CONNECTORS_LOGGING_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_APPCONNECTORS_V1_INTERNAL_APP_CONNECTORS_LOGGING_DECORATOR_H

#include "google/cloud/beyondcorp/appconnectors/v1/internal/app_connectors_stub.h"
#include "google/cloud/tracing_options.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace beyondcorp_appconnectors_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class AppConnectorsServiceLogging : public AppConnectorsServiceStub {
 public:
  ~AppConnectorsServiceLogging() override = default;
  AppConnectorsServiceLogging(std::shared_ptr<AppConnectorsServiceStub> child,
                              TracingOptions tracing_options,
                              std::set<std::string> components);

  StatusOr<
      google::cloud::beyondcorp::appconnectors::v1::ListAppConnectorsResponse>
  ListAppConnectors(grpc::ClientContext& context,
                    google::cloud::beyondcorp::appconnectors::v1::
                        ListAppConnectorsRequest const& request) override;

  StatusOr<google::cloud::beyondcorp::appconnectors::v1::AppConnector>
  GetAppConnector(grpc::ClientContext& context,
                  google::cloud::beyondcorp::appconnectors::v1::
                      GetAppConnectorRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateAppConnector(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::beyondcorp::appconnectors::v1::
          CreateAppConnectorRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateAppConnector(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::beyondcorp::appconnectors::v1::
          UpdateAppConnectorRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteAppConnector(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::beyondcorp::appconnectors::v1::
          DeleteAppConnectorRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncReportStatus(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::beyondcorp::appconnectors::v1::ReportStatusRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::shared_ptr<AppConnectorsServiceStub> child_;
  TracingOptions tracing_options_;
  std::set<std::string> components_;
};  // AppConnectorsServiceLogging

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace beyondcorp_appconnectors_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_APPCONNECTORS_V1_INTERNAL_APP_CONNECTORS_LOGGING_DECORATOR_H
