# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /cygdrive/c/Users/Mat/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Mat/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TD6_TasBinomial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TD6_TasBinomial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TD6_TasBinomial.dir/flags.make

CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o: CMakeFiles/TD6_TasBinomial.dir/flags.make
CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o: ../tas_binomial.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o   -c /cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial/tas_binomial.c

CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial/tas_binomial.c > CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.i

CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial/tas_binomial.c -o CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.s

CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o.requires:

.PHONY : CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o.requires

CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o.provides: CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o.requires
	$(MAKE) -f CMakeFiles/TD6_TasBinomial.dir/build.make CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o.provides.build
.PHONY : CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o.provides

CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o.provides.build: CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o


# Object files for target TD6_TasBinomial
TD6_TasBinomial_OBJECTS = \
"CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o"

# External object files for target TD6_TasBinomial
TD6_TasBinomial_EXTERNAL_OBJECTS =

TD6_TasBinomial.exe: CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o
TD6_TasBinomial.exe: CMakeFiles/TD6_TasBinomial.dir/build.make
TD6_TasBinomial.exe: CMakeFiles/TD6_TasBinomial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable TD6_TasBinomial.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TD6_TasBinomial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TD6_TasBinomial.dir/build: TD6_TasBinomial.exe

.PHONY : CMakeFiles/TD6_TasBinomial.dir/build

CMakeFiles/TD6_TasBinomial.dir/requires: CMakeFiles/TD6_TasBinomial.dir/tas_binomial.c.o.requires

.PHONY : CMakeFiles/TD6_TasBinomial.dir/requires

CMakeFiles/TD6_TasBinomial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TD6_TasBinomial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TD6_TasBinomial.dir/clean

CMakeFiles/TD6_TasBinomial.dir/depend:
	cd /cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial /cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial /cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial/cmake-build-debug /cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial/cmake-build-debug /cygdrive/f/Fac/L3Algo/L3Algo/TD6_TasBinomial/cmake-build-debug/CMakeFiles/TD6_TasBinomial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TD6_TasBinomial.dir/depend

