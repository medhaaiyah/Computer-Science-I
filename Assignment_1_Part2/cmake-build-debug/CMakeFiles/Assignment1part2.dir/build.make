# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\medha\CLionProjects\Assignment1part2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\medha\CLionProjects\Assignment1part2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Assignment1part2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment1part2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment1part2.dir/flags.make

CMakeFiles/Assignment1part2.dir/main.cpp.obj: CMakeFiles/Assignment1part2.dir/flags.make
CMakeFiles/Assignment1part2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\medha\CLionProjects\Assignment1part2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment1part2.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment1part2.dir\main.cpp.obj -c C:\Users\medha\CLionProjects\Assignment1part2\main.cpp

CMakeFiles/Assignment1part2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment1part2.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\medha\CLionProjects\Assignment1part2\main.cpp > CMakeFiles\Assignment1part2.dir\main.cpp.i

CMakeFiles/Assignment1part2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment1part2.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\medha\CLionProjects\Assignment1part2\main.cpp -o CMakeFiles\Assignment1part2.dir\main.cpp.s

CMakeFiles/Assignment1part2.dir/assignment1part2.cpp.obj: CMakeFiles/Assignment1part2.dir/flags.make
CMakeFiles/Assignment1part2.dir/assignment1part2.cpp.obj: ../assignment1part2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\medha\CLionProjects\Assignment1part2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Assignment1part2.dir/assignment1part2.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment1part2.dir\assignment1part2.cpp.obj -c C:\Users\medha\CLionProjects\Assignment1part2\assignment1part2.cpp

CMakeFiles/Assignment1part2.dir/assignment1part2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment1part2.dir/assignment1part2.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\medha\CLionProjects\Assignment1part2\assignment1part2.cpp > CMakeFiles\Assignment1part2.dir\assignment1part2.cpp.i

CMakeFiles/Assignment1part2.dir/assignment1part2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment1part2.dir/assignment1part2.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\medha\CLionProjects\Assignment1part2\assignment1part2.cpp -o CMakeFiles\Assignment1part2.dir\assignment1part2.cpp.s

# Object files for target Assignment1part2
Assignment1part2_OBJECTS = \
"CMakeFiles/Assignment1part2.dir/main.cpp.obj" \
"CMakeFiles/Assignment1part2.dir/assignment1part2.cpp.obj"

# External object files for target Assignment1part2
Assignment1part2_EXTERNAL_OBJECTS =

Assignment1part2.exe: CMakeFiles/Assignment1part2.dir/main.cpp.obj
Assignment1part2.exe: CMakeFiles/Assignment1part2.dir/assignment1part2.cpp.obj
Assignment1part2.exe: CMakeFiles/Assignment1part2.dir/build.make
Assignment1part2.exe: CMakeFiles/Assignment1part2.dir/linklibs.rsp
Assignment1part2.exe: CMakeFiles/Assignment1part2.dir/objects1.rsp
Assignment1part2.exe: CMakeFiles/Assignment1part2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\medha\CLionProjects\Assignment1part2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Assignment1part2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Assignment1part2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment1part2.dir/build: Assignment1part2.exe

.PHONY : CMakeFiles/Assignment1part2.dir/build

CMakeFiles/Assignment1part2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Assignment1part2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Assignment1part2.dir/clean

CMakeFiles/Assignment1part2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\medha\CLionProjects\Assignment1part2 C:\Users\medha\CLionProjects\Assignment1part2 C:\Users\medha\CLionProjects\Assignment1part2\cmake-build-debug C:\Users\medha\CLionProjects\Assignment1part2\cmake-build-debug C:\Users\medha\CLionProjects\Assignment1part2\cmake-build-debug\CMakeFiles\Assignment1part2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment1part2.dir/depend

