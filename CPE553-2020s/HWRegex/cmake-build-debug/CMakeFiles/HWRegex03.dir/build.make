# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/fengliu/CLionProjects/HWRegex

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fengliu/CLionProjects/HWRegex/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HWRegex03.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HWRegex03.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HWRegex03.dir/flags.make

CMakeFiles/HWRegex03.dir/test.cpp.o: CMakeFiles/HWRegex03.dir/flags.make
CMakeFiles/HWRegex03.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fengliu/CLionProjects/HWRegex/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HWRegex03.dir/test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HWRegex03.dir/test.cpp.o -c /Users/fengliu/CLionProjects/HWRegex/test.cpp

CMakeFiles/HWRegex03.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HWRegex03.dir/test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fengliu/CLionProjects/HWRegex/test.cpp > CMakeFiles/HWRegex03.dir/test.cpp.i

CMakeFiles/HWRegex03.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HWRegex03.dir/test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fengliu/CLionProjects/HWRegex/test.cpp -o CMakeFiles/HWRegex03.dir/test.cpp.s

# Object files for target HWRegex03
HWRegex03_OBJECTS = \
"CMakeFiles/HWRegex03.dir/test.cpp.o"

# External object files for target HWRegex03
HWRegex03_EXTERNAL_OBJECTS =

HWRegex03: CMakeFiles/HWRegex03.dir/test.cpp.o
HWRegex03: CMakeFiles/HWRegex03.dir/build.make
HWRegex03: CMakeFiles/HWRegex03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/fengliu/CLionProjects/HWRegex/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HWRegex03"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HWRegex03.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HWRegex03.dir/build: HWRegex03

.PHONY : CMakeFiles/HWRegex03.dir/build

CMakeFiles/HWRegex03.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HWRegex03.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HWRegex03.dir/clean

CMakeFiles/HWRegex03.dir/depend:
	cd /Users/fengliu/CLionProjects/HWRegex/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fengliu/CLionProjects/HWRegex /Users/fengliu/CLionProjects/HWRegex /Users/fengliu/CLionProjects/HWRegex/cmake-build-debug /Users/fengliu/CLionProjects/HWRegex/cmake-build-debug /Users/fengliu/CLionProjects/HWRegex/cmake-build-debug/CMakeFiles/HWRegex03.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HWRegex03.dir/depend

