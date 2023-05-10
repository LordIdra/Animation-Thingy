find_program(CCACHE ccache)

set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE})
set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=bugprone-*,clang-analyzer-*,concurrency-*,cppcoreguidelines-*,misc-*,modernize-*,performance-*,portability-*,readability-*,-misc-unused-using-decls,-cppcoreguidelines-pro-type-union-access,-readability-implicit-bool-conversion,-readability-magic-numbers,-bugprone-narrowing-conversions,-modernize-pass-by-value,-cppcoreguidelines-avoid-magic-numbers,-performance-inefficient-string-concatenation)

set(source_files
    Main.cpp
)

set(test_files

)

add_executable(ACPC ${source_files} ${test_files})
target_include_directories(ACPC PRIVATE .)