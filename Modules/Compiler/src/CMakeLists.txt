add_library(ComponentCompiler ${source_files} ${main_file})
target_compile_options(ComponentCompiler PRIVATE -O0 -g)
target_include_directories(ComponentCompiler PRIVATE .)