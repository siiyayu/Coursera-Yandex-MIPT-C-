# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = "/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/_UNIQ_ID.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/_UNIQ_ID.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_UNIQ_ID.dir/flags.make

CMakeFiles/_UNIQ_ID.dir/main.cpp.o: CMakeFiles/_UNIQ_ID.dir/flags.make
CMakeFiles/_UNIQ_ID.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/_UNIQ_ID.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/_UNIQ_ID.dir/main.cpp.o -c "/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID/main.cpp"

CMakeFiles/_UNIQ_ID.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_UNIQ_ID.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID/main.cpp" > CMakeFiles/_UNIQ_ID.dir/main.cpp.i

CMakeFiles/_UNIQ_ID.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_UNIQ_ID.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID/main.cpp" -o CMakeFiles/_UNIQ_ID.dir/main.cpp.s

# Object files for target _UNIQ_ID
_UNIQ_ID_OBJECTS = \
"CMakeFiles/_UNIQ_ID.dir/main.cpp.o"

# External object files for target _UNIQ_ID
_UNIQ_ID_EXTERNAL_OBJECTS =

_UNIQ_ID: CMakeFiles/_UNIQ_ID.dir/main.cpp.o
_UNIQ_ID: CMakeFiles/_UNIQ_ID.dir/build.make
_UNIQ_ID: CMakeFiles/_UNIQ_ID.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable _UNIQ_ID"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_UNIQ_ID.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_UNIQ_ID.dir/build: _UNIQ_ID

.PHONY : CMakeFiles/_UNIQ_ID.dir/build

CMakeFiles/_UNIQ_ID.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/_UNIQ_ID.dir/cmake_clean.cmake
.PHONY : CMakeFiles/_UNIQ_ID.dir/clean

CMakeFiles/_UNIQ_ID.dir/depend:
	cd "/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID" "/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID" "/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID/cmake-build-debug" "/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID/cmake-build-debug" "/Users/andrewbelyaev/CLionProjects/Макрос UNIQ_ID/cmake-build-debug/CMakeFiles/_UNIQ_ID.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/_UNIQ_ID.dir/depend

