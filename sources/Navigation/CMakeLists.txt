set(project_name Navigation)

find_package(Qt5 COMPONENTS Core) # Fixes an issue with CMake 3.13
add_library(${project_name} STATIC NavPresenter.cpp NavPresenter.h)
use_qt(${project_name})

set(includes ${CMAKE_CURRENT_LIST_DIR} "${CMAKE_CURRENT_LIST_DIR}/..")
target_include_directories(${project_name} PUBLIC ${includes})
