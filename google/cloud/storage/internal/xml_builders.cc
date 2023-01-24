// Copyright 2023 Google LLC
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

#include "google/cloud/storage/internal/xml_builders.h"
#include "google/cloud/storage/internal/xml_escape.h"

namespace google {
namespace cloud {
namespace storage_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<XmlNode> CompleteMultipartUpload(
    std::map<std::size_t, std::string> const& parts) {
  auto root = XmlNode::CreateRoot();
  auto target_node = root->AppendTagNode("CompleteMultipartUpload");
  for (auto const& p : parts) {
    auto part_tag = target_node->AppendTagNode("Part");
    part_tag->AppendTagNode("PartNumber")
        ->AppendTextNode(std::to_string(p.first));
    part_tag->AppendTagNode("ETag")->AppendTextNode(EscapeXmlContent(p.second));
  }
  return root;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage_internal
}  // namespace cloud
}  // namespace google
