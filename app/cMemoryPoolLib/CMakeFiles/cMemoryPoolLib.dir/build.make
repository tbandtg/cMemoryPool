# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/agarza/learning/cMemoryPool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/agarza/learning/cMemoryPool/app

# Include any dependencies generated for this target.
include cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/compiler_depend.make

# Include the progress variables for this target.
include cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/progress.make

# Include the compile flags for this target's objects.
include cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/flags.make

cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.o: cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/flags.make
cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.o: ../cMemoryPoolLib/source/cMemoryPool.c
cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.o: cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/agarza/learning/cMemoryPool/app/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.o"
	cd /home/agarza/learning/cMemoryPool/app/cMemoryPoolLib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.o -MF CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.o.d -o CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.o -c /home/agarza/learning/cMemoryPool/cMemoryPoolLib/source/cMemoryPool.c

cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.i"
	cd /home/agarza/learning/cMemoryPool/app/cMemoryPoolLib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/agarza/learning/cMemoryPool/cMemoryPoolLib/source/cMemoryPool.c > CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.i

cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.s"
	cd /home/agarza/learning/cMemoryPool/app/cMemoryPoolLib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/agarza/learning/cMemoryPool/cMemoryPoolLib/source/cMemoryPool.c -o CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.s

# Object files for target cMemoryPoolLib
cMemoryPoolLib_OBJECTS = \
"CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.o"

# External object files for target cMemoryPoolLib
cMemoryPoolLib_EXTERNAL_OBJECTS =

cMemoryPoolLib/libcMemoryPoolLib.a: cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/source/cMemoryPool.c.o
cMemoryPoolLib/libcMemoryPoolLib.a: cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/build.make
cMemoryPoolLib/libcMemoryPoolLib.a: cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/agarza/learning/cMemoryPool/app/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libcMemoryPoolLib.a"
	cd /home/agarza/learning/cMemoryPool/app/cMemoryPoolLib && $(CMAKE_COMMAND) -P CMakeFiles/cMemoryPoolLib.dir/cmake_clean_target.cmake
	cd /home/agarza/learning/cMemoryPool/app/cMemoryPoolLib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cMemoryPoolLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/build: cMemoryPoolLib/libcMemoryPoolLib.a
.PHONY : cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/build

cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/clean:
	cd /home/agarza/learning/cMemoryPool/app/cMemoryPoolLib && $(CMAKE_COMMAND) -P CMakeFiles/cMemoryPoolLib.dir/cmake_clean.cmake
.PHONY : cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/clean

cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/depend:
	cd /home/agarza/learning/cMemoryPool/app && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/agarza/learning/cMemoryPool /home/agarza/learning/cMemoryPool/cMemoryPoolLib /home/agarza/learning/cMemoryPool/app /home/agarza/learning/cMemoryPool/app/cMemoryPoolLib /home/agarza/learning/cMemoryPool/app/cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cMemoryPoolLib/CMakeFiles/cMemoryPoolLib.dir/depend

