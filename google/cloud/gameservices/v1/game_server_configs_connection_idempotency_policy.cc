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
// source: google/cloud/gaming/v1/game_server_configs_service.proto

#include "google/cloud/gameservices/v1/game_server_configs_connection_idempotency_policy.h"
#include <memory>

namespace google {
namespace cloud {
namespace gameservices_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

GameServerConfigsServiceConnectionIdempotencyPolicy::
    ~GameServerConfigsServiceConnectionIdempotencyPolicy() = default;

std::unique_ptr<GameServerConfigsServiceConnectionIdempotencyPolicy>
GameServerConfigsServiceConnectionIdempotencyPolicy::clone() const {
  return std::make_unique<GameServerConfigsServiceConnectionIdempotencyPolicy>(
      *this);
}

Idempotency
GameServerConfigsServiceConnectionIdempotencyPolicy::ListGameServerConfigs(
    google::cloud::gaming::v1::ListGameServerConfigsRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

Idempotency
GameServerConfigsServiceConnectionIdempotencyPolicy::GetGameServerConfig(
    google::cloud::gaming::v1::GetGameServerConfigRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency
GameServerConfigsServiceConnectionIdempotencyPolicy::CreateGameServerConfig(
    google::cloud::gaming::v1::CreateGameServerConfigRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency
GameServerConfigsServiceConnectionIdempotencyPolicy::DeleteGameServerConfig(
    google::cloud::gaming::v1::DeleteGameServerConfigRequest const&) {
  return Idempotency::kNonIdempotent;
}

std::unique_ptr<GameServerConfigsServiceConnectionIdempotencyPolicy>
MakeDefaultGameServerConfigsServiceConnectionIdempotencyPolicy() {
  return std::make_unique<
      GameServerConfigsServiceConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace gameservices_v1
}  // namespace cloud
}  // namespace google
