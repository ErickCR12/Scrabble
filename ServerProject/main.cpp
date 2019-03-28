
// Libraries
#include <iostream>
#include <pthread.h>

// Game Logic
#include "Tests/GameLogicTest/DictionaryTest.hpp"
#include "gameLogic/Game.hpp"

// Sockets
//#include "SocketComunication/serverSocket.hpp"
#include "SocketComunication/server_Socket.hpp"

// JSON
#include "Tests/JsonTest/JSON_Test.hpp"
#include "JSON/PlayerMessage.hpp"

// gtest
#include <gtest/gtest.h>
#include <gmock/gmock.h>

server_Socket *server;

void * serverRun(void *)
{
    try{
        server->initSocket();
        server->addFirstClient();
        while(server->getClientsAmt()<4) server->addClients();
        server->runServer();
    }catch(string ex)
    {
        cout << ex;
    }

    pthread_exit(NULL);
}


int main(int argc,char* argv[]) {

    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();

    server = new server_Socket();
    pthread_t hiloServer;
    pthread_create(&hiloServer,0,serverRun,NULL);
    pthread_detach(hiloServer);

    while (1) {
        string mensaje;
        cin >> mensaje;
        if(mensaje == "EXIT") break;
        server->sendMessagetoAll(mensaje.c_str());
    }
    delete server;

    return 0;
}

void server_Socket::msgHandler(const char* message) {
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





