//
// Created by esteban on 20/03/19.
//

#include "socketTest1.hpp"


//socketServer *server; // Esta variable debe ser global... para el ejemplo

/*void* startServer(void *){
    try {
        server->runServer();
    }catch(string exception){
        cout << exception <<endl;
    }
    pthread_exit(nullptr);

}*/

/*
void socketTest(){

    server = new socketServer;

    pthread_t serverThread;
    pthread_create(&serverThread, 0, startServer, nullptr);
    pthread_detach(serverThread);

    while (true) {
        string message;
        cin >> message;
        server->sendMessage(message.c_str());
    }

}
*/