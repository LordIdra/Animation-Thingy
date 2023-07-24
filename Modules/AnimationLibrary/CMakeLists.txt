set(source_files
    errors/Errors.cpp
    readfile/ReadFile.cpp
)

set(test_files
    TestRead.cpp
)

add_subdirectory(src)
add_subdirectory(tests)
