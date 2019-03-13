cmake_minimum_required(VERSION 3.13)
project(Scrabble)

set(CMAKE_CXX_STANDARD 17)

add_executable(Scrabble main.cpp Objects/Dictionary.hpp Objects/GameDeck.hpp Objects/LetterTile.hpp DataStructures/Stack.hpp DataStructures/Queue.hpp Objects/ServerBoard.hpp Objects/ClientBoard.hpp Objects/Player.hpp DataStructures/CircularList.hpp)