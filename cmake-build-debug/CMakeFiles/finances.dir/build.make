# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/supersu/projects/finances

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/supersu/projects/finances/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/finances.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/finances.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/finances.dir/flags.make

CMakeFiles/finances.dir/src/main.cpp.o: CMakeFiles/finances.dir/flags.make
CMakeFiles/finances.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/supersu/projects/finances/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/finances.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/finances.dir/src/main.cpp.o -c /Users/supersu/projects/finances/src/main.cpp

CMakeFiles/finances.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finances.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/supersu/projects/finances/src/main.cpp > CMakeFiles/finances.dir/src/main.cpp.i

CMakeFiles/finances.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finances.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/supersu/projects/finances/src/main.cpp -o CMakeFiles/finances.dir/src/main.cpp.s

CMakeFiles/finances.dir/src/Registry.cpp.o: CMakeFiles/finances.dir/flags.make
CMakeFiles/finances.dir/src/Registry.cpp.o: ../src/Registry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/supersu/projects/finances/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/finances.dir/src/Registry.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/finances.dir/src/Registry.cpp.o -c /Users/supersu/projects/finances/src/Registry.cpp

CMakeFiles/finances.dir/src/Registry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finances.dir/src/Registry.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/supersu/projects/finances/src/Registry.cpp > CMakeFiles/finances.dir/src/Registry.cpp.i

CMakeFiles/finances.dir/src/Registry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finances.dir/src/Registry.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/supersu/projects/finances/src/Registry.cpp -o CMakeFiles/finances.dir/src/Registry.cpp.s

CMakeFiles/finances.dir/src/CreditCard.cpp.o: CMakeFiles/finances.dir/flags.make
CMakeFiles/finances.dir/src/CreditCard.cpp.o: ../src/CreditCard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/supersu/projects/finances/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/finances.dir/src/CreditCard.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/finances.dir/src/CreditCard.cpp.o -c /Users/supersu/projects/finances/src/CreditCard.cpp

CMakeFiles/finances.dir/src/CreditCard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finances.dir/src/CreditCard.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/supersu/projects/finances/src/CreditCard.cpp > CMakeFiles/finances.dir/src/CreditCard.cpp.i

CMakeFiles/finances.dir/src/CreditCard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finances.dir/src/CreditCard.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/supersu/projects/finances/src/CreditCard.cpp -o CMakeFiles/finances.dir/src/CreditCard.cpp.s

CMakeFiles/finances.dir/src/FileFormatter.cpp.o: CMakeFiles/finances.dir/flags.make
CMakeFiles/finances.dir/src/FileFormatter.cpp.o: ../src/FileFormatter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/supersu/projects/finances/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/finances.dir/src/FileFormatter.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/finances.dir/src/FileFormatter.cpp.o -c /Users/supersu/projects/finances/src/FileFormatter.cpp

CMakeFiles/finances.dir/src/FileFormatter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finances.dir/src/FileFormatter.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/supersu/projects/finances/src/FileFormatter.cpp > CMakeFiles/finances.dir/src/FileFormatter.cpp.i

CMakeFiles/finances.dir/src/FileFormatter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finances.dir/src/FileFormatter.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/supersu/projects/finances/src/FileFormatter.cpp -o CMakeFiles/finances.dir/src/FileFormatter.cpp.s

CMakeFiles/finances.dir/src/Statistics.cpp.o: CMakeFiles/finances.dir/flags.make
CMakeFiles/finances.dir/src/Statistics.cpp.o: ../src/Statistics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/supersu/projects/finances/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/finances.dir/src/Statistics.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/finances.dir/src/Statistics.cpp.o -c /Users/supersu/projects/finances/src/Statistics.cpp

CMakeFiles/finances.dir/src/Statistics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finances.dir/src/Statistics.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/supersu/projects/finances/src/Statistics.cpp > CMakeFiles/finances.dir/src/Statistics.cpp.i

CMakeFiles/finances.dir/src/Statistics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finances.dir/src/Statistics.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/supersu/projects/finances/src/Statistics.cpp -o CMakeFiles/finances.dir/src/Statistics.cpp.s

# Object files for target finances
finances_OBJECTS = \
"CMakeFiles/finances.dir/src/main.cpp.o" \
"CMakeFiles/finances.dir/src/Registry.cpp.o" \
"CMakeFiles/finances.dir/src/CreditCard.cpp.o" \
"CMakeFiles/finances.dir/src/FileFormatter.cpp.o" \
"CMakeFiles/finances.dir/src/Statistics.cpp.o"

# External object files for target finances
finances_EXTERNAL_OBJECTS =

finances: CMakeFiles/finances.dir/src/main.cpp.o
finances: CMakeFiles/finances.dir/src/Registry.cpp.o
finances: CMakeFiles/finances.dir/src/CreditCard.cpp.o
finances: CMakeFiles/finances.dir/src/FileFormatter.cpp.o
finances: CMakeFiles/finances.dir/src/Statistics.cpp.o
finances: CMakeFiles/finances.dir/build.make
finances: CMakeFiles/finances.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/supersu/projects/finances/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable finances"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/finances.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/finances.dir/build: finances

.PHONY : CMakeFiles/finances.dir/build

CMakeFiles/finances.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/finances.dir/cmake_clean.cmake
.PHONY : CMakeFiles/finances.dir/clean

CMakeFiles/finances.dir/depend:
	cd /Users/supersu/projects/finances/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/supersu/projects/finances /Users/supersu/projects/finances /Users/supersu/projects/finances/cmake-build-debug /Users/supersu/projects/finances/cmake-build-debug /Users/supersu/projects/finances/cmake-build-debug/CMakeFiles/finances.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/finances.dir/depend

