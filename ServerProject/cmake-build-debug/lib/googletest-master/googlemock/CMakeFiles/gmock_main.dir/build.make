# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
<<<<<<< HEAD
CMAKE_COMMAND = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f
=======
CMAKE_COMMAND = /opt/clion-2019.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.1/bin/cmake/linux/bin/cmake -E remove -f
>>>>>>> master

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
<<<<<<< HEAD
CMAKE_SOURCE_DIR = /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug
=======
CMAKE_SOURCE_DIR = /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug
>>>>>>> master

# Include any dependencies generated for this target.
include lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/depend.make

# Include the progress variables for this target.
include lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/flags.make

lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/flags.make
lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: ../lib/googletest-master/googlemock/src/gmock_main.cc
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	cd /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/lib/googletest-master/googlemock/src/gmock_main.cc

lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/lib/googletest-master/googlemock/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/lib/googletest-master/googlemock/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	cd /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/lib/googletest-master/googlemock/src/gmock_main.cc

lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/lib/googletest-master/googlemock/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/lib/googletest-master/googlemock/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s
>>>>>>> master

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

lib/libgmock_maind.a: lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
lib/libgmock_maind.a: lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/build.make
lib/libgmock_maind.a: lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/link.txt
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../libgmock_maind.a"
	cd /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	cd /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../libgmock_maind.a"
	cd /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	cd /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)
>>>>>>> master

# Rule to build all files generated by this target.
lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/build: lib/libgmock_maind.a

.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/build

lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/clean:
<<<<<<< HEAD
	cd /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/clean

lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/depend:
	cd /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/lib/googletest-master/googlemock /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/DependInfo.cmake --color=$(COLOR)
=======
	cd /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/clean

lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/depend:
	cd /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/lib/googletest-master/googlemock /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock /home/oscar_araya_x/CLionProjects/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> master
.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock_main.dir/depend

