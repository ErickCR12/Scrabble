
// Libraries
#include <iostream>
#include <pthread.h>

// Game Logic
#include "gameLogic/Server.hpp"

// gtest
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc,char* argv[]) {

    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();

    // Se crea un servidor
    Server* server1_ = new Server();

    /* ------------------------------------------------------
     *              ESTRUCTURA DE EJECUCION
     *
     * 1. Se crea un nuevo juego
     * 2. Se agregan los clientes
     * 3. Se ejecuta la funcion Game::play() dentro de un hilo
     * ------------------------------------------------------*/
    server1_->new_game();
    thread t(&Server::launch_game,server1_);
    t.join();

    return 0;
}


/*------------------------------------------------
 *                  END OF CODE ZONE
 * -----------------------------------------------*/
