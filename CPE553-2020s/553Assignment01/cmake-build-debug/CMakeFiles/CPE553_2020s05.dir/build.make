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
CMAKE_SOURCE_DIR = /Users/fengliu/CLionProjects/553Assignment01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fengliu/CLionProjects/553Assignment01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPE553_2020s05.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPE553_2020s05.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPE553_2020s05.dir/flags.make

CMakeFiles/CPE553_2020s05.dir/Feng_Liu_HW1E.cpp.o: CMakeFiles/CPE553_2020s05.dir/flags.make
CMakeFiles/CPE553_2020s05.dir/Feng_Liu_HW1E.cpp.o: ../Feng_Liu_HW1E.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fengliu/CLionProjects/553Assignment01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPE553_2020s05.dir/Feng_Liu_HW1E.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPE553_2020s05.dir/Feng_Liu_HW1E.cpp.o -c /Users/fengliu/CLionProjects/553Assignment01/Feng_Liu_HW1E.cpp

CMakeFiles/CPE553_2020s05.dir/Feng_Liu_HW1E.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPE553_2020s05.dir/Feng_Liu_HW1E.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fengliu/CLionProjects/553Assignment01/Feng_Liu_HW1E.cpp > CMakeFiles/CPE553_2020s05.dir/Feng_Liu_HW1E.cpp.i

CMakeFiles/CPE553_2020s05.dir/Feng_Liu_HW1E.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPE553_2020s05.dir/Feng_Liu_HW1E.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fengliu/CLionProjects/553Assignment01/Feng_Liu_HW1E.cpp -o CMakeFiles/CPE553_2020s05.dir/Feng_Liu_HW1E.cpp.s

# Object files for target CPE553_2020s05
CPE553_2020s05_OBJECTS = \
"CMakeFiles/CPE553_2020s05.dir/Feng_Liu_HW1E.cpp.o"

# External object files for target CPE553_2020s05
CPE553_2020s05_EXTERNAL_OBJECTS =

CPE553_2020s05: CMakeFiles/CPE553_2020s05.dir/Feng_Liu_HW1E.cpp.o
CPE553_2020s05: CMakeFiles/CPE553_2020s05.dir/build.make
CPE553_2020s05: CMakeFiles/CPE553_2020s05.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/fengliu/CLionProjects/553Assignment01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CPE553_2020s05"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPE553_2020s05.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPE553_2020s05.dir/build: CPE553_2020s05

.PHONY : CMakeFiles/CPE553_2020s05.dir/build

CMakeFiles/CPE553_2020s05.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPE553_2020s05.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPE553_2020s05.dir/clean

CMakeFiles/CPE553_2020s05.dir/depend:
	cd /Users/fengliu/CLionProjects/553Assignment01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fengliu/CLionProjects/553Assignment01 /Users/fengliu/CLionProjects/553Assignment01 /Users/fengliu/CLionProjects/553Assignment01/cmake-build-debug /Users/fengliu/CLionProjects/553Assignment01/cmake-build-debug /Users/fengliu/CLionProjects/553Assignment01/cmake-build-debug/CMakeFiles/CPE553_2020s05.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPE553_2020s05.dir/depend

