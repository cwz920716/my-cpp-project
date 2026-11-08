# Prefer an installed GoogleTest (e.g. libgtest-dev, vcpkg, conan);
# otherwise download it at configure time.
option(MYCPP_FETCH_GTEST "Always download GoogleTest instead of using an installed one" OFF)

if(NOT MYCPP_FETCH_GTEST)
  find_package(GTest 1.14 CONFIG QUIET)
endif()

if(GTest_FOUND)
  message(STATUS "Using installed GoogleTest ${GTest_VERSION}")
else()
  message(STATUS "Fetching GoogleTest via FetchContent")
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  )
  # Keep gtest from overriding the parent project's CRT settings on Windows
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
endif()

add_executable(mycpp_tests math_test.cpp)
target_link_libraries(mycpp_tests PRIVATE mycpp GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(mycpp_tests)
