add_library(ComponentCompiler ${source_files} ${main_file})
target_include_directories(ComponentCompiler PRIVATE . ../../AnimationLibrary/src)
target_link_libraries(ComponentCompiler AnimationLibrary)