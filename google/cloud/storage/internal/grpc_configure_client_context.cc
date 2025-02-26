// Copyright 2022 Google LLC
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

#include "google/cloud/storage/internal/grpc_configure_client_context.h"
#include <regex>

namespace google {
namespace cloud {
namespace storage_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

void ApplyRoutingHeaders(
    grpc::ClientContext& context,
    storage::internal::InsertObjectMediaRequest const& request) {
  context.AddMetadata("x-goog-request-params",
                      "bucket=projects/_/buckets/" + request.bucket_name());
}

void ApplyRoutingHeaders(grpc::ClientContext& context,
                         storage::internal::UploadChunkRequest const& request) {
  static auto* slash_format =
      new std::regex{"(projects/[^/]+/buckets/[^/]+)/.*", std::regex::optimize};
  static auto* colon_format =
      new std::regex{"(projects/[^/]+/buckets/[^:]+):.*", std::regex::optimize};
  for (auto const* re : {slash_format, colon_format}) {
    std::smatch match;
    if (!std::regex_match(request.upload_session_url(), match, *re)) continue;
    context.AddMetadata("x-goog-request-params", "bucket=" + match[1].str());
  }
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage_internal
}  // namespace cloud
}  // namespace google
