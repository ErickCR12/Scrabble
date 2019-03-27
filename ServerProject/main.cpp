
// Libraries
#include <iostream>
#include <pthread.h>

// Game Logic
#include "Tests/GameLogicTest/DictionaryTest.hpp"
#include "Tests/GameLogicTest/PlayerTest.hpp"
#include "gameLogic/Game.hpp"

// Sockets
#include "Tests/SocketsTest/socketTest1.hpp"

// JSON
#include "Tests/JsonTest/JSON_Test.hpp"
#include "JSON/PlayerMessage.hpp"

// gtest
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc,char* argv[]) {


    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();

    //PlayerTest::test2();

    Game* g1 = new Game(2);
    cout<<"Code : "<<g1->getGameCode()<<endl;

    PlayerMessage* sms = new PlayerMessage();
    sms->setMessage("camaron",0,0,true);
    string json = sms->serialize();
    g1->recieveMessage(json);
    sms->setMessage("omedor",0,1,false);
    json = sms->serialize();
    g1->recieveMessage(json);

    //DictionaryTest::test1();

    //PlayerTest::test1();
    //

    //JSON_Test::test1();

    return 0;
}





