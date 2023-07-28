list(TRANSFORM source_files PREPEND ../src/)
add_executable(TestComponentCompiler ${test_files} ${source_files})
target_compile_options(TestComponentCompiler PRIVATE -O0 -g)
target_include_directories(TestComponentCompiler PRIVATE ../src)

find_package(Catch2 REQUIRED)
target_link_libraries(TestComponentCompiler Catch2::Catch2WithMain)