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
include Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/depend.make

# Include the progress variables for this target.
include Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/progress.make

# Include the compile flags for this target's objects.
include Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/flags.make

Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/Subtraction.cpp.o: Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/flags.make
Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/Subtraction.cpp.o: ../Modules/ComponentCompiler/src/Subtraction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/idra/GitHub/Animation-Thingy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/Subtraction.cpp.o"
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ComponentCompiler/src && $(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-checks=bugprone-*,clang-analyzer-*,concurrency-*,cppcoreguidelines-*,misc-*,modernize-*,performance-*,portability-*,readability-*,-misc-unused-using-decls,-cppcoreguidelines-pro-type-union-access,-readability-implicit-bool-conversion,-readability-magic-numbers,-bugprone-narrowing-conversions,-modernize-pass-by-value,-cppcoreguidelines-avoid-magic-numbers,-performance-inefficient-string-concatenation" --source=/home/idra/GitHub/Animation-Thingy/Modules/ComponentCompiler/src/Subtraction.cpp -- /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComponentCompiler.dir/Subtraction.cpp.o -c /home/idra/GitHub/Animation-Thingy/Modules/ComponentCompiler/src/Subtraction.cpp

Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/Subtraction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComponentCompiler.dir/Subtraction.cpp.i"
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ComponentCompiler/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/idra/GitHub/Animation-Thingy/Modules/ComponentCompiler/src/Subtraction.cpp > CMakeFiles/ComponentCompiler.dir/Subtraction.cpp.i

Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/Subtraction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComponentCompiler.dir/Subtraction.cpp.s"
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ComponentCompiler/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/idra/GitHub/Animation-Thingy/Modules/ComponentCompiler/src/Subtraction.cpp -o CMakeFiles/ComponentCompiler.dir/Subtraction.cpp.s

Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/Main.cpp.o: Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/flags.make
Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/Main.cpp.o: ../Modules/ComponentCompiler/src/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/idra/GitHub/Animation-Thingy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/Main.cpp.o"
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ComponentCompiler/src && $(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-checks=bugprone-*,clang-analyzer-*,concurrency-*,cppcoreguidelines-*,misc-*,modernize-*,performance-*,portability-*,readability-*,-misc-unused-using-decls,-cppcoreguidelines-pro-type-union-access,-readability-implicit-bool-conversion,-readability-magic-numbers,-bugprone-narrowing-conversions,-modernize-pass-by-value,-cppcoreguidelines-avoid-magic-numbers,-performance-inefficient-string-concatenation" --source=/home/idra/GitHub/Animation-Thingy/Modules/ComponentCompiler/src/Main.cpp -- /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComponentCompiler.dir/Main.cpp.o -c /home/idra/GitHub/Animation-Thingy/Modules/ComponentCompiler/src/Main.cpp

Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComponentCompiler.dir/Main.cpp.i"
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ComponentCompiler/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/idra/GitHub/Animation-Thingy/Modules/ComponentCompiler/src/Main.cpp > CMakeFiles/ComponentCompiler.dir/Main.cpp.i

Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComponentCompiler.dir/Main.cpp.s"
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ComponentCompiler/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/idra/GitHub/Animation-Thingy/Modules/ComponentCompiler/src/Main.cpp -o CMakeFiles/ComponentCompiler.dir/Main.cpp.s

# Object files for target ComponentCompiler
ComponentCompiler_OBJECTS = \
"CMakeFiles/ComponentCompiler.dir/Subtraction.cpp.o" \
"CMakeFiles/ComponentCompiler.dir/Main.cpp.o"

# External object files for target ComponentCompiler
ComponentCompiler_EXTERNAL_OBJECTS =

Modules/ComponentCompiler/src/ComponentCompiler: Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/Subtraction.cpp.o
Modules/ComponentCompiler/src/ComponentCompiler: Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/Main.cpp.o
Modules/ComponentCompiler/src/ComponentCompiler: Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/build.make
Modules/ComponentCompiler/src/ComponentCompiler: Modules/AnimationLibrary/src/libAnimationLibrary.a
Modules/ComponentCompiler/src/ComponentCompiler: Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/idra/GitHub/Animation-Thingy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ComponentCompiler"
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ComponentCompiler/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ComponentCompiler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/build: Modules/ComponentCompiler/src/ComponentCompiler

.PHONY : Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/build

Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/clean:
	cd /home/idra/GitHub/Animation-Thingy/build/Modules/ComponentCompiler/src && $(CMAKE_COMMAND) -P CMakeFiles/ComponentCompiler.dir/cmake_clean.cmake
.PHONY : Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/clean

Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/depend:
	cd /home/idra/GitHub/Animation-Thingy/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/idra/GitHub/Animation-Thingy /home/idra/GitHub/Animation-Thingy/Modules/ComponentCompiler/src /home/idra/GitHub/Animation-Thingy/build /home/idra/GitHub/Animation-Thingy/build/Modules/ComponentCompiler/src /home/idra/GitHub/Animation-Thingy/build/Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Modules/ComponentCompiler/src/CMakeFiles/ComponentCompiler.dir/depend
