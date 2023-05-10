set(test_files
    "TestAddition.cpp"
)

add_executable(ALIB_tests ${test_files})
target_include_directories(ALIB_tests PRIVATE "../src")