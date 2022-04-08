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
// source: google/cloud/dialogflow/cx/v3/transition_route_group.proto

#include "google/cloud/dialogflow_cx/internal/transition_route_groups_connection_impl.h"
#include "google/cloud/dialogflow_cx/internal/transition_route_groups_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

TransitionRouteGroupsConnectionImpl::TransitionRouteGroupsConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<dialogflow_cx_internal::TransitionRouteGroupsStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options),
          dialogflow_cx_internal::TransitionRouteGroupsDefaultOptions(
              TransitionRouteGroupsConnection::options()))) {}

StreamRange<google::cloud::dialogflow::cx::v3::TransitionRouteGroup>
TransitionRouteGroupsConnectionImpl::ListTransitionRouteGroups(
    google::cloud::dialogflow::cx::v3::ListTransitionRouteGroupsRequest
        request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry =
      std::shared_ptr<dialogflow_cx::TransitionRouteGroupsRetryPolicy const>(
          retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListTransitionRouteGroups(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::dialogflow::cx::v3::TransitionRouteGroup>>(
      std::move(request),
      [stub, retry, backoff, idempotency,
       function_name](google::cloud::dialogflow::cx::v3::
                          ListTransitionRouteGroupsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::dialogflow::cx::v3::
                       ListTransitionRouteGroupsRequest const& request) {
              return stub->ListTransitionRouteGroups(context, request);
            },
            r, function_name);
      },
      [](google::cloud::dialogflow::cx::v3::ListTransitionRouteGroupsResponse
             r) {
        std::vector<google::cloud::dialogflow::cx::v3::TransitionRouteGroup>
            result(r.transition_route_groups().size());
        auto& messages = *r.mutable_transition_route_groups();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::dialogflow::cx::v3::TransitionRouteGroup>
TransitionRouteGroupsConnectionImpl::GetTransitionRouteGroup(
    google::cloud::dialogflow::cx::v3::GetTransitionRouteGroupRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetTransitionRouteGroup(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::
                 GetTransitionRouteGroupRequest const& request) {
        return stub_->GetTransitionRouteGroup(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::dialogflow::cx::v3::TransitionRouteGroup>
TransitionRouteGroupsConnectionImpl::CreateTransitionRouteGroup(
    google::cloud::dialogflow::cx::v3::CreateTransitionRouteGroupRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateTransitionRouteGroup(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::
                 CreateTransitionRouteGroupRequest const& request) {
        return stub_->CreateTransitionRouteGroup(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::dialogflow::cx::v3::TransitionRouteGroup>
TransitionRouteGroupsConnectionImpl::UpdateTransitionRouteGroup(
    google::cloud::dialogflow::cx::v3::UpdateTransitionRouteGroupRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateTransitionRouteGroup(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::
                 UpdateTransitionRouteGroupRequest const& request) {
        return stub_->UpdateTransitionRouteGroup(context, request);
      },
      request, __func__);
}

Status TransitionRouteGroupsConnectionImpl::DeleteTransitionRouteGroup(
    google::cloud::dialogflow::cx::v3::DeleteTransitionRouteGroupRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteTransitionRouteGroup(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::
                 DeleteTransitionRouteGroupRequest const& request) {
        return stub_->DeleteTransitionRouteGroup(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google
