# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3

# Include any dependencies generated for this target.
include CMakeFiles/my_solution.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_solution.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_solution.dir/flags.make

CMakeFiles/my_solution.dir/lab3.cpp.o: CMakeFiles/my_solution.dir/flags.make
CMakeFiles/my_solution.dir/lab3.cpp.o: lab3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_solution.dir/lab3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_solution.dir/lab3.cpp.o -c /mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3/lab3.cpp

CMakeFiles/my_solution.dir/lab3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_solution.dir/lab3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3/lab3.cpp > CMakeFiles/my_solution.dir/lab3.cpp.i

CMakeFiles/my_solution.dir/lab3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_solution.dir/lab3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3/lab3.cpp -o CMakeFiles/my_solution.dir/lab3.cpp.s

# Object files for target my_solution
my_solution_OBJECTS = \
"CMakeFiles/my_solution.dir/lab3.cpp.o"

# External object files for target my_solution
my_solution_EXTERNAL_OBJECTS =

my_solution: CMakeFiles/my_solution.dir/lab3.cpp.o
my_solution: CMakeFiles/my_solution.dir/build.make
my_solution: CMakeFiles/my_solution.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable my_solution"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_solution.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_solution.dir/build: my_solution

.PHONY : CMakeFiles/my_solution.dir/build

CMakeFiles/my_solution.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_solution.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_solution.dir/clean

CMakeFiles/my_solution.dir/depend:
	cd /mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3 /mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3 /mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3 /mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3 /mnt/e/Facultate/an4/Sem1/PAOO/PAOO/lab3/CMakeFiles/my_solution.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_solution.dir/depend

