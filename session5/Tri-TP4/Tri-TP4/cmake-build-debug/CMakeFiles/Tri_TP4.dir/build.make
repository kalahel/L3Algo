# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Remi\Desktop\cours\L3\Algorithme\Tri-TP4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Remi\Desktop\cours\L3\Algorithme\Tri-TP4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tri_TP4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tri_TP4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tri_TP4.dir/flags.make

CMakeFiles/Tri_TP4.dir/main.c.obj: CMakeFiles/Tri_TP4.dir/flags.make
CMakeFiles/Tri_TP4.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Remi\Desktop\cours\L3\Algorithme\Tri-TP4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Tri_TP4.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Tri_TP4.dir\main.c.obj   -c C:\Users\Remi\Desktop\cours\L3\Algorithme\Tri-TP4\main.c

CMakeFiles/Tri_TP4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tri_TP4.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Remi\Desktop\cours\L3\Algorithme\Tri-TP4\main.c > CMakeFiles\Tri_TP4.dir\main.c.i

CMakeFiles/Tri_TP4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tri_TP4.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Remi\Desktop\cours\L3\Algorithme\Tri-TP4\main.c -o CMakeFiles\Tri_TP4.dir\main.c.s

CMakeFiles/Tri_TP4.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Tri_TP4.dir/main.c.obj.requires

CMakeFiles/Tri_TP4.dir/main.c.obj.provides: CMakeFiles/Tri_TP4.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Tri_TP4.dir\build.make CMakeFiles/Tri_TP4.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Tri_TP4.dir/main.c.obj.provides

CMakeFiles/Tri_TP4.dir/main.c.obj.provides.build: CMakeFiles/Tri_TP4.dir/main.c.obj


# Object files for target Tri_TP4
Tri_TP4_OBJECTS = \
"CMakeFiles/Tri_TP4.dir/main.c.obj"

# External object files for target Tri_TP4
Tri_TP4_EXTERNAL_OBJECTS =

Tri_TP4.exe: CMakeFiles/Tri_TP4.dir/main.c.obj
Tri_TP4.exe: CMakeFiles/Tri_TP4.dir/build.make
Tri_TP4.exe: CMakeFiles/Tri_TP4.dir/linklibs.rsp
Tri_TP4.exe: CMakeFiles/Tri_TP4.dir/objects1.rsp
Tri_TP4.exe: CMakeFiles/Tri_TP4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Remi\Desktop\cours\L3\Algorithme\Tri-TP4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Tri_TP4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tri_TP4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tri_TP4.dir/build: Tri_TP4.exe

.PHONY : CMakeFiles/Tri_TP4.dir/build

CMakeFiles/Tri_TP4.dir/requires: CMakeFiles/Tri_TP4.dir/main.c.obj.requires

.PHONY : CMakeFiles/Tri_TP4.dir/requires

CMakeFiles/Tri_TP4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tri_TP4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tri_TP4.dir/clean

CMakeFiles/Tri_TP4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Remi\Desktop\cours\L3\Algorithme\Tri-TP4 C:\Users\Remi\Desktop\cours\L3\Algorithme\Tri-TP4 C:\Users\Remi\Desktop\cours\L3\Algorithme\Tri-TP4\cmake-build-debug C:\Users\Remi\Desktop\cours\L3\Algorithme\Tri-TP4\cmake-build-debug C:\Users\Remi\Desktop\cours\L3\Algorithme\Tri-TP4\cmake-build-debug\CMakeFiles\Tri_TP4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tri_TP4.dir/depend
