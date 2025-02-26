// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_INTERNAL_STORAGE_ROUND_ROBIN_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_INTERNAL_STORAGE_ROUND_ROBIN_H

#include "google/cloud/storage/internal/storage_stub.h"
#include "google/cloud/storage/version.h"
#include "google/cloud/completion_queue.h"
#include <grpcpp/grpcpp.h>
#include <memory>
#include <mutex>
#include <vector>

namespace google {
namespace cloud {
namespace storage_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class StorageRoundRobin
    : public StorageStub,
      public std::enable_shared_from_this<StorageRoundRobin> {
 public:
  explicit StorageRoundRobin(std::vector<std::shared_ptr<StorageStub>> children)
      : children_(std::move(children)) {}
  ~StorageRoundRobin() override = default;

  void StartRefreshLoop(google::cloud::CompletionQueue cq,
                        std::vector<std::shared_ptr<grpc::Channel>> channels);

  Status DeleteBucket(
      grpc::ClientContext& context,
      google::storage::v2::DeleteBucketRequest const& request) override;

  StatusOr<google::storage::v2::Bucket> GetBucket(
      grpc::ClientContext& context,
      google::storage::v2::GetBucketRequest const& request) override;

  StatusOr<google::storage::v2::Bucket> CreateBucket(
      grpc::ClientContext& context,
      google::storage::v2::CreateBucketRequest const& request) override;

  StatusOr<google::storage::v2::ListBucketsResponse> ListBuckets(
      grpc::ClientContext& context,
      google::storage::v2::ListBucketsRequest const& request) override;

  StatusOr<google::storage::v2::Bucket> LockBucketRetentionPolicy(
      grpc::ClientContext& context,
      google::storage::v2::LockBucketRetentionPolicyRequest const& request)
      override;

  StatusOr<google::iam::v1::Policy> GetIamPolicy(
      grpc::ClientContext& context,
      google::iam::v1::GetIamPolicyRequest const& request) override;

  StatusOr<google::iam::v1::Policy> SetIamPolicy(
      grpc::ClientContext& context,
      google::iam::v1::SetIamPolicyRequest const& request) override;

  StatusOr<google::iam::v1::TestIamPermissionsResponse> TestIamPermissions(
      grpc::ClientContext& context,
      google::iam::v1::TestIamPermissionsRequest const& request) override;

  StatusOr<google::storage::v2::Bucket> UpdateBucket(
      grpc::ClientContext& context,
      google::storage::v2::UpdateBucketRequest const& request) override;

  Status DeleteNotificationConfig(
      grpc::ClientContext& context,
      google::storage::v2::DeleteNotificationConfigRequest const& request)
      override;

  StatusOr<google::storage::v2::NotificationConfig> GetNotificationConfig(
      grpc::ClientContext& context,
      google::storage::v2::GetNotificationConfigRequest const& request)
      override;

  StatusOr<google::storage::v2::NotificationConfig> CreateNotificationConfig(
      grpc::ClientContext& context,
      google::storage::v2::CreateNotificationConfigRequest const& request)
      override;

  StatusOr<google::storage::v2::ListNotificationConfigsResponse>
  ListNotificationConfigs(
      grpc::ClientContext& context,
      google::storage::v2::ListNotificationConfigsRequest const& request)
      override;

  StatusOr<google::storage::v2::Object> ComposeObject(
      grpc::ClientContext& context,
      google::storage::v2::ComposeObjectRequest const& request) override;

  Status DeleteObject(
      grpc::ClientContext& context,
      google::storage::v2::DeleteObjectRequest const& request) override;

  StatusOr<google::storage::v2::CancelResumableWriteResponse>
  CancelResumableWrite(
      grpc::ClientContext& context,
      google::storage::v2::CancelResumableWriteRequest const& request) override;

  StatusOr<google::storage::v2::Object> GetObject(
      grpc::ClientContext& context,
      google::storage::v2::GetObjectRequest const& request) override;

  std::unique_ptr<google::cloud::internal::StreamingReadRpc<
      google::storage::v2::ReadObjectResponse>>
  ReadObject(std::shared_ptr<grpc::ClientContext> context,
             google::storage::v2::ReadObjectRequest const& request) override;

  StatusOr<google::storage::v2::Object> UpdateObject(
      grpc::ClientContext& context,
      google::storage::v2::UpdateObjectRequest const& request) override;

  std::unique_ptr<google::cloud::internal::StreamingWriteRpc<
      google::storage::v2::WriteObjectRequest,
      google::storage::v2::WriteObjectResponse>>
  WriteObject(std::shared_ptr<grpc::ClientContext> context) override;

  StatusOr<google::storage::v2::ListObjectsResponse> ListObjects(
      grpc::ClientContext& context,
      google::storage::v2::ListObjectsRequest const& request) override;

  StatusOr<google::storage::v2::RewriteResponse> RewriteObject(
      grpc::ClientContext& context,
      google::storage::v2::RewriteObjectRequest const& request) override;

  StatusOr<google::storage::v2::StartResumableWriteResponse>
  StartResumableWrite(
      grpc::ClientContext& context,
      google::storage::v2::StartResumableWriteRequest const& request) override;
  StatusOr<google::storage::v2::QueryWriteStatusResponse> QueryWriteStatus(
      grpc::ClientContext& context,
      google::storage::v2::QueryWriteStatusRequest const& request) override;

  StatusOr<google::storage::v2::ServiceAccount> GetServiceAccount(
      grpc::ClientContext& context,
      google::storage::v2::GetServiceAccountRequest const& request) override;

  StatusOr<google::storage::v2::CreateHmacKeyResponse> CreateHmacKey(
      grpc::ClientContext& context,
      google::storage::v2::CreateHmacKeyRequest const& request) override;

  Status DeleteHmacKey(
      grpc::ClientContext& context,
      google::storage::v2::DeleteHmacKeyRequest const& request) override;

  StatusOr<google::storage::v2::HmacKeyMetadata> GetHmacKey(
      grpc::ClientContext& context,
      google::storage::v2::GetHmacKeyRequest const& request) override;

  StatusOr<google::storage::v2::ListHmacKeysResponse> ListHmacKeys(
      grpc::ClientContext& context,
      google::storage::v2::ListHmacKeysRequest const& request) override;

  StatusOr<google::storage::v2::HmacKeyMetadata> UpdateHmacKey(
      grpc::ClientContext& context,
      google::storage::v2::UpdateHmacKeyRequest const& request) override;

  future<Status> AsyncDeleteObject(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::storage::v2::DeleteObjectRequest const& request) override;

  std::unique_ptr<::google::cloud::internal::AsyncStreamingReadRpc<
      google::storage::v2::ReadObjectResponse>>
  AsyncReadObject(
      google::cloud::CompletionQueue const& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::storage::v2::ReadObjectRequest const& request) override;

  std::unique_ptr<::google::cloud::internal::AsyncStreamingWriteRpc<
      google::storage::v2::WriteObjectRequest,
      google::storage::v2::WriteObjectResponse>>
  AsyncWriteObject(google::cloud::CompletionQueue const& cq,
                   std::shared_ptr<grpc::ClientContext> context) override;

  future<StatusOr<google::storage::v2::StartResumableWriteResponse>>
  AsyncStartResumableWrite(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::storage::v2::StartResumableWriteRequest const& request) override;

  future<StatusOr<google::storage::v2::QueryWriteStatusResponse>>
  AsyncQueryWriteStatus(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::storage::v2::QueryWriteStatusRequest const& request) override;

 private:
  std::shared_ptr<StorageStub> Child();
  std::weak_ptr<StorageRoundRobin> WeakFromThis() { return shared_from_this(); }
  void Refresh(std::size_t index,
               std::weak_ptr<google::cloud::internal::CompletionQueueImpl> wcq);
  void OnRefresh(
      std::size_t index,
      std::weak_ptr<google::cloud::internal::CompletionQueueImpl> wcq, bool ok);

  std::vector<std::shared_ptr<StorageStub>> const children_;
  std::mutex mu_;
  std::size_t current_ = 0;
  std::vector<std::shared_ptr<grpc::Channel>> channels_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_INTERNAL_STORAGE_ROUND_ROBIN_H
