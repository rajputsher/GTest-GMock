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
CMAKE_SOURCE_DIR = /home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj/build

# Include any dependencies generated for this target.
include CMakeFiles/databaseConnectionLibrary.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/databaseConnectionLibrary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/databaseConnectionLibrary.dir/flags.make

CMakeFiles/databaseConnectionLibrary.dir/IDatabaseConnection.cpp.o: CMakeFiles/databaseConnectionLibrary.dir/flags.make
CMakeFiles/databaseConnectionLibrary.dir/IDatabaseConnection.cpp.o: ../IDatabaseConnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/databaseConnectionLibrary.dir/IDatabaseConnection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/databaseConnectionLibrary.dir/IDatabaseConnection.cpp.o -c /home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj/IDatabaseConnection.cpp

CMakeFiles/databaseConnectionLibrary.dir/IDatabaseConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/databaseConnectionLibrary.dir/IDatabaseConnection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj/IDatabaseConnection.cpp > CMakeFiles/databaseConnectionLibrary.dir/IDatabaseConnection.cpp.i

CMakeFiles/databaseConnectionLibrary.dir/IDatabaseConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/databaseConnectionLibrary.dir/IDatabaseConnection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj/IDatabaseConnection.cpp -o CMakeFiles/databaseConnectionLibrary.dir/IDatabaseConnection.cpp.s

# Object files for target databaseConnectionLibrary
databaseConnectionLibrary_OBJECTS = \
"CMakeFiles/databaseConnectionLibrary.dir/IDatabaseConnection.cpp.o"

# External object files for target databaseConnectionLibrary
databaseConnectionLibrary_EXTERNAL_OBJECTS =

libdatabaseConnectionLibrary.a: CMakeFiles/databaseConnectionLibrary.dir/IDatabaseConnection.cpp.o
libdatabaseConnectionLibrary.a: CMakeFiles/databaseConnectionLibrary.dir/build.make
libdatabaseConnectionLibrary.a: CMakeFiles/databaseConnectionLibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libdatabaseConnectionLibrary.a"
	$(CMAKE_COMMAND) -P CMakeFiles/databaseConnectionLibrary.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/databaseConnectionLibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/databaseConnectionLibrary.dir/build: libdatabaseConnectionLibrary.a

.PHONY : CMakeFiles/databaseConnectionLibrary.dir/build

CMakeFiles/databaseConnectionLibrary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/databaseConnectionLibrary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/databaseConnectionLibrary.dir/clean

CMakeFiles/databaseConnectionLibrary.dir/depend:
	cd /home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj /home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj /home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj/build /home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj/build /home/shivsayali/Shivaram/onlineCourses/GTest-GMock/4_GMockProject/GMock_proj/build/CMakeFiles/databaseConnectionLibrary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/databaseConnectionLibrary.dir/depend

