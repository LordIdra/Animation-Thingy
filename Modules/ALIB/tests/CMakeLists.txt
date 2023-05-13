add_executable(TestALIB ${test_files})
target_include_directories(TestALIB PRIVATE "../src")

find_package(Catch2 REQUIRED)
target_link_libraries(TestALIB ALIB Catch2::Catch2WithMain)