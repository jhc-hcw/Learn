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
CMAKE_SOURCE_DIR = /home/jhc/桌面/Learn/j_for_net/file9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jhc/桌面/Learn/j_for_net/file9/build

# Include any dependencies generated for this target.
include CMakeFiles/select.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/select.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/select.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/select.dir/flags.make

CMakeFiles/select.dir/select.cpp.o: CMakeFiles/select.dir/flags.make
CMakeFiles/select.dir/select.cpp.o: ../select.cpp
CMakeFiles/select.dir/select.cpp.o: CMakeFiles/select.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jhc/桌面/Learn/j_for_net/file9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/select.dir/select.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/select.dir/select.cpp.o -MF CMakeFiles/select.dir/select.cpp.o.d -o CMakeFiles/select.dir/select.cpp.o -c /home/jhc/桌面/Learn/j_for_net/file9/select.cpp

CMakeFiles/select.dir/select.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/select.dir/select.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jhc/桌面/Learn/j_for_net/file9/select.cpp > CMakeFiles/select.dir/select.cpp.i

CMakeFiles/select.dir/select.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/select.dir/select.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jhc/桌面/Learn/j_for_net/file9/select.cpp -o CMakeFiles/select.dir/select.cpp.s

# Object files for target select
select_OBJECTS = \
"CMakeFiles/select.dir/select.cpp.o"

# External object files for target select
select_EXTERNAL_OBJECTS =

bin/select: CMakeFiles/select.dir/select.cpp.o
bin/select: CMakeFiles/select.dir/build.make
bin/select: CMakeFiles/select.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jhc/桌面/Learn/j_for_net/file9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/select"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/select.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/select.dir/build: bin/select
.PHONY : CMakeFiles/select.dir/build

CMakeFiles/select.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/select.dir/cmake_clean.cmake
.PHONY : CMakeFiles/select.dir/clean

CMakeFiles/select.dir/depend:
	cd /home/jhc/桌面/Learn/j_for_net/file9/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jhc/桌面/Learn/j_for_net/file9 /home/jhc/桌面/Learn/j_for_net/file9 /home/jhc/桌面/Learn/j_for_net/file9/build /home/jhc/桌面/Learn/j_for_net/file9/build /home/jhc/桌面/Learn/j_for_net/file9/build/CMakeFiles/select.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/select.dir/depend

