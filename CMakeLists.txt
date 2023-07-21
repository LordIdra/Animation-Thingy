cmake_minimum_required(VERSION 3.16)
project(AnimationThingy)

find_program(CCACHE ccache)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=bugprone-*,clang-analyzer-*,concurrency-*,cppcoreguidelines-*,misc-*,modernize-*,performance-*,portability-*,readability-*,-misc-unused-using-decls,-cppcoreguidelines-pro-type-union-access,-readability-implicit-bool-conversion,-readability-magic-numbers,-bugprone-narrowing-conversions,-modernize-pass-by-value,-cppcoreguidelines-avoid-magic-numbers,-performance-inefficient-string-concatenation)

add_subdirectory(Modules/AnimationLibrary)
add_subdirectory(Modules/ComponentCompiler)
add_subdirectory(Modules/ProgramCompiler)
add_subdirectory(Modules/Main)
