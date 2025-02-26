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
// source: google/cloud/notebooks/v1/managed_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NOTEBOOKS_V1_MANAGED_NOTEBOOK_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NOTEBOOKS_V1_MANAGED_NOTEBOOK_CONNECTION_H

#include "google/cloud/notebooks/v1/internal/managed_notebook_retry_traits.h"
#include "google/cloud/notebooks/v1/managed_notebook_connection_idempotency_policy.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/cloud/notebooks/v1/managed_service.pb.h>
#include <google/cloud/notebooks/v1/service.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace notebooks_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ManagedNotebookServiceRetryPolicy =
    ::google::cloud::internal::TraitBasedRetryPolicy<
        notebooks_v1_internal::ManagedNotebookServiceRetryTraits>;

using ManagedNotebookServiceLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        notebooks_v1_internal::ManagedNotebookServiceRetryTraits>;

using ManagedNotebookServiceLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        notebooks_v1_internal::ManagedNotebookServiceRetryTraits>;

/**
 * The `ManagedNotebookServiceConnection` object for
 * `ManagedNotebookServiceClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `ManagedNotebookServiceClient`. This allows users to inject custom
 * behavior (e.g., with a Google Mock object) when writing tests that use
 * objects of type `ManagedNotebookServiceClient`.
 *
 * To create a concrete instance, see `MakeManagedNotebookServiceConnection()`.
 *
 * For mocking, see `notebooks_v1_mocks::MockManagedNotebookServiceConnection`.
 */
class ManagedNotebookServiceConnection {
 public:
  virtual ~ManagedNotebookServiceConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StreamRange<google::cloud::notebooks::v1::Runtime> ListRuntimes(
      google::cloud::notebooks::v1::ListRuntimesRequest request);

  virtual StatusOr<google::cloud::notebooks::v1::Runtime> GetRuntime(
      google::cloud::notebooks::v1::GetRuntimeRequest const& request);

  virtual future<StatusOr<google::cloud::notebooks::v1::Runtime>> CreateRuntime(
      google::cloud::notebooks::v1::CreateRuntimeRequest const& request);

  virtual future<StatusOr<google::cloud::notebooks::v1::Runtime>> UpdateRuntime(
      google::cloud::notebooks::v1::UpdateRuntimeRequest const& request);

  virtual future<StatusOr<google::cloud::notebooks::v1::OperationMetadata>>
  DeleteRuntime(
      google::cloud::notebooks::v1::DeleteRuntimeRequest const& request);

  virtual future<StatusOr<google::cloud::notebooks::v1::Runtime>> StartRuntime(
      google::cloud::notebooks::v1::StartRuntimeRequest const& request);

  virtual future<StatusOr<google::cloud::notebooks::v1::Runtime>> StopRuntime(
      google::cloud::notebooks::v1::StopRuntimeRequest const& request);

  virtual future<StatusOr<google::cloud::notebooks::v1::Runtime>> SwitchRuntime(
      google::cloud::notebooks::v1::SwitchRuntimeRequest const& request);

  virtual future<StatusOr<google::cloud::notebooks::v1::Runtime>> ResetRuntime(
      google::cloud::notebooks::v1::ResetRuntimeRequest const& request);

  virtual future<StatusOr<google::cloud::notebooks::v1::Runtime>>
  UpgradeRuntime(
      google::cloud::notebooks::v1::UpgradeRuntimeRequest const& request);

  virtual future<StatusOr<google::cloud::notebooks::v1::Runtime>>
  ReportRuntimeEvent(
      google::cloud::notebooks::v1::ReportRuntimeEventRequest const& request);

  virtual StatusOr<
      google::cloud::notebooks::v1::RefreshRuntimeTokenInternalResponse>
  RefreshRuntimeTokenInternal(
      google::cloud::notebooks::v1::RefreshRuntimeTokenInternalRequest const&
          request);

  virtual future<StatusOr<google::cloud::notebooks::v1::Runtime>>
  DiagnoseRuntime(
      google::cloud::notebooks::v1::DiagnoseRuntimeRequest const& request);
};

/**
 * A factory function to construct an object of type
 * `ManagedNotebookServiceConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of
 * ManagedNotebookServiceClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `ManagedNotebookServiceConnection`. Expected options are any of the
 * types in the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::notebooks_v1::ManagedNotebookServicePolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `ManagedNotebookServiceConnection`
 * created by this function.
 */
std::shared_ptr<ManagedNotebookServiceConnection>
MakeManagedNotebookServiceConnection(Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace notebooks_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NOTEBOOKS_V1_MANAGED_NOTEBOOK_CONNECTION_H
