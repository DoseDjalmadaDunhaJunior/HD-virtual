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
CMAKE_COMMAND = /opt/clion-2019.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/djalma/Desktop/sexto_semestre/HD-virtual

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/djalma/Desktop/sexto_semestre/HD-virtual/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HD_Virtual.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HD_Virtual.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HD_Virtual.dir/flags.make

CMakeFiles/HD_Virtual.dir/main.cpp.o: CMakeFiles/HD_Virtual.dir/flags.make
CMakeFiles/HD_Virtual.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/djalma/Desktop/sexto_semestre/HD-virtual/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HD_Virtual.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HD_Virtual.dir/main.cpp.o -c /home/djalma/Desktop/sexto_semestre/HD-virtual/main.cpp

CMakeFiles/HD_Virtual.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HD_Virtual.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/djalma/Desktop/sexto_semestre/HD-virtual/main.cpp > CMakeFiles/HD_Virtual.dir/main.cpp.i

CMakeFiles/HD_Virtual.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HD_Virtual.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/djalma/Desktop/sexto_semestre/HD-virtual/main.cpp -o CMakeFiles/HD_Virtual.dir/main.cpp.s

# Object files for target HD_Virtual
HD_Virtual_OBJECTS = \
"CMakeFiles/HD_Virtual.dir/main.cpp.o"

# External object files for target HD_Virtual
HD_Virtual_EXTERNAL_OBJECTS =

HD_Virtual: CMakeFiles/HD_Virtual.dir/main.cpp.o
HD_Virtual: CMakeFiles/HD_Virtual.dir/build.make
HD_Virtual: CMakeFiles/HD_Virtual.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/djalma/Desktop/sexto_semestre/HD-virtual/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HD_Virtual"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HD_Virtual.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HD_Virtual.dir/build: HD_Virtual

.PHONY : CMakeFiles/HD_Virtual.dir/build

CMakeFiles/HD_Virtual.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HD_Virtual.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HD_Virtual.dir/clean

CMakeFiles/HD_Virtual.dir/depend:
	cd /home/djalma/Desktop/sexto_semestre/HD-virtual/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/djalma/Desktop/sexto_semestre/HD-virtual /home/djalma/Desktop/sexto_semestre/HD-virtual /home/djalma/Desktop/sexto_semestre/HD-virtual/cmake-build-debug /home/djalma/Desktop/sexto_semestre/HD-virtual/cmake-build-debug /home/djalma/Desktop/sexto_semestre/HD-virtual/cmake-build-debug/CMakeFiles/HD_Virtual.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HD_Virtual.dir/depend

