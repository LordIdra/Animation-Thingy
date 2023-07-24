list(TRANSFORM source_files PREPEND ../src/)
add_executable(TestComponentCompiler ${test_files} ${source_files})
target_include_directories(TestComponentCompiler PRIVATE ../src ../../AnimationLibrary/src)

find_package(Catch2 REQUIRED)
target_link_libraries(TestComponentCompiler AnimationLibrary Catch2::Catch2WithMain)