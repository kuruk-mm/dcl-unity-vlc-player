cmake_minimum_required(VERSION 3.15.0)

# Define the Project Name and Description
project(dcl-unity-vlc-player)

# Set required C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Set the Relative Path Configurations
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
# Configure the visibility of symbols in targets
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
# Define installation folder and the module path (this one required by conan)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(LibVLC REQUIRED)

add_library(dcl-unity-vlc-player SHARED src/DCLVLCPlayerWrapper.cpp src/VLCPlayer.cpp)
add_executable(dcl-unity-vlc-player-test test/main.cpp)

target_include_directories(dcl-unity-vlc-player
    PUBLIC
    include
    ${LIBVLC_INCLUDE_DIR}
)
target_link_libraries(dcl-unity-vlc-player
    PUBLIC
    ${LIBVLC_LIBRARY} ${LIBVLCCORE_LIBRARY}
)

target_link_libraries(dcl-unity-vlc-player-test
    PUBLIC
    dcl-unity-vlc-player
)