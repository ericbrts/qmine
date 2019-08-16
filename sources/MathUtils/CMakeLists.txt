set(project_name MathUtils)
set(sources
  Matrix/Matrix2d.h
  MathUtils.cpp
  MathUtils.h)

add_library(${project_name} STATIC ${sources})
group_source_files("${sources}")

set(includes  ${CMAKE_CURRENT_LIST_DIR} "${CMAKE_CURRENT_LIST_DIR}/..")
target_include_directories(${project_name} PUBLIC ${includes} )
