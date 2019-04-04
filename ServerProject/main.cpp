
// Libraries
#include <iostream>
#include <pthread.h>

// Game Logic
#include "Tests/GameLogicTest/DictionaryTest.hpp"
#include "gameLogic/Server.hpp"
#include "gameLogic/Game.hpp"

// JSON
#include "Tests/JsonTest/JSON_Test.hpp"
#include "JSON/PlayerMessage.hpp"

// gtest
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc,char* argv[]) {

    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();

    // Se crea un servidor
    Server* server1_ = new Server();

    /*      ESTRUCTURA DE EJECUCION
     * 1. Se crea un nuevo juego
     * 2. Se agregan los clientes
     * 3. Se ejecuta la funcion Game::play() dentro de un hilo
     */
    server1_->new_game();
    thread t(&Server::launch_game,server1_);
    t.join();

    return 0;
}


/*------------------------------------------------
 *                  DEEP CODE ZONE
 * -----------------------------------------------*/

/* server = new server_Socket();
    pthread_t hiloServer;
    pthread_create(&hiloServer,0,serverRun,NULL);
    pthread_detach(hiloServer);

    while (1) {
        string mensaje;
        cin >> mensaje;
        if(mensaje == "EXIT") break;
        server->sendMessagetoAll(mensaje.c_str());
    }
    delete server;*/


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





