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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lekeifer/CLionProjects/QuickSort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lekeifer/CLionProjects/QuickSort/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/QuickSort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QuickSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QuickSort.dir/flags.make

CMakeFiles/QuickSort.dir/main.cpp.o: CMakeFiles/QuickSort.dir/flags.make
CMakeFiles/QuickSort.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lekeifer/CLionProjects/QuickSort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QuickSort.dir/main.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuickSort.dir/main.cpp.o -c /Users/lekeifer/CLionProjects/QuickSort/main.cpp

CMakeFiles/QuickSort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuickSort.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lekeifer/CLionProjects/QuickSort/main.cpp > CMakeFiles/QuickSort.dir/main.cpp.i

CMakeFiles/QuickSort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuickSort.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lekeifer/CLionProjects/QuickSort/main.cpp -o CMakeFiles/QuickSort.dir/main.cpp.s

# Object files for target QuickSort
QuickSort_OBJECTS = \
"CMakeFiles/QuickSort.dir/main.cpp.o"

# External object files for target QuickSort
QuickSort_EXTERNAL_OBJECTS =

QuickSort: CMakeFiles/QuickSort.dir/main.cpp.o
QuickSort: CMakeFiles/QuickSort.dir/build.make
QuickSort: CMakeFiles/QuickSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lekeifer/CLionProjects/QuickSort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable QuickSort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QuickSort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QuickSort.dir/build: QuickSort

.PHONY : CMakeFiles/QuickSort.dir/build

CMakeFiles/QuickSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QuickSort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QuickSort.dir/clean

CMakeFiles/QuickSort.dir/depend:
	cd /Users/lekeifer/CLionProjects/QuickSort/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lekeifer/CLionProjects/QuickSort /Users/lekeifer/CLionProjects/QuickSort /Users/lekeifer/CLionProjects/QuickSort/cmake-build-debug /Users/lekeifer/CLionProjects/QuickSort/cmake-build-debug /Users/lekeifer/CLionProjects/QuickSort/cmake-build-debug/CMakeFiles/QuickSort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QuickSort.dir/depend

