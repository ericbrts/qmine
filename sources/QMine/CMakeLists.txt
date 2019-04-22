set(project_name QMine)

add_executable(${project_name} main.cpp)

use_qt(${project_name})

target_link_libraries(${project_name} MathUtils)

set(includes ${CMAKE_CURRENT_LIST_DIR} "${CMAKE_CURRENT_LIST_DIR}/..")
target_include_directories(${project_name} PUBLIC ${includes} )
