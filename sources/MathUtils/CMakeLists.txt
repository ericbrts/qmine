set(project_name MathUtils)

add_library(${project_name} STATIC Matrix/Matrix2d.h MathUtils.cpp MathUtils.h)

set(includes  ${CMAKE_CURRENT_LIST_DIR} "${CMAKE_CURRENT_LIST_DIR}/..")
target_include_directories(${project_name} PUBLIC ${includes} )
