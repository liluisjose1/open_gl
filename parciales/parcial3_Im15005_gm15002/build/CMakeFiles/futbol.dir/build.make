# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/luis/parcial3_Im15005_gm15002

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luis/parcial3_Im15005_gm15002/build

# Include any dependencies generated for this target.
include CMakeFiles/futbol.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/futbol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/futbol.dir/flags.make

CMakeFiles/futbol.dir/main.cpp.o: CMakeFiles/futbol.dir/flags.make
CMakeFiles/futbol.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/parcial3_Im15005_gm15002/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/futbol.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/futbol.dir/main.cpp.o -c /home/luis/parcial3_Im15005_gm15002/main.cpp

CMakeFiles/futbol.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/futbol.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luis/parcial3_Im15005_gm15002/main.cpp > CMakeFiles/futbol.dir/main.cpp.i

CMakeFiles/futbol.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/futbol.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luis/parcial3_Im15005_gm15002/main.cpp -o CMakeFiles/futbol.dir/main.cpp.s

CMakeFiles/futbol.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/futbol.dir/main.cpp.o.requires

CMakeFiles/futbol.dir/main.cpp.o.provides: CMakeFiles/futbol.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/futbol.dir/build.make CMakeFiles/futbol.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/futbol.dir/main.cpp.o.provides

CMakeFiles/futbol.dir/main.cpp.o.provides.build: CMakeFiles/futbol.dir/main.cpp.o


# Object files for target futbol
futbol_OBJECTS = \
"CMakeFiles/futbol.dir/main.cpp.o"

# External object files for target futbol
futbol_EXTERNAL_OBJECTS =

futbol: CMakeFiles/futbol.dir/main.cpp.o
futbol: CMakeFiles/futbol.dir/build.make
futbol: /usr/lib/x86_64-linux-gnu/libGLU.so
futbol: /usr/lib/x86_64-linux-gnu/libGL.so
futbol: /usr/lib/x86_64-linux-gnu/libglut.so
futbol: /usr/lib/x86_64-linux-gnu/libXmu.so
futbol: /usr/lib/x86_64-linux-gnu/libXi.so
futbol: CMakeFiles/futbol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luis/parcial3_Im15005_gm15002/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable futbol"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/futbol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/futbol.dir/build: futbol

.PHONY : CMakeFiles/futbol.dir/build

CMakeFiles/futbol.dir/requires: CMakeFiles/futbol.dir/main.cpp.o.requires

.PHONY : CMakeFiles/futbol.dir/requires

CMakeFiles/futbol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/futbol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/futbol.dir/clean

CMakeFiles/futbol.dir/depend:
	cd /home/luis/parcial3_Im15005_gm15002/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luis/parcial3_Im15005_gm15002 /home/luis/parcial3_Im15005_gm15002 /home/luis/parcial3_Im15005_gm15002/build /home/luis/parcial3_Im15005_gm15002/build /home/luis/parcial3_Im15005_gm15002/build/CMakeFiles/futbol.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/futbol.dir/depend

