set(project_name QMine)

find_package(Qt5 COMPONENTS Core) # Fixes an issue with CMake 3.13
add_executable(${project_name} main.cpp NavPresenter.cpp NavPresenter.h ../QML/Mine.qrc)

use_qt(${project_name})

target_link_libraries(${project_name} MathUtils)

set(includes ${CMAKE_CURRENT_LIST_DIR} "${CMAKE_CURRENT_LIST_DIR}/..")
target_include_directories(${project_name} PUBLIC ${includes} )
