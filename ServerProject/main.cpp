
// Libraries
#include <iostream>
#include <pthread.h>

// Game Logic
#include "Tests/GameLogicTest/DictionaryTest.hpp"
#include "gameLogic/Game.hpp"

// Sockets
#include "SocketComunication/serverSocket.hpp"

// JSON
#include "Tests/JsonTest/JSON_Test.hpp"
#include "JSON/PlayerMessage.hpp"

// gtest
#include <gtest/gtest.h>
#include <gmock/gmock.h>

serverSocket *server;

void * serverRun(void *)
{
    try{
        server->initSocket();
        server->runServer(4);
    }catch(string ex)
    {
        cout << ex;
    }

    pthread_exit(NULL);
}

void* writer(void *){
    while (1) {
        string mensaje;
        cin >> mensaje;
        if(mensaje == "EXIT") break;
        server->sendMessage(mensaje.c_str());
    }
    delete server;
}

void GameMock(){

     while(true){

     }

}

int main(int argc,char* argv[]) {

    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();

    server = new serverSocket;
    pthread_t hiloServer;
    pthread_create(&hiloServer,0,serverRun,NULL);
    pthread_detach(hiloServer);

    pthread_t hiloServer2;
    pthread_create(&hiloServer2,0,writer,NULL);
    pthread_detach(hiloServer2);


    while(!server->getClients()<4) {
        GameMock();
    }


    //return 0;
}

void serverSocket::messageHandler(string message) {
    cout<<":: "<<message<<endl;
}

     /*PlayerTest::test2();

    Game* g1 = new Game(2);
    cout<<"Code : "<<g1->getGameCode()<<endl;

    PlayerMessage* sms = new PlayerMessage();
    sms->setMessage("camaron",0,0,true);
    string json = sms->serialize();
    g1->recieveMessage(json);
    sms->setMessage("omedor",0,1,false);
    json = sms->serialize();
    g1->recieveMessage(json);*/





