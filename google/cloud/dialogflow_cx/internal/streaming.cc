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

#include "google/cloud/dialogflow_cx/internal/sessions_connection_impl.h"

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::cloud::dialogflow::cx::v3::StreamingDetectIntentRequest,
    google::cloud::dialogflow::cx::v3::StreamingDetectIntentResponse>>
SessionsConnectionImpl::AsyncStreamingDetectIntent(ExperimentalTag) {
  return stub_->AsyncStreamingDetectIntent(
      background_->cq(), absl::make_unique<grpc::ClientContext>());
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google
