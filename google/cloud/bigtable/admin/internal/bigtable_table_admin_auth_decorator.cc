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
// source: google/bigtable/admin/v2/bigtable_table_admin.proto

#include "google/cloud/bigtable/admin/internal/bigtable_table_admin_auth_decorator.h"
#include <google/bigtable/admin/v2/bigtable_table_admin.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace bigtable_admin_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

BigtableTableAdminAuth::BigtableTableAdminAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<BigtableTableAdminStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::bigtable::admin::v2::Table>
BigtableTableAdminAuth::CreateTable(
    grpc::ClientContext& context,
    google::bigtable::admin::v2::CreateTableRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateTable(context, request);
}

StatusOr<google::bigtable::admin::v2::ListTablesResponse>
BigtableTableAdminAuth::ListTables(
    grpc::ClientContext& context,
    google::bigtable::admin::v2::ListTablesRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListTables(context, request);
}

StatusOr<google::bigtable::admin::v2::Table> BigtableTableAdminAuth::GetTable(
    grpc::ClientContext& context,
    google::bigtable::admin::v2::GetTableRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetTable(context, request);
}

future<StatusOr<google::longrunning::Operation>>
BigtableTableAdminAuth::AsyncUpdateTable(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::admin::v2::UpdateTableRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncUpdateTable(cq, *std::move(context), request);
      });
}

Status BigtableTableAdminAuth::DeleteTable(
    grpc::ClientContext& context,
    google::bigtable::admin::v2::DeleteTableRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteTable(context, request);
}

future<StatusOr<google::longrunning::Operation>>
BigtableTableAdminAuth::AsyncUndeleteTable(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::admin::v2::UndeleteTableRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncUndeleteTable(cq, *std::move(context), request);
      });
}

StatusOr<google::bigtable::admin::v2::Table>
BigtableTableAdminAuth::ModifyColumnFamilies(
    grpc::ClientContext& context,
    google::bigtable::admin::v2::ModifyColumnFamiliesRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ModifyColumnFamilies(context, request);
}

Status BigtableTableAdminAuth::DropRowRange(
    grpc::ClientContext& context,
    google::bigtable::admin::v2::DropRowRangeRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DropRowRange(context, request);
}

StatusOr<google::bigtable::admin::v2::GenerateConsistencyTokenResponse>
BigtableTableAdminAuth::GenerateConsistencyToken(
    grpc::ClientContext& context,
    google::bigtable::admin::v2::GenerateConsistencyTokenRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GenerateConsistencyToken(context, request);
}

StatusOr<google::bigtable::admin::v2::CheckConsistencyResponse>
BigtableTableAdminAuth::CheckConsistency(
    grpc::ClientContext& context,
    google::bigtable::admin::v2::CheckConsistencyRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CheckConsistency(context, request);
}

future<StatusOr<google::longrunning::Operation>>
BigtableTableAdminAuth::AsyncCreateBackup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::admin::v2::CreateBackupRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateBackup(cq, *std::move(context), request);
      });
}

StatusOr<google::bigtable::admin::v2::Backup> BigtableTableAdminAuth::GetBackup(
    grpc::ClientContext& context,
    google::bigtable::admin::v2::GetBackupRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetBackup(context, request);
}

StatusOr<google::bigtable::admin::v2::Backup>
BigtableTableAdminAuth::UpdateBackup(
    grpc::ClientContext& context,
    google::bigtable::admin::v2::UpdateBackupRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateBackup(context, request);
}

Status BigtableTableAdminAuth::DeleteBackup(
    grpc::ClientContext& context,
    google::bigtable::admin::v2::DeleteBackupRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteBackup(context, request);
}

StatusOr<google::bigtable::admin::v2::ListBackupsResponse>
BigtableTableAdminAuth::ListBackups(
    grpc::ClientContext& context,
    google::bigtable::admin::v2::ListBackupsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListBackups(context, request);
}

future<StatusOr<google::longrunning::Operation>>
BigtableTableAdminAuth::AsyncRestoreTable(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::admin::v2::RestoreTableRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncRestoreTable(cq, *std::move(context), request);
      });
}

StatusOr<google::iam::v1::Policy> BigtableTableAdminAuth::GetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::GetIamPolicyRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetIamPolicy(context, request);
}

StatusOr<google::iam::v1::Policy> BigtableTableAdminAuth::SetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::SetIamPolicyRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->SetIamPolicy(context, request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
BigtableTableAdminAuth::TestIamPermissions(
    grpc::ClientContext& context,
    google::iam::v1::TestIamPermissionsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->TestIamPermissions(context, request);
}

future<StatusOr<google::bigtable::admin::v2::CheckConsistencyResponse>>
BigtableTableAdminAuth::AsyncCheckConsistency(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::admin::v2::CheckConsistencyRequest const& request) {
  using ReturnType =
      StatusOr<google::bigtable::admin::v2::CheckConsistencyResponse>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCheckConsistency(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
BigtableTableAdminAuth::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncGetOperation(cq, *std::move(context), request);
      });
}

future<Status> BigtableTableAdminAuth::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) return make_ready_future(std::move(context).status());
        return child->AsyncCancelOperation(cq, *std::move(context), request);
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigtable_admin_internal
}  // namespace cloud
}  // namespace google
