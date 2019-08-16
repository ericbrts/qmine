macro (set_runtime_output_directory runtime_folder)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${runtime_folder})
  foreach( configuration ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${configuration} upperconf )
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${upperconf} ${runtime_folder})
  endforeach()
endmacro()

macro(group_source_files source_file_list)
  foreach(source_file_path ${source_file_list})
    get_filename_component(source_file_absolute_path ${source_file_path} ABSOLUTE)
    get_filename_component(source_file_absolute_dir ${source_file_absolute_path} DIRECTORY)
    file(RELATIVE_PATH source_file_relative_dir ${CMAKE_CURRENT_LIST_DIR} ${source_file_absolute_dir})

    if(source_file_relative_dir)
      string(REPLACE "/" "\\" source_filter_in_project ${source_file_relative_dir})
    else()
      set(source_filter_in_project " ")
    endif()

    source_group(${source_filter_in_project} FILES ${source_file_absolute_path})
  endforeach()
endmacro()

function(add_subdirectories_with_cmakelists root_path)
  file(GLOB_RECURSE all_cmakelists ${root_path}/*CMakeLists.txt)
  foreach(cmakelists ${all_cmakelists})
    get_filename_component(cmakelists_dir ${cmakelists} DIRECTORY)
    add_subdirectory(${cmakelists_dir})
  endforeach()
endfunction()

function(use_qt project_name)
  set(qt_root C:/Qt/5.12.0/msvc2015_64 CACHE STRING "Qt root")
  set(qt_modules_to_import Core Gui Qml Quick QuickWidgets Network OpenGL Multimedia)

  find_package(Qt5 PATHS ${qt_root} COMPONENTS ${qt_modules_to_import} REQUIRED)
  foreach(module ${qt_modules_to_import})
    list(APPEND qt_link Qt5::${module})
  endforeach()
  target_link_libraries(${project_name} ${qt_link})

  set(qt_defines $<$<CONFIG:Debug>:QT_QML_DEBUG>)

  list(APPEND bin_dep_dirs ${qt_root}/bin/)

  # Instruct CMake to run moc automatically when needed
  set_property(TARGET ${project_name} PROPERTY AUTOMOC TRUE)
  set_property(TARGET ${project_name} PROPERTY AUTORCC TRUE)

  list(APPEND includes ${CMAKE_CURRENT_BINARY_DIR}) #for generated MOC files
endfunction()
