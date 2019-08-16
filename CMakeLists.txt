cmake_minimum_required(VERSION 3.5)

include("cmake/functions.cmake")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)

project(QMine)

set_runtime_output_directory(${CMAKE_SOURCE_DIR}/install)

add_subdirectories_with_cmakelists(${PROJECT_SOURCE_DIR}/sources)
