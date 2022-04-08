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
// source: google/cloud/dialogflow/cx/v3/agent.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_AGENTS_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_AGENTS_CONNECTION_H

#include "google/cloud/dialogflow_cx/agents_connection_idempotency_policy.h"
#include "google/cloud/dialogflow_cx/internal/agents_retry_traits.h"
#include "google/cloud/dialogflow_cx/internal/agents_stub.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using AgentsRetryPolicy = ::google::cloud::internal::TraitBasedRetryPolicy<
    dialogflow_cx_internal::AgentsRetryTraits>;

using AgentsLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        dialogflow_cx_internal::AgentsRetryTraits>;

using AgentsLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        dialogflow_cx_internal::AgentsRetryTraits>;

class AgentsConnection {
 public:
  virtual ~AgentsConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StreamRange<google::cloud::dialogflow::cx::v3::Agent> ListAgents(
      google::cloud::dialogflow::cx::v3::ListAgentsRequest request);

  virtual StatusOr<google::cloud::dialogflow::cx::v3::Agent> GetAgent(
      google::cloud::dialogflow::cx::v3::GetAgentRequest const& request);

  virtual StatusOr<google::cloud::dialogflow::cx::v3::Agent> CreateAgent(
      google::cloud::dialogflow::cx::v3::CreateAgentRequest const& request);

  virtual StatusOr<google::cloud::dialogflow::cx::v3::Agent> UpdateAgent(
      google::cloud::dialogflow::cx::v3::UpdateAgentRequest const& request);

  virtual Status DeleteAgent(
      google::cloud::dialogflow::cx::v3::DeleteAgentRequest const& request);

  virtual future<
      StatusOr<google::cloud::dialogflow::cx::v3::ExportAgentResponse>>
  ExportAgent(
      google::cloud::dialogflow::cx::v3::ExportAgentRequest const& request);

  virtual future<StatusOr<google::protobuf::Struct>> RestoreAgent(
      google::cloud::dialogflow::cx::v3::RestoreAgentRequest const& request);

  virtual StatusOr<google::cloud::dialogflow::cx::v3::AgentValidationResult>
  ValidateAgent(
      google::cloud::dialogflow::cx::v3::ValidateAgentRequest const& request);

  virtual StatusOr<google::cloud::dialogflow::cx::v3::AgentValidationResult>
  GetAgentValidationResult(
      google::cloud::dialogflow::cx::v3::GetAgentValidationResultRequest const&
          request);
};

std::shared_ptr<AgentsConnection> MakeAgentsConnection(Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<dialogflow_cx::AgentsConnection> MakeAgentsConnection(
    std::shared_ptr<AgentsStub> stub, Options options);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_AGENTS_CONNECTION_H
