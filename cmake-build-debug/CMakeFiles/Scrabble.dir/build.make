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
CMAKE_COMMAND = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Scrabble.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Scrabble.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Scrabble.dir/flags.make

CMakeFiles/Scrabble.dir/main.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Scrabble.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/main.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/main.cpp

CMakeFiles/Scrabble.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/main.cpp > CMakeFiles/Scrabble.dir/main.cpp.i

CMakeFiles/Scrabble.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/main.cpp -o CMakeFiles/Scrabble.dir/main.cpp.s

CMakeFiles/Scrabble.dir/gameLogic/Board.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/gameLogic/Board.cpp.o: ../gameLogic/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Scrabble.dir/gameLogic/Board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/gameLogic/Board.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Board.cpp

CMakeFiles/Scrabble.dir/gameLogic/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/gameLogic/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Board.cpp > CMakeFiles/Scrabble.dir/gameLogic/Board.cpp.i

CMakeFiles/Scrabble.dir/gameLogic/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/gameLogic/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Board.cpp -o CMakeFiles/Scrabble.dir/gameLogic/Board.cpp.s

CMakeFiles/Scrabble.dir/gameLogic/Dictionary.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/gameLogic/Dictionary.cpp.o: ../gameLogic/Dictionary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Scrabble.dir/gameLogic/Dictionary.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/gameLogic/Dictionary.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Dictionary.cpp

CMakeFiles/Scrabble.dir/gameLogic/Dictionary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/gameLogic/Dictionary.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Dictionary.cpp > CMakeFiles/Scrabble.dir/gameLogic/Dictionary.cpp.i

CMakeFiles/Scrabble.dir/gameLogic/Dictionary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/gameLogic/Dictionary.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Dictionary.cpp -o CMakeFiles/Scrabble.dir/gameLogic/Dictionary.cpp.s

CMakeFiles/Scrabble.dir/gameLogic/LetterTile.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/gameLogic/LetterTile.cpp.o: ../gameLogic/LetterTile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Scrabble.dir/gameLogic/LetterTile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/gameLogic/LetterTile.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/LetterTile.cpp

CMakeFiles/Scrabble.dir/gameLogic/LetterTile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/gameLogic/LetterTile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/LetterTile.cpp > CMakeFiles/Scrabble.dir/gameLogic/LetterTile.cpp.i

CMakeFiles/Scrabble.dir/gameLogic/LetterTile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/gameLogic/LetterTile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/LetterTile.cpp -o CMakeFiles/Scrabble.dir/gameLogic/LetterTile.cpp.s

CMakeFiles/Scrabble.dir/gameLogic/Player.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/gameLogic/Player.cpp.o: ../gameLogic/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Scrabble.dir/gameLogic/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/gameLogic/Player.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Player.cpp

CMakeFiles/Scrabble.dir/gameLogic/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/gameLogic/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Player.cpp > CMakeFiles/Scrabble.dir/gameLogic/Player.cpp.i

CMakeFiles/Scrabble.dir/gameLogic/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/gameLogic/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Player.cpp -o CMakeFiles/Scrabble.dir/gameLogic/Player.cpp.s

CMakeFiles/Scrabble.dir/gameLogic/Game.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/gameLogic/Game.cpp.o: ../gameLogic/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Scrabble.dir/gameLogic/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/gameLogic/Game.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Game.cpp

CMakeFiles/Scrabble.dir/gameLogic/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/gameLogic/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Game.cpp > CMakeFiles/Scrabble.dir/gameLogic/Game.cpp.i

CMakeFiles/Scrabble.dir/gameLogic/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/gameLogic/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Game.cpp -o CMakeFiles/Scrabble.dir/gameLogic/Game.cpp.s

CMakeFiles/Scrabble.dir/gameLogic/GameDeck.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/gameLogic/GameDeck.cpp.o: ../gameLogic/GameDeck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Scrabble.dir/gameLogic/GameDeck.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/gameLogic/GameDeck.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/GameDeck.cpp

CMakeFiles/Scrabble.dir/gameLogic/GameDeck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/gameLogic/GameDeck.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/GameDeck.cpp > CMakeFiles/Scrabble.dir/gameLogic/GameDeck.cpp.i

CMakeFiles/Scrabble.dir/gameLogic/GameDeck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/gameLogic/GameDeck.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/GameDeck.cpp -o CMakeFiles/Scrabble.dir/gameLogic/GameDeck.cpp.s

CMakeFiles/Scrabble.dir/gameLogic/Server.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/gameLogic/Server.cpp.o: ../gameLogic/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Scrabble.dir/gameLogic/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/gameLogic/Server.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Server.cpp

CMakeFiles/Scrabble.dir/gameLogic/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/gameLogic/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Server.cpp > CMakeFiles/Scrabble.dir/gameLogic/Server.cpp.i

CMakeFiles/Scrabble.dir/gameLogic/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/gameLogic/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/gameLogic/Server.cpp -o CMakeFiles/Scrabble.dir/gameLogic/Server.cpp.s

CMakeFiles/Scrabble.dir/Tests/JsonTest/JSON_Test.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/Tests/JsonTest/JSON_Test.cpp.o: ../Tests/JsonTest/JSON_Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Scrabble.dir/Tests/JsonTest/JSON_Test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/Tests/JsonTest/JSON_Test.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/JsonTest/JSON_Test.cpp

CMakeFiles/Scrabble.dir/Tests/JsonTest/JSON_Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/Tests/JsonTest/JSON_Test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/JsonTest/JSON_Test.cpp > CMakeFiles/Scrabble.dir/Tests/JsonTest/JSON_Test.cpp.i

CMakeFiles/Scrabble.dir/Tests/JsonTest/JSON_Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/Tests/JsonTest/JSON_Test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/JsonTest/JSON_Test.cpp -o CMakeFiles/Scrabble.dir/Tests/JsonTest/JSON_Test.cpp.s

CMakeFiles/Scrabble.dir/Tests/GameLogicTest/DictionaryTest.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/Tests/GameLogicTest/DictionaryTest.cpp.o: ../Tests/GameLogicTest/DictionaryTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Scrabble.dir/Tests/GameLogicTest/DictionaryTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/Tests/GameLogicTest/DictionaryTest.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/GameLogicTest/DictionaryTest.cpp

CMakeFiles/Scrabble.dir/Tests/GameLogicTest/DictionaryTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/Tests/GameLogicTest/DictionaryTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/GameLogicTest/DictionaryTest.cpp > CMakeFiles/Scrabble.dir/Tests/GameLogicTest/DictionaryTest.cpp.i

CMakeFiles/Scrabble.dir/Tests/GameLogicTest/DictionaryTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/Tests/GameLogicTest/DictionaryTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/GameLogicTest/DictionaryTest.cpp -o CMakeFiles/Scrabble.dir/Tests/GameLogicTest/DictionaryTest.cpp.s

CMakeFiles/Scrabble.dir/Tests/GameLogicTest/PlayerTest.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/Tests/GameLogicTest/PlayerTest.cpp.o: ../Tests/GameLogicTest/PlayerTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Scrabble.dir/Tests/GameLogicTest/PlayerTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/Tests/GameLogicTest/PlayerTest.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/GameLogicTest/PlayerTest.cpp

CMakeFiles/Scrabble.dir/Tests/GameLogicTest/PlayerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/Tests/GameLogicTest/PlayerTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/GameLogicTest/PlayerTest.cpp > CMakeFiles/Scrabble.dir/Tests/GameLogicTest/PlayerTest.cpp.i

CMakeFiles/Scrabble.dir/Tests/GameLogicTest/PlayerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/Tests/GameLogicTest/PlayerTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/GameLogicTest/PlayerTest.cpp -o CMakeFiles/Scrabble.dir/Tests/GameLogicTest/PlayerTest.cpp.s

CMakeFiles/Scrabble.dir/Tests/SocketsTest/socketTest1.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/Tests/SocketsTest/socketTest1.cpp.o: ../Tests/SocketsTest/socketTest1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Scrabble.dir/Tests/SocketsTest/socketTest1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/Tests/SocketsTest/socketTest1.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/SocketsTest/socketTest1.cpp

CMakeFiles/Scrabble.dir/Tests/SocketsTest/socketTest1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/Tests/SocketsTest/socketTest1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/SocketsTest/socketTest1.cpp > CMakeFiles/Scrabble.dir/Tests/SocketsTest/socketTest1.cpp.i

CMakeFiles/Scrabble.dir/Tests/SocketsTest/socketTest1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/Tests/SocketsTest/socketTest1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/SocketsTest/socketTest1.cpp -o CMakeFiles/Scrabble.dir/Tests/SocketsTest/socketTest1.cpp.s

CMakeFiles/Scrabble.dir/Tests/GameLogicTest/Board_gtest.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/Tests/GameLogicTest/Board_gtest.cpp.o: ../Tests/GameLogicTest/Board_gtest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Scrabble.dir/Tests/GameLogicTest/Board_gtest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/Tests/GameLogicTest/Board_gtest.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/GameLogicTest/Board_gtest.cpp

CMakeFiles/Scrabble.dir/Tests/GameLogicTest/Board_gtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/Tests/GameLogicTest/Board_gtest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/GameLogicTest/Board_gtest.cpp > CMakeFiles/Scrabble.dir/Tests/GameLogicTest/Board_gtest.cpp.i

CMakeFiles/Scrabble.dir/Tests/GameLogicTest/Board_gtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/Tests/GameLogicTest/Board_gtest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/Tests/GameLogicTest/Board_gtest.cpp -o CMakeFiles/Scrabble.dir/Tests/GameLogicTest/Board_gtest.cpp.s

CMakeFiles/Scrabble.dir/JSON/PlayerMessage.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/JSON/PlayerMessage.cpp.o: ../JSON/PlayerMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Scrabble.dir/JSON/PlayerMessage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/JSON/PlayerMessage.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/JSON/PlayerMessage.cpp

CMakeFiles/Scrabble.dir/JSON/PlayerMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/JSON/PlayerMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/JSON/PlayerMessage.cpp > CMakeFiles/Scrabble.dir/JSON/PlayerMessage.cpp.i

CMakeFiles/Scrabble.dir/JSON/PlayerMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/JSON/PlayerMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/JSON/PlayerMessage.cpp -o CMakeFiles/Scrabble.dir/JSON/PlayerMessage.cpp.s

CMakeFiles/Scrabble.dir/JSON/ServerMessage.cpp.o: CMakeFiles/Scrabble.dir/flags.make
CMakeFiles/Scrabble.dir/JSON/ServerMessage.cpp.o: ../JSON/ServerMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Scrabble.dir/JSON/ServerMessage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Scrabble.dir/JSON/ServerMessage.cpp.o -c /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/JSON/ServerMessage.cpp

CMakeFiles/Scrabble.dir/JSON/ServerMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Scrabble.dir/JSON/ServerMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/JSON/ServerMessage.cpp > CMakeFiles/Scrabble.dir/JSON/ServerMessage.cpp.i

CMakeFiles/Scrabble.dir/JSON/ServerMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Scrabble.dir/JSON/ServerMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/JSON/ServerMessage.cpp -o CMakeFiles/Scrabble.dir/JSON/ServerMessage.cpp.s

# Object files for target Scrabble
Scrabble_OBJECTS = \
"CMakeFiles/Scrabble.dir/main.cpp.o" \
"CMakeFiles/Scrabble.dir/gameLogic/Board.cpp.o" \
"CMakeFiles/Scrabble.dir/gameLogic/Dictionary.cpp.o" \
"CMakeFiles/Scrabble.dir/gameLogic/LetterTile.cpp.o" \
"CMakeFiles/Scrabble.dir/gameLogic/Player.cpp.o" \
"CMakeFiles/Scrabble.dir/gameLogic/Game.cpp.o" \
"CMakeFiles/Scrabble.dir/gameLogic/GameDeck.cpp.o" \
"CMakeFiles/Scrabble.dir/gameLogic/Server.cpp.o" \
"CMakeFiles/Scrabble.dir/Tests/JsonTest/JSON_Test.cpp.o" \
"CMakeFiles/Scrabble.dir/Tests/GameLogicTest/DictionaryTest.cpp.o" \
"CMakeFiles/Scrabble.dir/Tests/GameLogicTest/PlayerTest.cpp.o" \
"CMakeFiles/Scrabble.dir/Tests/SocketsTest/socketTest1.cpp.o" \
"CMakeFiles/Scrabble.dir/Tests/GameLogicTest/Board_gtest.cpp.o" \
"CMakeFiles/Scrabble.dir/JSON/PlayerMessage.cpp.o" \
"CMakeFiles/Scrabble.dir/JSON/ServerMessage.cpp.o"

# External object files for target Scrabble
Scrabble_EXTERNAL_OBJECTS =

Scrabble: CMakeFiles/Scrabble.dir/main.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/gameLogic/Board.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/gameLogic/Dictionary.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/gameLogic/LetterTile.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/gameLogic/Player.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/gameLogic/Game.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/gameLogic/GameDeck.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/gameLogic/Server.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/Tests/JsonTest/JSON_Test.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/Tests/GameLogicTest/DictionaryTest.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/Tests/GameLogicTest/PlayerTest.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/Tests/SocketsTest/socketTest1.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/Tests/GameLogicTest/Board_gtest.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/JSON/PlayerMessage.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/JSON/ServerMessage.cpp.o
Scrabble: CMakeFiles/Scrabble.dir/build.make
Scrabble: lib/libgtestd.a
Scrabble: lib/libgtest_maind.a
Scrabble: lib/libgtestd.a
Scrabble: CMakeFiles/Scrabble.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable Scrabble"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Scrabble.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Scrabble.dir/build: Scrabble

.PHONY : CMakeFiles/Scrabble.dir/build

CMakeFiles/Scrabble.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Scrabble.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Scrabble.dir/clean

CMakeFiles/Scrabble.dir/depend:
	cd /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/cmake-build-debug/CMakeFiles/Scrabble.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Scrabble.dir/depend

