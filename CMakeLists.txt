cmake_minimum_required(VERSION 3.16)
project(AnimationThingy)

find_program(CCACHE ccache)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=bugprone-*,clang-analyzer-*,concurrency-*,cppcoreguidelines-*,misc-*,modernize-*,performance-*,portability-*,readability-*,-misc-unused-using-decls,-cppcoreguidelines-pro-type-union-access,-readability-implicit-bool-conversion,-readability-magic-numbers,-bugprone-narrowing-conversions,-modernize-pass-by-value,-cppcoreguidelines-avoid-magic-numbers,-performance-inefficient-string-concatenation)

add_subdirectory(Modules/Compiler)