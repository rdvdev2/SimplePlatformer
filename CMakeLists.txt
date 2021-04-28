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
FetchContent_GetProperties(mINI)
if(NOT $mini_POPULATED)
    FetchContent_Populate(mINI)

    add_library(mINI INTERFACE)
    target_include_directories(mINI INTERFACE ${mini_SOURCE_DIR}/src)
    target_compile_definitions(mINI INTERFACE MINI_CASE_SENSITIVE)
    add_library(pulzed::mINI ALIAS mINI)
endif()

# Get the Box2D physics engine
FetchContent_Declare(
        Box2D
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v2.4.1
)
FetchContent_GetProperties(Box2D)
if(NOT $box2d_POPULATED)
    FetchContent_Populate(Box2D)

    option(BOX2D_BUILD_UNIT_TESTS "Build the Box2D unit tests" OFF)
    option(BOX2D_BUILD_TESTBED "Build the Box2D testbed" OFF)
    option(BOX2D_BUILD_DOCS "Build the Box2D documentation" OFF)
    option(BOX2D_USER_SETTINGS "Override Box2D settings with b2UserSettings.h" OFF)

    add_subdirectory(${box2d_SOURCE_DIR} ${box2d_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_subdirectory(src)

message(CHECK_START "Checking CXX compiler compatibility")
if(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU AND ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 9.0)
    message(CHECK_FAIL "Found ${CMAKE_CXX_COMPILER_ID} @ ${CMAKE_CXX_COMPILER_VERSION}")
    message(SEND_ERROR "This build is known to fail under this compiler (GCC < 9.0)")
else()
    message(CHECK_PASS "Found ${CMAKE_CXX_COMPILER_ID} @ ${CMAKE_CXX_COMPILER_VERSION}")
endif ()