cmake_minimum_required(VERSION 3.13)
project(Scrabble)

set(CMAKE_CXX_STANDARD 17)

add_executable(Scrabble main.cpp gameLogic/Dictionary.hpp gameLogic/GameDeck.hpp gameLogic/LetterTile.hpp
        dataStructures/Stack.hpp dataStructures/Queue.hpp dataStructures/CircularList.hpp gameLogic/Board.cpp
        gameLogic/Board.hpp gameLogic/Dictionary.cpp gameLogic/LetterTile.cpp gameLogic/Player.hpp gameLogic/Player.cpp
        gameLogic/Game.cpp gameLogic/Game.hpp gameLogic/GameDeck.cpp SocketComunication/socketClient.hpp
        SocketComunication/socketServer.hpp ScrabbleTest/JsonTest/JSON_Test.cpp ScrabbleTest/JsonTest/JSON_Test.hpp ScrabbleTest/GameLogicTest/DictionaryTest.cpp ScrabbleTest/GameLogicTest/DictionaryTest.hpp JSON/JsonMessage.cpp JSON/JsonMessage.hpp ScrabbleTest/GameLogicTest/BoardTest.cpp ScrabbleTest/GameLogicTest/BoardTest.hpp ScrabbleTest/GameLogicTest/PlayerTest.cpp ScrabbleTest/GameLogicTest/PlayerTest.hpp ScrabbleTest/SocketsTest/socketTest1.cpp ScrabbleTest/SocketsTest/socketTest1.hpp)
