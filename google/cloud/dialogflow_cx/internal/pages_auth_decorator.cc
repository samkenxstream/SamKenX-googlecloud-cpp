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
// source: google/cloud/dialogflow/cx/v3/page.proto

#include "google/cloud/dialogflow_cx/internal/pages_auth_decorator.h"
#include <google/cloud/dialogflow/cx/v3/page.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

PagesAuth::PagesAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<PagesStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::dialogflow::cx::v3::ListPagesResponse>
PagesAuth::ListPages(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::ListPagesRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListPages(context, request);
}

StatusOr<google::cloud::dialogflow::cx::v3::Page> PagesAuth::GetPage(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::GetPageRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetPage(context, request);
}

StatusOr<google::cloud::dialogflow::cx::v3::Page> PagesAuth::CreatePage(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::CreatePageRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreatePage(context, request);
}

StatusOr<google::cloud::dialogflow::cx::v3::Page> PagesAuth::UpdatePage(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::UpdatePageRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdatePage(context, request);
}

Status PagesAuth::DeletePage(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::DeletePageRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeletePage(context, request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google
