# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /snap/cmake/549/bin/cmake

# The command to remove a file.
RM = /snap/cmake/549/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wiktor/Desktop/Vector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wiktor/Desktop/Vector/bulid

# Include any dependencies generated for this target.
include CMakeFiles/vector-ut.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vector-ut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vector-ut.dir/flags.make

CMakeFiles/vector-ut.dir/tests/main.ut.cpp.o: CMakeFiles/vector-ut.dir/flags.make
CMakeFiles/vector-ut.dir/tests/main.ut.cpp.o: ../tests/main.ut.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wiktor/Desktop/Vector/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vector-ut.dir/tests/main.ut.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vector-ut.dir/tests/main.ut.cpp.o -c /home/wiktor/Desktop/Vector/tests/main.ut.cpp

CMakeFiles/vector-ut.dir/tests/main.ut.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector-ut.dir/tests/main.ut.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wiktor/Desktop/Vector/tests/main.ut.cpp > CMakeFiles/vector-ut.dir/tests/main.ut.cpp.i

CMakeFiles/vector-ut.dir/tests/main.ut.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector-ut.dir/tests/main.ut.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wiktor/Desktop/Vector/tests/main.ut.cpp -o CMakeFiles/vector-ut.dir/tests/main.ut.cpp.s

CMakeFiles/vector-ut.dir/tests/vector.ut.cpp.o: CMakeFiles/vector-ut.dir/flags.make
CMakeFiles/vector-ut.dir/tests/vector.ut.cpp.o: ../tests/vector.ut.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wiktor/Desktop/Vector/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/vector-ut.dir/tests/vector.ut.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vector-ut.dir/tests/vector.ut.cpp.o -c /home/wiktor/Desktop/Vector/tests/vector.ut.cpp

CMakeFiles/vector-ut.dir/tests/vector.ut.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector-ut.dir/tests/vector.ut.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wiktor/Desktop/Vector/tests/vector.ut.cpp > CMakeFiles/vector-ut.dir/tests/vector.ut.cpp.i

CMakeFiles/vector-ut.dir/tests/vector.ut.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector-ut.dir/tests/vector.ut.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wiktor/Desktop/Vector/tests/vector.ut.cpp -o CMakeFiles/vector-ut.dir/tests/vector.ut.cpp.s

# Object files for target vector-ut
vector__ut_OBJECTS = \
"CMakeFiles/vector-ut.dir/tests/main.ut.cpp.o" \
"CMakeFiles/vector-ut.dir/tests/vector.ut.cpp.o"

# External object files for target vector-ut
vector__ut_EXTERNAL_OBJECTS =

vector-ut: CMakeFiles/vector-ut.dir/tests/main.ut.cpp.o
vector-ut: CMakeFiles/vector-ut.dir/tests/vector.ut.cpp.o
vector-ut: CMakeFiles/vector-ut.dir/build.make
vector-ut: CMakeFiles/vector-ut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wiktor/Desktop/Vector/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable vector-ut"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vector-ut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vector-ut.dir/build: vector-ut

.PHONY : CMakeFiles/vector-ut.dir/build

CMakeFiles/vector-ut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vector-ut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vector-ut.dir/clean

CMakeFiles/vector-ut.dir/depend:
	cd /home/wiktor/Desktop/Vector/bulid && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wiktor/Desktop/Vector /home/wiktor/Desktop/Vector /home/wiktor/Desktop/Vector/bulid /home/wiktor/Desktop/Vector/bulid /home/wiktor/Desktop/Vector/bulid/CMakeFiles/vector-ut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vector-ut.dir/depend

