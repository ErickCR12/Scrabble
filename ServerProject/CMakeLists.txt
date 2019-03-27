cmake_minimum_required(VERSION 3.13)
project(Scrabble)

set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG_ON) # <- This line allows CLion to enable Threads

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


find_package(Threads) # <- This line allows CLion to enable Threads

add_executable(
        Scrabble main.cpp

        dataStructures/Stack.hpp dataStructures/Queue.hpp dataStructures/CircularList.hpp

        gameLogic/Board.cpp gameLogic/Board.hpp
        gameLogic/Dictionary.cpp gameLogic/Dictionary.hpp
        gameLogic/LetterTile.cpp gameLogic/LetterTile.hpp
        gameLogic/Player.hpp gameLogic/Player.cpp
        gameLogic/Game.cpp gameLogic/Game.hpp
        gameLogic/GameDeck.cpp  gameLogic/GameDeck.hpp
        gameLogic/Server.cpp gameLogic/Server.hpp

        SocketComunication/socketClient.hpp SocketComunication/socketClient.cpp
        SocketComunication/socketServer.hpp SocketComunication/socketServer.cpp

        Tests/JsonTest/JSON_Test.cpp Tests/JsonTest/JSON_Test.hpp
        Tests/GameLogicTest/DictionaryTest.cpp Tests/GameLogicTest/DictionaryTest.hpp
        Tests/GameLogicTest/PlayerTest.hpp Tests/GameLogicTest/PlayerTest.cpp
        Tests/SocketsTest/socketTest1.cpp Tests/SocketsTest/socketTest1.hpp
        Tests/GameLogicTest/Board_gtest.cpp

        JSON/PlayerMessage.cpp JSON/PlayerMessage.hpp
        JSON/ServerMessage.cpp JSON/ServerMessage.hpp

)


target_link_libraries(Scrabble gtest gtest_main)
target_link_libraries(Scrabble ${CMAKE_THREAD_LIBS_INIT}) # <- This line allows CLion to enable Threads
