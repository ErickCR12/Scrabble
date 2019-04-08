
// Libraries
#include <iostream>
#include <pthread.h>

// Game Logic
#include "gameLogic/Server.hpp"
#include "gameLogic/Game.hpp"

// gtest
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>

int server_release();

using namespace std;

int main(int argc,char* argv[]) {

    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();



    //Esta línea es la que envía el SMS al teléfono de @OscarAraya18
    //El archivo .py se encuente en el directorio cmake-build-debug


    const char* requestedWord = "Assfsd";
    const char* defaultMessage = "python sendSms.py ";

    string completeMessage = defaultMessage;
    completeMessage += requestedWord;

    const char* sendCommand = completeMessage.c_str();

    //system(sendCommand);


    server_release();

    return 0;
}

int server_release(){

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

// {"id":2,"word":"perro","firstRow":0,"firstCol":0,"is_Vertical":true}

/*Game *game = new Game();

    string JSON = "{\"id\":2,\"word\":\"perro\",\"firstRow\":0,\"firstCol\":0,\"is_Vertical\":false}";

    game->recieveMessage(JSON);

    JSON =  "{\"id\":2,\"word\":\"ceano\",\"firstRow\":1,\"firstCol\":4,\"is_Vertical\":true}";
    game->recieveMessage(JSON);

    JSON =  "{\"id\":2,\"word\":\"scuela\",\"firstRow\":2,\"firstCol\":5,\"is_Vertical\":false}";
    game->recieveMessage(JSON);

    JSON =  "{\"id\":2,\"word\":\"buela\",\"firstRow\":3,\"firstCol\":10,\"is_Vertical\":true}";
    game->recieveMessage(JSON);*/