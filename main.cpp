
// Libraries
#include <iostream>
#include <pthread.h>

// Game Logic
#include "Tests/GameLogicTest/DictionaryTest.hpp"
#include "Tests/GameLogicTest/PlayerTest.hpp"

// Sockets
#include "Tests/SocketsTest/socketTest1.hpp"

// JSON
#include "Tests/JsonTest/JSON_Test.hpp"

// gtest
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc,char* argv[]) {

    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();
    //DictionaryTest::test1();

    //PlayerTest::test1();
    //PlayerTest::test2();

    //JSON_Test::test1();

    return 0;
}





