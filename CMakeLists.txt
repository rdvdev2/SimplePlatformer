cmake_minimum_required(VERSION 3.17)
project(
    SimplePlatformer
    VERSION 1.0
    LANGUAGES CXX)

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

include(GNUInstallDirs)

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

# Get the mINI library
include(FetchContent)
FetchContent_Declare(
        mINI
        GIT_REPOSITORY https://github.com/pulzed/mINI.git
        GIT_TAG 0.9.10
)
FetchContent_MakeAvailable(mINI)
add_library(mINI INTERFACE)
target_include_directories(mINI INTERFACE ${mini_SOURCE_DIR}/src)
target_compile_definitions(mINI INTERFACE MINI_CASE_SENSITIVE)
add_library(pulzed::mINI ALIAS mINI)

add_subdirectory(src)