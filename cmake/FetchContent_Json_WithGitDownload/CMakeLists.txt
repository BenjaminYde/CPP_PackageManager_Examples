# define project
cmake_minimum_required(VERSION 3.20.0)
project(MyProject CXX)

# add executable
add_executable(MyTarget main.cpp)

#include cmake modules
include(FetchContent)

# package - declare: json cpp
FetchContent_Declare(external_jsoncpp
  GIT_REPOSITORY    https://github.com/open-source-parsers/jsoncpp.git
  GIT_TAG 1.9.5
)

set(JSONCPP_WITH_TESTS OFF)
set(BUILD_SHARED_LIBS OFF)
set(DBUILD_STATIC_LIBS ON)

# package - make available: json cpp
FetchContent_MakeAvailable(external_jsoncpp)

# package - link libraries
target_link_libraries(MyTarget PRIVATE jsoncpp_static)

#target_include_directories(MyTarget INTERFACE "${CMAKE_BINARY_DIR}/_deps/external_jsoncpp-src/include")