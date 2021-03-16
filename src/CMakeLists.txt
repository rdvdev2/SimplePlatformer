
# Find all C/C++ source files
file(GLOB_RECURSE SOURCE_FILES *.c *.cpp *.h *.hpp)

# Add an executable
add_executable(SimplePlatformer ${SOURCE_FILES})
target_compile_features(SimplePlatformer PUBLIC cxx_std_20) # Compile with C++20
target_link_libraries(SimplePlatformer PRIVATE sfml-graphics sfml-window sfml-system) # Compile against SFML

# Installation steps
if(WIN32)
    install(TARGETS SimplePlatformer
            RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})
else()
    install(TARGETS SimplePlatformer
            RUNTIME)
endif()