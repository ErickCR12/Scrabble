cmake_minimum_required(VERSION 3.13)
project(Scrabble)

set(CMAKE_CXX_STANDARD 17)

add_executable(Scrabble main.cpp gamelogic/Dictionary.hpp gamelogic/GameDeck.hpp gamelogic/LetterTile.hpp
        datastructures/Stack.hpp datastructures/Queue.hpp datastructures/CircularList.hpp gamelogic/Board.cpp
        gamelogic/Board.hpp gamelogic/Dictionary.cpp gamelogic/LetterTile.cpp gamelogic/Player.hpp gamelogic/Player.cpp
        gamelogic/Game.cpp gamelogic/Game.hpp gamelogic/GameDeck.cpp SocketComunication/socketClient.hpp SocketComunication/socketServer.hpp)