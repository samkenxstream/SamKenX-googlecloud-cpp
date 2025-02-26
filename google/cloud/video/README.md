# Video Services C++ Client Library

This directory contains an idiomatic C++ client library for video services,
including:

- [Live Stream API][livestream-service-docs], a service to transcode live, linear video streams into a variety of formats.
- [Transcoder API][transcoder-service-docs], a service to convert video files
  into formats suitable for consumer distribution.
- [Video Stitcher API][stitcher-service-docs], a service to generate dynamic
  content for delivery to client devices. Call the Video Stitcher API from your
  servers to dynamically insert ads into video-on-demand and live streams for
  your users.

While this library is **GA**, please note that the Google Cloud C++
client libraries do **not** follow [Semantic Versioning](https://semver.org/).

## Quickstart

The [quickstart/](quickstart/README.md) directory contains a minimal environment
to get started using this client library in a larger project. The following
"Hello World" program is used in this quickstart, and should give you a taste of
this library.

For detailed instructions on how to build and install this library, see the
top-level [README](/README.md#building-and-installing).

<!-- inject-quickstart-start -->

```cc
#include "google/cloud/video/transcoder/v1/transcoder_client.h"
#include <iostream>

int main(int argc, char* argv[]) try {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " project-id location-id\n";
    return 1;
  }

  namespace transcoder = ::google::cloud::video_transcoder_v1;
  auto client = transcoder::TranscoderServiceClient(
      transcoder::MakeTranscoderServiceConnection());

  auto const parent =
      std::string{"projects/"} + argv[1] + "/locations/" + argv[2];
  for (auto r : client.ListJobs(parent)) {
    if (!r) throw std::move(r).status();
    std::cout << r->DebugString() << "\n";
  }

  return 0;
} catch (google::cloud::Status const& status) {
  std::cerr << "google::cloud::Status thrown: " << status << "\n";
  return 1;
}
```

<!-- inject-quickstart-end -->

## More Information

- Official documentation about the [Live Stream API][livestream-service-docs] service
- Official documentation about the [Transcoder API][transcoder-service-docs] service
- Official documentation about the [Video Stitcher API][stitcher-service-docs] service
- [Reference doxygen documentation][doxygen-link] for each release of this
  client library
- Detailed header comments in our [public `.h`][source-link] files

[doxygen-link]: https://googleapis.dev/cpp/google-cloud-video/latest/
[livestream-service-docs]: https://cloud.google.com/livestream
[source-link]: https://github.com/googleapis/google-cloud-cpp/tree/main/google/cloud/video
[stitcher-service-docs]: https://cloud.google.com/video-stitcher
[transcoder-service-docs]: https://cloud.google.com/transcoder
