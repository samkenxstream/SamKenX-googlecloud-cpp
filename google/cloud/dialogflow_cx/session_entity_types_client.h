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
// source: google/cloud/dialogflow/cx/v3/session_entity_type.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_SESSION_ENTITY_TYPES_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_SESSION_ENTITY_TYPES_CLIENT_H

#include "google/cloud/dialogflow_cx/session_entity_types_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Service for managing
/// [SessionEntityTypes][google.cloud.dialogflow.cx.v3.SessionEntityType].
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class SessionEntityTypesClient {
 public:
  explicit SessionEntityTypesClient(
      std::shared_ptr<SessionEntityTypesConnection> connection,
      Options opts = {});
  ~SessionEntityTypesClient();

  //@{
  // @name Copy and move support
  SessionEntityTypesClient(SessionEntityTypesClient const&) = default;
  SessionEntityTypesClient& operator=(SessionEntityTypesClient const&) =
      default;
  SessionEntityTypesClient(SessionEntityTypesClient&&) = default;
  SessionEntityTypesClient& operator=(SessionEntityTypesClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(SessionEntityTypesClient const& a,
                         SessionEntityTypesClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(SessionEntityTypesClient const& a,
                         SessionEntityTypesClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Returns the list of all session entity types in the specified session.
  ///
  /// @param parent  Required. The session to list all session entity types
  /// from.
  ///  Format:
  ///  @code
  ///  projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/sessions/<Session ID>
  ///  @endcode
  ///  or
  ///  @code
  ///  projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/environments/<Environment ID>/sessions/<Session ID>
  ///  @endcode
  ///  If `Environment ID` is not specified, we assume default 'draft'
  ///  environment.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::SessionEntityType,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  /// [google.cloud.dialogflow.cx.v3.ListSessionEntityTypesRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L163}
  /// [google.cloud.dialogflow.cx.v3.SessionEntityType]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  StreamRange<google::cloud::dialogflow::cx::v3::SessionEntityType>
  ListSessionEntityTypes(std::string const& parent, Options opts = {});

  ///
  /// Returns the list of all session entity types in the specified session.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ListSessionEntityTypesRequest,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L163}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::SessionEntityType,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  /// [google.cloud.dialogflow.cx.v3.ListSessionEntityTypesRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L163}
  /// [google.cloud.dialogflow.cx.v3.SessionEntityType]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  StreamRange<google::cloud::dialogflow::cx::v3::SessionEntityType>
  ListSessionEntityTypes(
      google::cloud::dialogflow::cx::v3::ListSessionEntityTypesRequest request,
      Options opts = {});

  ///
  /// Retrieves the specified session entity type.
  ///
  /// @param name  Required. The name of the session entity type.
  ///  Format:
  ///  @code
  ///  projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/sessions/<Session ID>/entityTypes/<Entity Type ID>
  ///  @endcode
  ///  or
  ///  @code
  ///  projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/environments/<Environment ID>/sessions/<Session
  ///  ID>/entityTypes/<Entity Type ID>
  ///  @endcode
  ///  If `Environment ID` is not specified, we assume the default 'draft'
  ///  environment.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::SessionEntityType,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  /// [google.cloud.dialogflow.cx.v3.GetSessionEntityTypeRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L197}
  /// [google.cloud.dialogflow.cx.v3.SessionEntityType]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::SessionEntityType>
  GetSessionEntityType(std::string const& name, Options opts = {});

  ///
  /// Retrieves the specified session entity type.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::GetSessionEntityTypeRequest,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L197}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::SessionEntityType,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  /// [google.cloud.dialogflow.cx.v3.GetSessionEntityTypeRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L197}
  /// [google.cloud.dialogflow.cx.v3.SessionEntityType]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::SessionEntityType>
  GetSessionEntityType(
      google::cloud::dialogflow::cx::v3::GetSessionEntityTypeRequest const&
          request,
      Options opts = {});

  ///
  /// Creates a session entity type.
  ///
  /// @param parent  Required. The session to create a session entity type for.
  ///  Format:
  ///  @code
  ///  projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/sessions/<Session ID>
  ///  @endcode
  ///  or
  ///  @code
  ///  projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/environments/<Environment ID>/sessions/<Session ID>
  ///  @endcode
  ///  If `Environment ID` is not specified, we assume default 'draft'
  ///  environment.
  /// @param session_entity_type  Required. The session entity type to create.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::SessionEntityType,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  /// [google.cloud.dialogflow.cx.v3.CreateSessionEntityTypeRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L214}
  /// [google.cloud.dialogflow.cx.v3.SessionEntityType]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::SessionEntityType>
  CreateSessionEntityType(
      std::string const& parent,
      google::cloud::dialogflow::cx::v3::SessionEntityType const&
          session_entity_type,
      Options opts = {});

  ///
  /// Creates a session entity type.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::CreateSessionEntityTypeRequest,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L214}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::SessionEntityType,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  /// [google.cloud.dialogflow.cx.v3.CreateSessionEntityTypeRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L214}
  /// [google.cloud.dialogflow.cx.v3.SessionEntityType]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::SessionEntityType>
  CreateSessionEntityType(
      google::cloud::dialogflow::cx::v3::CreateSessionEntityTypeRequest const&
          request,
      Options opts = {});

  ///
  /// Updates the specified session entity type.
  ///
  /// @param session_entity_type  Required. The session entity type to update.
  ///  Format:
  ///  @code
  ///  projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/sessions/<Session ID>/entityTypes/<Entity Type ID>
  ///  @endcode
  ///  or
  ///  @code
  ///  projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/environments/<Environment ID>/sessions/<Session
  ///  ID>/entityTypes/<Entity Type ID>
  ///  @endcode
  ///  If `Environment ID` is not specified, we assume the default 'draft'
  ///  environment.
  /// @param update_mask  The mask to control which fields get updated.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::SessionEntityType,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  /// [google.cloud.dialogflow.cx.v3.UpdateSessionEntityTypeRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L233}
  /// [google.cloud.dialogflow.cx.v3.SessionEntityType]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::SessionEntityType>
  UpdateSessionEntityType(
      google::cloud::dialogflow::cx::v3::SessionEntityType const&
          session_entity_type,
      google::protobuf::FieldMask const& update_mask, Options opts = {});

  ///
  /// Updates the specified session entity type.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::UpdateSessionEntityTypeRequest,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L233}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::SessionEntityType,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  /// [google.cloud.dialogflow.cx.v3.UpdateSessionEntityTypeRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L233}
  /// [google.cloud.dialogflow.cx.v3.SessionEntityType]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L116}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::SessionEntityType>
  UpdateSessionEntityType(
      google::cloud::dialogflow::cx::v3::UpdateSessionEntityTypeRequest const&
          request,
      Options opts = {});

  ///
  /// Deletes the specified session entity type.
  ///
  /// @param name  Required. The name of the session entity type to delete.
  ///  Format:
  ///  @code
  ///  projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/sessions/<Session ID>/entityTypes/<Entity Type ID>
  ///  @endcode
  ///  or
  ///  @code
  ///  projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/environments/<Environment ID>/sessions/<Session
  ///  ID>/entityTypes/<Entity Type ID>
  ///  @endcode
  ///  If `Environment ID` is not specified, we assume the default 'draft'
  ///  environment.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  ///
  /// [google.cloud.dialogflow.cx.v3.DeleteSessionEntityTypeRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L248}
  ///
  Status DeleteSessionEntityType(std::string const& name, Options opts = {});

  ///
  /// Deletes the specified session entity type.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::DeleteSessionEntityTypeRequest,google/cloud/dialogflow/cx/v3/session_entity_type.proto#L248}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  ///
  /// [google.cloud.dialogflow.cx.v3.DeleteSessionEntityTypeRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session_entity_type.proto#L248}
  ///
  Status DeleteSessionEntityType(
      google::cloud::dialogflow::cx::v3::DeleteSessionEntityTypeRequest const&
          request,
      Options opts = {});

 private:
  std::shared_ptr<SessionEntityTypesConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_SESSION_ENTITY_TYPES_CLIENT_H
