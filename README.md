# my-cpp-project

A C++20 CMake project with GoogleTest unit tests.

## Layout

```
include/mycpp/   Public headers
src/             Library sources and the app entry point
tests/           GoogleTest unit tests
```

## Build and test

```sh
cmake -S . -B build
cmake --build build -j
ctest --test-dir build --output-on-failure
./build/mycpp_app
```

## GoogleTest

The test build uses an installed GoogleTest (>= 1.14) if CMake can find one,
e.g. `apt install libgtest-dev`. Otherwise it downloads GoogleTest v1.15.2 via
`FetchContent`. Pass `-DMYCPP_FETCH_GTEST=ON` to always download it, or
`-DMYCPP_BUILD_TESTS=OFF` to skip the tests.
