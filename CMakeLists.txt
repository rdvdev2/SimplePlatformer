cmake_minimum_required(VERSION 3.17)
project(
    SimplePlatformer
    VERSION 1.0
    LANGUAGES CXX)

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

add_subdirectory(src)