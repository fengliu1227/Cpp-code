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
CMAKE_SOURCE_DIR = /Users/fengliu/CLionProjects/553Assignment07

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fengliu/CLionProjects/553Assignment07/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/553Assignment0702.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/553Assignment0702.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/553Assignment0702.dir/flags.make

CMakeFiles/553Assignment0702.dir/examplewritefile.cc.o: CMakeFiles/553Assignment0702.dir/flags.make
CMakeFiles/553Assignment0702.dir/examplewritefile.cc.o: ../examplewritefile.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fengliu/CLionProjects/553Assignment07/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/553Assignment0702.dir/examplewritefile.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/553Assignment0702.dir/examplewritefile.cc.o -c /Users/fengliu/CLionProjects/553Assignment07/examplewritefile.cc

CMakeFiles/553Assignment0702.dir/examplewritefile.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/553Assignment0702.dir/examplewritefile.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fengliu/CLionProjects/553Assignment07/examplewritefile.cc > CMakeFiles/553Assignment0702.dir/examplewritefile.cc.i

CMakeFiles/553Assignment0702.dir/examplewritefile.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/553Assignment0702.dir/examplewritefile.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fengliu/CLionProjects/553Assignment07/examplewritefile.cc -o CMakeFiles/553Assignment0702.dir/examplewritefile.cc.s

# Object files for target 553Assignment0702
553Assignment0702_OBJECTS = \
"CMakeFiles/553Assignment0702.dir/examplewritefile.cc.o"

# External object files for target 553Assignment0702
553Assignment0702_EXTERNAL_OBJECTS =

553Assignment0702: CMakeFiles/553Assignment0702.dir/examplewritefile.cc.o
553Assignment0702: CMakeFiles/553Assignment0702.dir/build.make
553Assignment0702: CMakeFiles/553Assignment0702.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/fengliu/CLionProjects/553Assignment07/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 553Assignment0702"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/553Assignment0702.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/553Assignment0702.dir/build: 553Assignment0702

.PHONY : CMakeFiles/553Assignment0702.dir/build

CMakeFiles/553Assignment0702.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/553Assignment0702.dir/cmake_clean.cmake
.PHONY : CMakeFiles/553Assignment0702.dir/clean

CMakeFiles/553Assignment0702.dir/depend:
	cd /Users/fengliu/CLionProjects/553Assignment07/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fengliu/CLionProjects/553Assignment07 /Users/fengliu/CLionProjects/553Assignment07 /Users/fengliu/CLionProjects/553Assignment07/cmake-build-debug /Users/fengliu/CLionProjects/553Assignment07/cmake-build-debug /Users/fengliu/CLionProjects/553Assignment07/cmake-build-debug/CMakeFiles/553Assignment0702.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/553Assignment0702.dir/depend

