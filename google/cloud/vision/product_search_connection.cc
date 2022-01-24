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
// source: google/cloud/vision/v1/product_search_service.proto

#include "google/cloud/vision/product_search_connection.h"
#include "google/cloud/vision/internal/product_search_connection_impl.h"
#include "google/cloud/vision/internal/product_search_option_defaults.h"
#include "google/cloud/vision/internal/product_search_stub_factory.h"
#include "google/cloud/vision/product_search_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace vision {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ProductSearchConnection::~ProductSearchConnection() = default;

StatusOr<google::cloud::vision::v1::ProductSet>
ProductSearchConnection::CreateProductSet(
    google::cloud::vision::v1::CreateProductSetRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::vision::v1::ProductSet>
ProductSearchConnection::ListProductSets(
    google::cloud::vision::v1::ListProductSetsRequest request) {
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::vision::v1::ProductSet>>(
      std::move(request),
      [](google::cloud::vision::v1::ListProductSetsRequest const&) {
        return StatusOr<google::cloud::vision::v1::ListProductSetsResponse>{};
      },
      [](google::cloud::vision::v1::ListProductSetsResponse const&) {
        return std::vector<google::cloud::vision::v1::ProductSet>();
      });
}

StatusOr<google::cloud::vision::v1::ProductSet>
ProductSearchConnection::GetProductSet(
    google::cloud::vision::v1::GetProductSetRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::vision::v1::ProductSet>
ProductSearchConnection::UpdateProductSet(
    google::cloud::vision::v1::UpdateProductSetRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status ProductSearchConnection::DeleteProductSet(
    google::cloud::vision::v1::DeleteProductSetRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::vision::v1::Product>
ProductSearchConnection::CreateProduct(
    google::cloud::vision::v1::CreateProductRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::vision::v1::Product>
ProductSearchConnection::ListProducts(
    google::cloud::vision::v1::ListProductsRequest request) {
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::vision::v1::Product>>(
      std::move(request),
      [](google::cloud::vision::v1::ListProductsRequest const&) {
        return StatusOr<google::cloud::vision::v1::ListProductsResponse>{};
      },
      [](google::cloud::vision::v1::ListProductsResponse const&) {
        return std::vector<google::cloud::vision::v1::Product>();
      });
}

StatusOr<google::cloud::vision::v1::Product>
ProductSearchConnection::GetProduct(
    google::cloud::vision::v1::GetProductRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::vision::v1::Product>
ProductSearchConnection::UpdateProduct(
    google::cloud::vision::v1::UpdateProductRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status ProductSearchConnection::DeleteProduct(
    google::cloud::vision::v1::DeleteProductRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::vision::v1::ReferenceImage>
ProductSearchConnection::CreateReferenceImage(
    google::cloud::vision::v1::CreateReferenceImageRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status ProductSearchConnection::DeleteReferenceImage(
    google::cloud::vision::v1::DeleteReferenceImageRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::vision::v1::ReferenceImage>
ProductSearchConnection::ListReferenceImages(
    google::cloud::vision::v1::ListReferenceImagesRequest request) {
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::vision::v1::ReferenceImage>>(
      std::move(request),
      [](google::cloud::vision::v1::ListReferenceImagesRequest const&) {
        return StatusOr<
            google::cloud::vision::v1::ListReferenceImagesResponse>{};
      },
      [](google::cloud::vision::v1::ListReferenceImagesResponse const&) {
        return std::vector<google::cloud::vision::v1::ReferenceImage>();
      });
}

StatusOr<google::cloud::vision::v1::ReferenceImage>
ProductSearchConnection::GetReferenceImage(
    google::cloud::vision::v1::GetReferenceImageRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status ProductSearchConnection::AddProductToProductSet(
    google::cloud::vision::v1::AddProductToProductSetRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status ProductSearchConnection::RemoveProductFromProductSet(
    google::cloud::vision::v1::RemoveProductFromProductSetRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::vision::v1::Product>
ProductSearchConnection::ListProductsInProductSet(
    google::cloud::vision::v1::ListProductsInProductSetRequest request) {
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::vision::v1::Product>>(
      std::move(request),
      [](google::cloud::vision::v1::ListProductsInProductSetRequest const&) {
        return StatusOr<
            google::cloud::vision::v1::ListProductsInProductSetResponse>{};
      },
      [](google::cloud::vision::v1::ListProductsInProductSetResponse const&) {
        return std::vector<google::cloud::vision::v1::Product>();
      });
}

future<StatusOr<google::cloud::vision::v1::ImportProductSetsResponse>>
ProductSearchConnection::ImportProductSets(
    google::cloud::vision::v1::ImportProductSetsRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::vision::v1::ImportProductSetsResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::vision::v1::BatchOperationMetadata>>
ProductSearchConnection::PurgeProducts(
    google::cloud::vision::v1::PurgeProductsRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::vision::v1::BatchOperationMetadata>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

std::shared_ptr<ProductSearchConnection> MakeProductSearchConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 ProductSearchPolicyOptionList>(options,
                                                                __func__);
  options = vision_internal::ProductSearchDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = vision_internal::CreateDefaultProductSearchStub(background->cq(),
                                                              options);
  return std::make_shared<vision_internal::ProductSearchConnectionImpl>(
      std::move(background), std::move(stub), options);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace vision
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace vision_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<vision::ProductSearchConnection> MakeProductSearchConnection(
    std::shared_ptr<ProductSearchStub> stub, Options options) {
  options = ProductSearchDefaultOptions(std::move(options));
  return std::make_shared<vision_internal::ProductSearchConnectionImpl>(
      internal::MakeBackgroundThreadsFactory(options)(), std::move(stub),
      std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace vision_internal
}  // namespace cloud
}  // namespace google
