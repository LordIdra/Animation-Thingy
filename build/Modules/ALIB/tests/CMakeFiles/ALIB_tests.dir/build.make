# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/idra/GitHub/Animation-Thingy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/idra/GitHub/Animation-Thingy/build

# Include any dependencies generated for this target.
include Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/depend.make

# Include the progress variables for this target.
include Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/progress.make

# Include the compile flags for this target's objects.
include Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/flags.make

Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/TestAddition.cpp.o: Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/flags.make
Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/TestAddition.cpp.o: ../Modules/ALIB/tests/TestAddition.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/idra/GitHub/Animation-Thingy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/TestAddition.cpp.o"
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ALIB/tests && $(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-checks=bugprone-*,clang-analyzer-*,concurrency-*,cppcoreguidelines-*,misc-*,modernize-*,performance-*,portability-*,readability-*,-misc-unused-using-decls,-cppcoreguidelines-pro-type-union-access,-readability-implicit-bool-conversion,-readability-magic-numbers,-bugprone-narrowing-conversions,-modernize-pass-by-value,-cppcoreguidelines-avoid-magic-numbers,-performance-inefficient-string-concatenation" --source=/home/idra/GitHub/Animation-Thingy/Modules/ALIB/tests/TestAddition.cpp -- /usr/bin/clang++-15  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ALIB_tests.dir/TestAddition.cpp.o -c /home/idra/GitHub/Animation-Thingy/Modules/ALIB/tests/TestAddition.cpp

Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/TestAddition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ALIB_tests.dir/TestAddition.cpp.i"
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ALIB/tests && /usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/idra/GitHub/Animation-Thingy/Modules/ALIB/tests/TestAddition.cpp > CMakeFiles/ALIB_tests.dir/TestAddition.cpp.i

Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/TestAddition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ALIB_tests.dir/TestAddition.cpp.s"
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ALIB/tests && /usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/idra/GitHub/Animation-Thingy/Modules/ALIB/tests/TestAddition.cpp -o CMakeFiles/ALIB_tests.dir/TestAddition.cpp.s

# Object files for target ALIB_tests
ALIB_tests_OBJECTS = \
"CMakeFiles/ALIB_tests.dir/TestAddition.cpp.o"

# External object files for target ALIB_tests
ALIB_tests_EXTERNAL_OBJECTS =

Modules/ALIB/tests/ALIB_tests: Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/TestAddition.cpp.o
Modules/ALIB/tests/ALIB_tests: Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/build.make
Modules/ALIB/tests/ALIB_tests: /home/idra/.conan2/p/catche826dfbf478db/p/lib/libCatch2Main.a
Modules/ALIB/tests/ALIB_tests: /home/idra/.conan2/p/catche826dfbf478db/p/lib/libCatch2.a
Modules/ALIB/tests/ALIB_tests: Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/idra/GitHub/Animation-Thingy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ALIB_tests"
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ALIB/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ALIB_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/build: Modules/ALIB/tests/ALIB_tests

.PHONY : Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/build

Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/clean:
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ALIB/tests && $(CMAKE_COMMAND) -P CMakeFiles/ALIB_tests.dir/cmake_clean.cmake
.PHONY : Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/clean

Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/depend:
	cd /home/idra/GitHub/Animation-Thingy/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/idra/GitHub/Animation-Thingy /home/idra/GitHub/Animation-Thingy/Modules/ALIB/tests /home/idra/GitHub/Animation-Thingy/build /home/idra/GitHub/Animation-Thingy/build/Modules/ALIB/tests /home/idra/GitHub/Animation-Thingy/build/Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Modules/ALIB/tests/CMakeFiles/ALIB_tests.dir/depend

