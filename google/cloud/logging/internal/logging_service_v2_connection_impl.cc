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

#include "google/cloud/logging/internal/logging_service_v2_connection_impl.h"
#include "google/cloud/logging/internal/logging_service_v2_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace logging_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

LoggingServiceV2ConnectionImpl::LoggingServiceV2ConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<logging_internal::LoggingServiceV2Stub> stub,
    Options const& options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      retry_policy_prototype_(
          options.get<logging::LoggingServiceV2RetryPolicyOption>()->clone()),
      backoff_policy_prototype_(
          options.get<logging::LoggingServiceV2BackoffPolicyOption>()->clone()),
      idempotency_policy_(
          options
              .get<logging::LoggingServiceV2ConnectionIdempotencyPolicyOption>()
              ->clone()) {}

Status LoggingServiceV2ConnectionImpl::DeleteLog(
    google::logging::v2::DeleteLogRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteLog(request),
      [this](grpc::ClientContext& context,
             google::logging::v2::DeleteLogRequest const& request) {
        return stub_->DeleteLog(context, request);
      },
      request, __func__);
}

StatusOr<google::logging::v2::WriteLogEntriesResponse>
LoggingServiceV2ConnectionImpl::WriteLogEntries(
    google::logging::v2::WriteLogEntriesRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->WriteLogEntries(request),
      [this](grpc::ClientContext& context,
             google::logging::v2::WriteLogEntriesRequest const& request) {
        return stub_->WriteLogEntries(context, request);
      },
      request, __func__);
}

StreamRange<google::logging::v2::LogEntry>
LoggingServiceV2ConnectionImpl::ListLogEntries(
    google::logging::v2::ListLogEntriesRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry = std::shared_ptr<logging::LoggingServiceV2RetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListLogEntries(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::logging::v2::LogEntry>>(
      std::move(request),
      [stub, retry, backoff, idempotency,
       function_name](google::logging::v2::ListLogEntriesRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::logging::v2::ListLogEntriesRequest const& request) {
              return stub->ListLogEntries(context, request);
            },
            r, function_name);
      },
      [](google::logging::v2::ListLogEntriesResponse r) {
        std::vector<google::logging::v2::LogEntry> result(r.entries().size());
        auto& messages = *r.mutable_entries();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StreamRange<google::api::MonitoredResourceDescriptor>
LoggingServiceV2ConnectionImpl::ListMonitoredResourceDescriptors(
    google::logging::v2::ListMonitoredResourceDescriptorsRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry = std::shared_ptr<logging::LoggingServiceV2RetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency =
      idempotency_policy()->ListMonitoredResourceDescriptors(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::api::MonitoredResourceDescriptor>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::logging::v2::ListMonitoredResourceDescriptorsRequest const&
              r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::logging::v2::
                       ListMonitoredResourceDescriptorsRequest const& request) {
              return stub->ListMonitoredResourceDescriptors(context, request);
            },
            r, function_name);
      },
      [](google::logging::v2::ListMonitoredResourceDescriptorsResponse r) {
        std::vector<google::api::MonitoredResourceDescriptor> result(
            r.resource_descriptors().size());
        auto& messages = *r.mutable_resource_descriptors();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StreamRange<std::string> LoggingServiceV2ConnectionImpl::ListLogs(
    google::logging::v2::ListLogsRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry = std::shared_ptr<logging::LoggingServiceV2RetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListLogs(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<StreamRange<std::string>>(
      std::move(request),
      [stub, retry, backoff, idempotency,
       function_name](google::logging::v2::ListLogsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::logging::v2::ListLogsRequest const& request) {
              return stub->ListLogs(context, request);
            },
            r, function_name);
      },
      [](google::logging::v2::ListLogsResponse r) {
        std::vector<std::string> result(r.log_names().size());
        auto& messages = *r.mutable_log_names();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::logging::v2::TailLogEntriesRequest,
    google::logging::v2::TailLogEntriesResponse>>
LoggingServiceV2ConnectionImpl::AsyncTailLogEntries() {
  return stub_->AsyncTailLogEntries(background_->cq(),
                                    absl::make_unique<grpc::ClientContext>());
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace logging_internal
}  // namespace cloud
}  // namespace google
