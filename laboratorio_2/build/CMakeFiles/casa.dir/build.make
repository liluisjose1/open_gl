# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/luis/open_gl/laboratorio_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luis/open_gl/laboratorio_2/build

# Include any dependencies generated for this target.
include CMakeFiles/casa.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/casa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/casa.dir/flags.make

CMakeFiles/casa.dir/casa.cpp.o: CMakeFiles/casa.dir/flags.make
CMakeFiles/casa.dir/casa.cpp.o: ../casa.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/open_gl/laboratorio_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/casa.dir/casa.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/casa.dir/casa.cpp.o -c /home/luis/open_gl/laboratorio_2/casa.cpp

CMakeFiles/casa.dir/casa.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/casa.dir/casa.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luis/open_gl/laboratorio_2/casa.cpp > CMakeFiles/casa.dir/casa.cpp.i

CMakeFiles/casa.dir/casa.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/casa.dir/casa.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luis/open_gl/laboratorio_2/casa.cpp -o CMakeFiles/casa.dir/casa.cpp.s

CMakeFiles/casa.dir/casa.cpp.o.requires:

.PHONY : CMakeFiles/casa.dir/casa.cpp.o.requires

CMakeFiles/casa.dir/casa.cpp.o.provides: CMakeFiles/casa.dir/casa.cpp.o.requires
	$(MAKE) -f CMakeFiles/casa.dir/build.make CMakeFiles/casa.dir/casa.cpp.o.provides.build
.PHONY : CMakeFiles/casa.dir/casa.cpp.o.provides

CMakeFiles/casa.dir/casa.cpp.o.provides.build: CMakeFiles/casa.dir/casa.cpp.o


# Object files for target casa
casa_OBJECTS = \
"CMakeFiles/casa.dir/casa.cpp.o"

# External object files for target casa
casa_EXTERNAL_OBJECTS =

casa: CMakeFiles/casa.dir/casa.cpp.o
casa: CMakeFiles/casa.dir/build.make
casa: /usr/lib/x86_64-linux-gnu/libGLU.so
casa: /usr/lib/x86_64-linux-gnu/libGL.so
casa: /usr/lib/x86_64-linux-gnu/libglut.so
casa: /usr/lib/x86_64-linux-gnu/libXmu.so
casa: /usr/lib/x86_64-linux-gnu/libXi.so
casa: CMakeFiles/casa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luis/open_gl/laboratorio_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable casa"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/casa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/casa.dir/build: casa

.PHONY : CMakeFiles/casa.dir/build

CMakeFiles/casa.dir/requires: CMakeFiles/casa.dir/casa.cpp.o.requires

.PHONY : CMakeFiles/casa.dir/requires

CMakeFiles/casa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/casa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/casa.dir/clean

CMakeFiles/casa.dir/depend:
	cd /home/luis/open_gl/laboratorio_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luis/open_gl/laboratorio_2 /home/luis/open_gl/laboratorio_2 /home/luis/open_gl/laboratorio_2/build /home/luis/open_gl/laboratorio_2/build /home/luis/open_gl/laboratorio_2/build/CMakeFiles/casa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/casa.dir/depend

