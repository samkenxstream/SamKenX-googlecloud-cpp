// Copyright 2021 Google LLC
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
// source: google/logging/v2/logging.proto

#include "google/cloud/logging/internal/logging_service_v2_metadata_decorator.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/logging/v2/logging.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace logging_internal {
inline namespace GOOGLE_CLOUD_CPP_GENERATED_NS {

LoggingServiceV2Metadata::LoggingServiceV2Metadata(
    std::shared_ptr<LoggingServiceV2Stub> child)
    : child_(std::move(child)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

Status LoggingServiceV2Metadata::DeleteLog(
    grpc::ClientContext& context,
    google::logging::v2::DeleteLogRequest const& request) {
  SetMetadata(context, "log_name=" + request.log_name());
  return child_->DeleteLog(context, request);
}

StatusOr<google::logging::v2::WriteLogEntriesResponse>
LoggingServiceV2Metadata::WriteLogEntries(
    grpc::ClientContext& context,
    google::logging::v2::WriteLogEntriesRequest const& request) {
  SetMetadata(context, {});
  return child_->WriteLogEntries(context, request);
}

StatusOr<google::logging::v2::ListLogEntriesResponse>
LoggingServiceV2Metadata::ListLogEntries(
    grpc::ClientContext& context,
    google::logging::v2::ListLogEntriesRequest const& request) {
  SetMetadata(context, {});
  return child_->ListLogEntries(context, request);
}

StatusOr<google::logging::v2::ListMonitoredResourceDescriptorsResponse>
LoggingServiceV2Metadata::ListMonitoredResourceDescriptors(
    grpc::ClientContext& context,
    google::logging::v2::ListMonitoredResourceDescriptorsRequest const&
        request) {
  SetMetadata(context, {});
  return child_->ListMonitoredResourceDescriptors(context, request);
}

StatusOr<google::logging::v2::ListLogsResponse>
LoggingServiceV2Metadata::ListLogs(
    grpc::ClientContext& context,
    google::logging::v2::ListLogsRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListLogs(context, request);
}

void LoggingServiceV2Metadata::SetMetadata(grpc::ClientContext& context,
                                           std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  context.AddMetadata("x-goog-api-client", api_client_header_);
}

}  // namespace GOOGLE_CLOUD_CPP_GENERATED_NS
}  // namespace logging_internal
}  // namespace cloud
}  // namespace google
