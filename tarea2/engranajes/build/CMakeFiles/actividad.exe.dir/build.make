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
CMAKE_SOURCE_DIR = /home/luis/open_gl/tarea2/engranajes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luis/open_gl/tarea2/engranajes/build

# Include any dependencies generated for this target.
include CMakeFiles/actividad.exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/actividad.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/actividad.exe.dir/flags.make

CMakeFiles/actividad.exe.dir/engranajes.cpp.o: CMakeFiles/actividad.exe.dir/flags.make
CMakeFiles/actividad.exe.dir/engranajes.cpp.o: ../engranajes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/open_gl/tarea2/engranajes/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/actividad.exe.dir/engranajes.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/actividad.exe.dir/engranajes.cpp.o -c /home/luis/open_gl/tarea2/engranajes/engranajes.cpp

CMakeFiles/actividad.exe.dir/engranajes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/actividad.exe.dir/engranajes.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luis/open_gl/tarea2/engranajes/engranajes.cpp > CMakeFiles/actividad.exe.dir/engranajes.cpp.i

CMakeFiles/actividad.exe.dir/engranajes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/actividad.exe.dir/engranajes.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luis/open_gl/tarea2/engranajes/engranajes.cpp -o CMakeFiles/actividad.exe.dir/engranajes.cpp.s

CMakeFiles/actividad.exe.dir/engranajes.cpp.o.requires:

.PHONY : CMakeFiles/actividad.exe.dir/engranajes.cpp.o.requires

CMakeFiles/actividad.exe.dir/engranajes.cpp.o.provides: CMakeFiles/actividad.exe.dir/engranajes.cpp.o.requires
	$(MAKE) -f CMakeFiles/actividad.exe.dir/build.make CMakeFiles/actividad.exe.dir/engranajes.cpp.o.provides.build
.PHONY : CMakeFiles/actividad.exe.dir/engranajes.cpp.o.provides

CMakeFiles/actividad.exe.dir/engranajes.cpp.o.provides.build: CMakeFiles/actividad.exe.dir/engranajes.cpp.o


# Object files for target actividad.exe
actividad_exe_OBJECTS = \
"CMakeFiles/actividad.exe.dir/engranajes.cpp.o"

# External object files for target actividad.exe
actividad_exe_EXTERNAL_OBJECTS =

actividad.exe: CMakeFiles/actividad.exe.dir/engranajes.cpp.o
actividad.exe: CMakeFiles/actividad.exe.dir/build.make
actividad.exe: /usr/lib/x86_64-linux-gnu/libGLU.so
actividad.exe: /usr/lib/x86_64-linux-gnu/libGL.so
actividad.exe: /usr/lib/x86_64-linux-gnu/libglut.so
actividad.exe: /usr/lib/x86_64-linux-gnu/libXmu.so
actividad.exe: /usr/lib/x86_64-linux-gnu/libXi.so
actividad.exe: CMakeFiles/actividad.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luis/open_gl/tarea2/engranajes/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable actividad.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/actividad.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/actividad.exe.dir/build: actividad.exe

.PHONY : CMakeFiles/actividad.exe.dir/build

CMakeFiles/actividad.exe.dir/requires: CMakeFiles/actividad.exe.dir/engranajes.cpp.o.requires

.PHONY : CMakeFiles/actividad.exe.dir/requires

CMakeFiles/actividad.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/actividad.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/actividad.exe.dir/clean

CMakeFiles/actividad.exe.dir/depend:
	cd /home/luis/open_gl/tarea2/engranajes/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luis/open_gl/tarea2/engranajes /home/luis/open_gl/tarea2/engranajes /home/luis/open_gl/tarea2/engranajes/build /home/luis/open_gl/tarea2/engranajes/build /home/luis/open_gl/tarea2/engranajes/build/CMakeFiles/actividad.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/actividad.exe.dir/depend

