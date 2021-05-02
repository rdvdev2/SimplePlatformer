
# Find all C/C++ source files
file(GLOB_RECURSE SOURCE_FILES *.c *.cpp *.h *.hpp)

# Configure the platform header
if(RUN_ON_BUILD_TREE)
    set(RESOURCES_PATH \"${CMAKE_CURRENT_BINARY_DIR}/resources\")
elseif(PORTABLE)
    set(RESOURCES_PATH \"./resources\")
else()
    set(RESOURCES_PATH \"${CMAKE_INSTALL_FULL_DATAROOTDIR}/resources\")
endif()
configure_file(platform.h.in platform.h @ONLY)

# Add an executable
add_executable(SimplePlatformer ${SOURCE_FILES})
target_include_directories(SimplePlatformer PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_compile_features(SimplePlatformer PUBLIC cxx_std_20) # Compile with C++20
target_link_libraries(SimplePlatformer PRIVATE sfml-graphics sfml-window sfml-system) # Compile against SFML
target_link_libraries(SimplePlatformer PRIVATE box2d) # Compile against Box2D
target_link_libraries(SimplePlatformer PRIVATE pulzed::mINI) # Include mINI header
set(CMAKE_EXE_LINKER_FLAGS " -static")
target_link_libraries(SimplePlatformer PRIVATE -static-libgcc -static-libstdc++) # Include C++ libs

# Installation steps
install(TARGETS SimplePlatformer RUNTIME)

# Copy all the resources
file(GLOB_RECURSE RESOURCE_FILES
        RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/resources ${CMAKE_CURRENT_SOURCE_DIR}/resources/*)
add_custom_target(copy_resource_files ALL
        COMMENT "Copying resource files")

foreach(RESOURCE_FILE ${RESOURCE_FILES})
    set(SRC "${CMAKE_CURRENT_SOURCE_DIR}/resources/${RESOURCE_FILE}")
    set(DST "${CMAKE_CURRENT_BINARY_DIR}/resources/${RESOURCE_FILE}")

    add_custom_command(
            TARGET copy_resource_files
            COMMAND ${CMAKE_COMMAND} -E copy ${SRC} ${DST}
            COMMENT "Copying resource file: ${RESOURCE_FILE}"
            DEPENDS ${SRC})
endforeach()

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/resources
        TYPE DATA)

# Delete resource folder on build tree on configure (deals with removed resources)
file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/resources)