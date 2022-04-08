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
// source: google/cloud/dialogflow/cx/v3/deployment.proto

#include "google/cloud/dialogflow_cx/internal/deployments_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dialogflow/cx/v3/deployment.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DeploymentsLogging::DeploymentsLogging(std::shared_ptr<DeploymentsStub> child,
                                       TracingOptions tracing_options,
                                       std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::dialogflow::cx::v3::ListDeploymentsResponse>
DeploymentsLogging::ListDeployments(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::ListDeploymentsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::ListDeploymentsRequest const&
                 request) { return child_->ListDeployments(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dialogflow::cx::v3::Deployment>
DeploymentsLogging::GetDeployment(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::GetDeploymentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::GetDeploymentRequest const&
                 request) { return child_->GetDeployment(context, request); },
      context, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google
