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
CMAKE_SOURCE_DIR = /home/luis/open_gl/tarea1/onda_cotangente

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luis/open_gl/tarea1/onda_cotangente/build

# Include any dependencies generated for this target.
include CMakeFiles/actividad.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/actividad.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/actividad.dir/flags.make

CMakeFiles/actividad.dir/onda_cotangente.cpp.o: CMakeFiles/actividad.dir/flags.make
CMakeFiles/actividad.dir/onda_cotangente.cpp.o: ../onda_cotangente.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/open_gl/tarea1/onda_cotangente/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/actividad.dir/onda_cotangente.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/actividad.dir/onda_cotangente.cpp.o -c /home/luis/open_gl/tarea1/onda_cotangente/onda_cotangente.cpp

CMakeFiles/actividad.dir/onda_cotangente.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/actividad.dir/onda_cotangente.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luis/open_gl/tarea1/onda_cotangente/onda_cotangente.cpp > CMakeFiles/actividad.dir/onda_cotangente.cpp.i

CMakeFiles/actividad.dir/onda_cotangente.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/actividad.dir/onda_cotangente.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luis/open_gl/tarea1/onda_cotangente/onda_cotangente.cpp -o CMakeFiles/actividad.dir/onda_cotangente.cpp.s

CMakeFiles/actividad.dir/onda_cotangente.cpp.o.requires:

.PHONY : CMakeFiles/actividad.dir/onda_cotangente.cpp.o.requires

CMakeFiles/actividad.dir/onda_cotangente.cpp.o.provides: CMakeFiles/actividad.dir/onda_cotangente.cpp.o.requires
	$(MAKE) -f CMakeFiles/actividad.dir/build.make CMakeFiles/actividad.dir/onda_cotangente.cpp.o.provides.build
.PHONY : CMakeFiles/actividad.dir/onda_cotangente.cpp.o.provides

CMakeFiles/actividad.dir/onda_cotangente.cpp.o.provides.build: CMakeFiles/actividad.dir/onda_cotangente.cpp.o


# Object files for target actividad
actividad_OBJECTS = \
"CMakeFiles/actividad.dir/onda_cotangente.cpp.o"

# External object files for target actividad
actividad_EXTERNAL_OBJECTS =

actividad: CMakeFiles/actividad.dir/onda_cotangente.cpp.o
actividad: CMakeFiles/actividad.dir/build.make
actividad: /usr/lib/x86_64-linux-gnu/libGLU.so
actividad: /usr/lib/x86_64-linux-gnu/libGL.so
actividad: /usr/lib/x86_64-linux-gnu/libglut.so
actividad: /usr/lib/x86_64-linux-gnu/libXmu.so
actividad: /usr/lib/x86_64-linux-gnu/libXi.so
actividad: CMakeFiles/actividad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luis/open_gl/tarea1/onda_cotangente/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable actividad"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/actividad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/actividad.dir/build: actividad

.PHONY : CMakeFiles/actividad.dir/build

CMakeFiles/actividad.dir/requires: CMakeFiles/actividad.dir/onda_cotangente.cpp.o.requires

.PHONY : CMakeFiles/actividad.dir/requires

CMakeFiles/actividad.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/actividad.dir/cmake_clean.cmake
.PHONY : CMakeFiles/actividad.dir/clean

CMakeFiles/actividad.dir/depend:
	cd /home/luis/open_gl/tarea1/onda_cotangente/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luis/open_gl/tarea1/onda_cotangente /home/luis/open_gl/tarea1/onda_cotangente /home/luis/open_gl/tarea1/onda_cotangente/build /home/luis/open_gl/tarea1/onda_cotangente/build /home/luis/open_gl/tarea1/onda_cotangente/build/CMakeFiles/actividad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/actividad.dir/depend

