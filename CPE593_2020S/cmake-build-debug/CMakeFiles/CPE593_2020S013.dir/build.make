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
CMAKE_SOURCE_DIR = /Users/fengliu/CLionProjects/CPE593_2020S

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fengliu/CLionProjects/CPE593_2020S/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPE593_2020S013.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPE593_2020S013.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPE593_2020S013.dir/flags.make

CMakeFiles/CPE593_2020S013.dir/LiuF_5.cpp.o: CMakeFiles/CPE593_2020S013.dir/flags.make
CMakeFiles/CPE593_2020S013.dir/LiuF_5.cpp.o: ../LiuF_5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fengliu/CLionProjects/CPE593_2020S/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPE593_2020S013.dir/LiuF_5.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPE593_2020S013.dir/LiuF_5.cpp.o -c /Users/fengliu/CLionProjects/CPE593_2020S/LiuF_5.cpp

CMakeFiles/CPE593_2020S013.dir/LiuF_5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPE593_2020S013.dir/LiuF_5.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fengliu/CLionProjects/CPE593_2020S/LiuF_5.cpp > CMakeFiles/CPE593_2020S013.dir/LiuF_5.cpp.i

CMakeFiles/CPE593_2020S013.dir/LiuF_5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPE593_2020S013.dir/LiuF_5.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fengliu/CLionProjects/CPE593_2020S/LiuF_5.cpp -o CMakeFiles/CPE593_2020S013.dir/LiuF_5.cpp.s

# Object files for target CPE593_2020S013
CPE593_2020S013_OBJECTS = \
"CMakeFiles/CPE593_2020S013.dir/LiuF_5.cpp.o"

# External object files for target CPE593_2020S013
CPE593_2020S013_EXTERNAL_OBJECTS =

CPE593_2020S013: CMakeFiles/CPE593_2020S013.dir/LiuF_5.cpp.o
CPE593_2020S013: CMakeFiles/CPE593_2020S013.dir/build.make
CPE593_2020S013: CMakeFiles/CPE593_2020S013.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/fengliu/CLionProjects/CPE593_2020S/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CPE593_2020S013"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPE593_2020S013.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPE593_2020S013.dir/build: CPE593_2020S013

.PHONY : CMakeFiles/CPE593_2020S013.dir/build

CMakeFiles/CPE593_2020S013.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPE593_2020S013.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPE593_2020S013.dir/clean

CMakeFiles/CPE593_2020S013.dir/depend:
	cd /Users/fengliu/CLionProjects/CPE593_2020S/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fengliu/CLionProjects/CPE593_2020S /Users/fengliu/CLionProjects/CPE593_2020S /Users/fengliu/CLionProjects/CPE593_2020S/cmake-build-debug /Users/fengliu/CLionProjects/CPE593_2020S/cmake-build-debug /Users/fengliu/CLionProjects/CPE593_2020S/cmake-build-debug/CMakeFiles/CPE593_2020S013.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPE593_2020S013.dir/depend

