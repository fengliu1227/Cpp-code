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
CMAKE_SOURCE_DIR = /Users/fengliu/CLionProjects/553Assignment03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fengliu/CLionProjects/553Assignment03/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/553Assignment0303.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/553Assignment0303.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/553Assignment0303.dir/flags.make

CMakeFiles/553Assignment0303.dir/Feng_Liu_HW3B_GameOfLife.cpp.o: CMakeFiles/553Assignment0303.dir/flags.make
CMakeFiles/553Assignment0303.dir/Feng_Liu_HW3B_GameOfLife.cpp.o: ../Feng_Liu_HW3B_GameOfLife.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fengliu/CLionProjects/553Assignment03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/553Assignment0303.dir/Feng_Liu_HW3B_GameOfLife.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/553Assignment0303.dir/Feng_Liu_HW3B_GameOfLife.cpp.o -c /Users/fengliu/CLionProjects/553Assignment03/Feng_Liu_HW3B_GameOfLife.cpp

CMakeFiles/553Assignment0303.dir/Feng_Liu_HW3B_GameOfLife.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/553Assignment0303.dir/Feng_Liu_HW3B_GameOfLife.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fengliu/CLionProjects/553Assignment03/Feng_Liu_HW3B_GameOfLife.cpp > CMakeFiles/553Assignment0303.dir/Feng_Liu_HW3B_GameOfLife.cpp.i

CMakeFiles/553Assignment0303.dir/Feng_Liu_HW3B_GameOfLife.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/553Assignment0303.dir/Feng_Liu_HW3B_GameOfLife.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fengliu/CLionProjects/553Assignment03/Feng_Liu_HW3B_GameOfLife.cpp -o CMakeFiles/553Assignment0303.dir/Feng_Liu_HW3B_GameOfLife.cpp.s

# Object files for target 553Assignment0303
553Assignment0303_OBJECTS = \
"CMakeFiles/553Assignment0303.dir/Feng_Liu_HW3B_GameOfLife.cpp.o"

# External object files for target 553Assignment0303
553Assignment0303_EXTERNAL_OBJECTS =

553Assignment0303: CMakeFiles/553Assignment0303.dir/Feng_Liu_HW3B_GameOfLife.cpp.o
553Assignment0303: CMakeFiles/553Assignment0303.dir/build.make
553Assignment0303: CMakeFiles/553Assignment0303.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/fengliu/CLionProjects/553Assignment03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 553Assignment0303"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/553Assignment0303.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/553Assignment0303.dir/build: 553Assignment0303

.PHONY : CMakeFiles/553Assignment0303.dir/build

CMakeFiles/553Assignment0303.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/553Assignment0303.dir/cmake_clean.cmake
.PHONY : CMakeFiles/553Assignment0303.dir/clean

CMakeFiles/553Assignment0303.dir/depend:
	cd /Users/fengliu/CLionProjects/553Assignment03/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fengliu/CLionProjects/553Assignment03 /Users/fengliu/CLionProjects/553Assignment03 /Users/fengliu/CLionProjects/553Assignment03/cmake-build-debug /Users/fengliu/CLionProjects/553Assignment03/cmake-build-debug /Users/fengliu/CLionProjects/553Assignment03/cmake-build-debug/CMakeFiles/553Assignment0303.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/553Assignment0303.dir/depend

