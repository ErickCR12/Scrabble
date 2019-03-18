#include "socketServer.h"
#include "socketClient.h"


socketServer *server;

void * startServer(void *){
    try {
        server->runServer();
    }catch(string exception){
        cout << exception <<endl;
    }
    pthread_exit(NULL);

}

int main(int argc, char const *arg[]) {
    server = new socketServer;

    pthread_t serverThread;
    pthread_create(&serverThread, 0, startServer, NULL);
    pthread_detach(serverThread);

    while (true) {
        string message;
        cin >> message;
        server->sendMessage(message.c_str());
    }
    //delete server;
    //return 0;
}
