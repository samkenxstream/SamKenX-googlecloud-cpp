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
// source: google/cloud/dialogflow/cx/v3/transition_route_group.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_MOCKS_MOCK_TRANSITION_ROUTE_GROUPS_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_MOCKS_MOCK_TRANSITION_ROUTE_GROUPS_CONNECTION_H

#include "google/cloud/dialogflow_cx/transition_route_groups_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace dialogflow_cx_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class MockTransitionRouteGroupsConnection
    : public dialogflow_cx::TransitionRouteGroupsConnection {
 public:
  MOCK_METHOD(Options, options, (), (override));

  MOCK_METHOD(
      StreamRange<google::cloud::dialogflow::cx::v3::TransitionRouteGroup>,
      ListTransitionRouteGroups,
      (google::cloud::dialogflow::cx::v3::ListTransitionRouteGroupsRequest
           request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::cx::v3::TransitionRouteGroup>,
      GetTransitionRouteGroup,
      (google::cloud::dialogflow::cx::v3::GetTransitionRouteGroupRequest const&
           request),
      (override));

  MOCK_METHOD(StatusOr<google::cloud::dialogflow::cx::v3::TransitionRouteGroup>,
              CreateTransitionRouteGroup,
              (google::cloud::dialogflow::cx::v3::
                   CreateTransitionRouteGroupRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::cloud::dialogflow::cx::v3::TransitionRouteGroup>,
              UpdateTransitionRouteGroup,
              (google::cloud::dialogflow::cx::v3::
                   UpdateTransitionRouteGroupRequest const& request),
              (override));

  MOCK_METHOD(Status, DeleteTransitionRouteGroup,
              (google::cloud::dialogflow::cx::v3::
                   DeleteTransitionRouteGroupRequest const& request),
              (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_MOCKS_MOCK_TRANSITION_ROUTE_GROUPS_CONNECTION_H
