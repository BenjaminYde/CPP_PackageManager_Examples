# configure cmake
cmake_minimum_required(VERSION 3.23)

# setup package manager: vcpkg
include(FetchContent)
FetchContent_Declare(vcpkg
    GIT_REPOSITORY https://github.com/microsoft/vcpkg/
    GIT_TAG 2022.10.19
)
FetchContent_MakeAvailable(vcpkg)

# NOTE: This must be defined before the first project call
set(CMAKE_TOOLCHAIN_FILE "${vcpkg_SOURCE_DIR}/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "")
set(ENV{VCPKG_FEATURE_FLAGS} "versions")

# configure project
set(CMAKE_CXX_STANDARD 20)
project(myApp LANGUAGES "CXX")
add_executable(myApp main.cpp)

# find packages
find_package(jsoncpp REQUIRED)

# link packages
target_link_libraries(myApp
        PRIVATE
        JsonCpp::JsonCpp)
