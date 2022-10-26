# define project
cmake_minimum_required(VERSION 3.20.0)
project(MyProject CXX)

# add executable
add_executable(MyTarget main.cpp)

#include cmake modules
include(ExternalProject)

# get package: json cpp
ExternalProject_Add(external_jsoncpp
  GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
  GIT_TAG 1.9.5
  UPDATE_COMMAND ""
  DOWNLOAD_DIR "${CMAKE_SOURCE_DIR}/extern-download/jsoncpp"
  PREFIX "${CMAKE_BINARY_DIR}/extern/jsoncpp"
  INSTALL_DIR "${CMAKE_BINARY_DIR}/install/jsoncpp"
  CMAKE_ARGS
    -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
    -DJSONCPP_WITH_TESTS=OFF
    -DBUILD_SHARED_LIBS=OFF
    -DBUILD_STATIC_LIBS=ON
)

# get cached data
ExternalProject_Get_Property(external_jsoncpp INSTALL_DIR)

# link package: json cpp

# following does generate unresolver references
# >> can be resolved with "ExternalProject_Add ... BUILD_BYPRODUCTS" ?
#target_link_libraries(MyTarget INTERFACE external_jsoncpp) 

target_link_libraries(MyTarget "${CMAKE_BINARY_DIR}/${INSTALL_DIR}/lib/jsoncpp.lib")

# include package: json cpp
include_directories("${INSTALL_DIR}/include")