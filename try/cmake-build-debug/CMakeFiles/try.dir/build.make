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
CMAKE_SOURCE_DIR = /Users/andrewbelyaev/CLionProjects/try

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrewbelyaev/CLionProjects/try/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/try.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/try.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/try.dir/flags.make

CMakeFiles/try.dir/main.cpp.o: CMakeFiles/try.dir/flags.make
CMakeFiles/try.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrewbelyaev/CLionProjects/try/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/try.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/try.dir/main.cpp.o -c /Users/andrewbelyaev/CLionProjects/try/main.cpp

CMakeFiles/try.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/try.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrewbelyaev/CLionProjects/try/main.cpp > CMakeFiles/try.dir/main.cpp.i

CMakeFiles/try.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/try.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrewbelyaev/CLionProjects/try/main.cpp -o CMakeFiles/try.dir/main.cpp.s

# Object files for target try
try_OBJECTS = \
"CMakeFiles/try.dir/main.cpp.o"

# External object files for target try
try_EXTERNAL_OBJECTS =

try: CMakeFiles/try.dir/main.cpp.o
try: CMakeFiles/try.dir/build.make
try: CMakeFiles/try.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andrewbelyaev/CLionProjects/try/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable try"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/try.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/try.dir/build: try

.PHONY : CMakeFiles/try.dir/build

CMakeFiles/try.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/try.dir/cmake_clean.cmake
.PHONY : CMakeFiles/try.dir/clean

CMakeFiles/try.dir/depend:
	cd /Users/andrewbelyaev/CLionProjects/try/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrewbelyaev/CLionProjects/try /Users/andrewbelyaev/CLionProjects/try /Users/andrewbelyaev/CLionProjects/try/cmake-build-debug /Users/andrewbelyaev/CLionProjects/try/cmake-build-debug /Users/andrewbelyaev/CLionProjects/try/cmake-build-debug/CMakeFiles/try.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/try.dir/depend

