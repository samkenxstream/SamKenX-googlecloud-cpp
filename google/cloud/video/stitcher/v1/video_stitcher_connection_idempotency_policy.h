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
// source: google/cloud/video/stitcher/v1/video_stitcher_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_VIDEO_STITCHER_V1_VIDEO_STITCHER_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_VIDEO_STITCHER_V1_VIDEO_STITCHER_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/version.h"
#include <google/cloud/video/stitcher/v1/video_stitcher_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace video_stitcher_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class VideoStitcherServiceConnectionIdempotencyPolicy {
 public:
  virtual ~VideoStitcherServiceConnectionIdempotencyPolicy();

  /// Create a new copy of this object.
  virtual std::unique_ptr<VideoStitcherServiceConnectionIdempotencyPolicy>
  clone() const;

  virtual google::cloud::Idempotency CreateCdnKey(
      google::cloud::video::stitcher::v1::CreateCdnKeyRequest const& request);

  virtual google::cloud::Idempotency ListCdnKeys(
      google::cloud::video::stitcher::v1::ListCdnKeysRequest request);

  virtual google::cloud::Idempotency GetCdnKey(
      google::cloud::video::stitcher::v1::GetCdnKeyRequest const& request);

  virtual google::cloud::Idempotency DeleteCdnKey(
      google::cloud::video::stitcher::v1::DeleteCdnKeyRequest const& request);

  virtual google::cloud::Idempotency UpdateCdnKey(
      google::cloud::video::stitcher::v1::UpdateCdnKeyRequest const& request);

  virtual google::cloud::Idempotency CreateVodSession(
      google::cloud::video::stitcher::v1::CreateVodSessionRequest const&
          request);

  virtual google::cloud::Idempotency GetVodSession(
      google::cloud::video::stitcher::v1::GetVodSessionRequest const& request);

  virtual google::cloud::Idempotency ListVodStitchDetails(
      google::cloud::video::stitcher::v1::ListVodStitchDetailsRequest request);

  virtual google::cloud::Idempotency GetVodStitchDetail(
      google::cloud::video::stitcher::v1::GetVodStitchDetailRequest const&
          request);

  virtual google::cloud::Idempotency ListVodAdTagDetails(
      google::cloud::video::stitcher::v1::ListVodAdTagDetailsRequest request);

  virtual google::cloud::Idempotency GetVodAdTagDetail(
      google::cloud::video::stitcher::v1::GetVodAdTagDetailRequest const&
          request);

  virtual google::cloud::Idempotency ListLiveAdTagDetails(
      google::cloud::video::stitcher::v1::ListLiveAdTagDetailsRequest request);

  virtual google::cloud::Idempotency GetLiveAdTagDetail(
      google::cloud::video::stitcher::v1::GetLiveAdTagDetailRequest const&
          request);

  virtual google::cloud::Idempotency CreateSlate(
      google::cloud::video::stitcher::v1::CreateSlateRequest const& request);

  virtual google::cloud::Idempotency ListSlates(
      google::cloud::video::stitcher::v1::ListSlatesRequest request);

  virtual google::cloud::Idempotency GetSlate(
      google::cloud::video::stitcher::v1::GetSlateRequest const& request);

  virtual google::cloud::Idempotency UpdateSlate(
      google::cloud::video::stitcher::v1::UpdateSlateRequest const& request);

  virtual google::cloud::Idempotency DeleteSlate(
      google::cloud::video::stitcher::v1::DeleteSlateRequest const& request);

  virtual google::cloud::Idempotency CreateLiveSession(
      google::cloud::video::stitcher::v1::CreateLiveSessionRequest const&
          request);

  virtual google::cloud::Idempotency GetLiveSession(
      google::cloud::video::stitcher::v1::GetLiveSessionRequest const& request);

  virtual google::cloud::Idempotency CreateLiveConfig(
      google::cloud::video::stitcher::v1::CreateLiveConfigRequest const&
          request);

  virtual google::cloud::Idempotency ListLiveConfigs(
      google::cloud::video::stitcher::v1::ListLiveConfigsRequest request);

  virtual google::cloud::Idempotency GetLiveConfig(
      google::cloud::video::stitcher::v1::GetLiveConfigRequest const& request);

  virtual google::cloud::Idempotency DeleteLiveConfig(
      google::cloud::video::stitcher::v1::DeleteLiveConfigRequest const&
          request);
};

std::unique_ptr<VideoStitcherServiceConnectionIdempotencyPolicy>
MakeDefaultVideoStitcherServiceConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace video_stitcher_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_VIDEO_STITCHER_V1_VIDEO_STITCHER_CONNECTION_IDEMPOTENCY_POLICY_H
