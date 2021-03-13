cmake_minimum_required(VERSION 3.17)
project(
    SimplePlatformer
    VERSION 1.0
    LANGUAGES CXX)

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

add_subdirectory(src)