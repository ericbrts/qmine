set(project_name Navigation)
set(sources
  NavFactory.cpp
  NavFactory.h
  NavPresenter.cpp
  NavPresenter.h
  Pages/APage.h
  Pages/HomePage.cpp
  Pages/HomePage.h
  Pages/MineGamePage.cpp
  Pages/MineGamePage.h
  Pages/SettingsPage.cpp
  Pages/SettingsPage.h)

find_package(Qt5 COMPONENTS Core) # Fixes an issue with CMake 3.13
add_library(${project_name} STATIC ${sources})
group_source_files("${sources}")
use_qt(${project_name})

set(includes ${CMAKE_CURRENT_LIST_DIR} "${CMAKE_CURRENT_LIST_DIR}/..")
target_include_directories(${project_name} PUBLIC ${includes})
