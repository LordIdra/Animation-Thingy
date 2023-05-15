add_executable(TestAnimationLibrary ${test_files})
target_include_directories(TestAnimationLibrary PRIVATE "../src")

find_package(Catch2 REQUIRED)
target_link_libraries(TestAnimationLibrary AnimationLibrary Catch2::Catch2WithMain)