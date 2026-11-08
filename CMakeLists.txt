cmake_minimum_required(VERSION 3.20)
project(my_cpp_project VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

option(MYCPP_BUILD_TESTS "Build unit tests" ON)

# Library
add_library(mycpp src/math.cpp)
target_include_directories(mycpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(mycpp PUBLIC cxx_std_20)
if(MSVC)
  target_compile_options(mycpp PRIVATE /W4)
else()
  target_compile_options(mycpp PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Executable
add_executable(mycpp_app src/main.cpp)
target_link_libraries(mycpp_app PRIVATE mycpp)

# Tests
if(MYCPP_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
