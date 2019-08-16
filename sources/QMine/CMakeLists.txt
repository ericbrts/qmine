set(project_name QMine)
set(sources
  main.cpp
  ../QML/Mine.qrc)

find_package(Qt5 COMPONENTS Core) # Fixes an issue with CMake 3.13
add_executable(${project_name} ${sources})
group_source_files("${sources}")

use_qt(${project_name})

target_link_libraries(${project_name} MathUtils Navigation)

set(includes ${CMAKE_CURRENT_LIST_DIR} "${CMAKE_CURRENT_LIST_DIR}/..")
target_include_directories(${project_name} PUBLIC ${includes})
