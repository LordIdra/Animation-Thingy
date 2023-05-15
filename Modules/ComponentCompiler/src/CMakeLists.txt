add_executable(ComponentCompiler ${source_files} ${main_file})
target_include_directories(ComponentCompiler PRIVATE .)
target_link_libraries(ComponentCompiler AnimationLibrary)