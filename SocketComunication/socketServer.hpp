#ifndef COMUNICATIONTEST_SOCKETSERVER_H
#define COMUNICATIONTEST_SOCKETSERVER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>


using namespace std;

struct dataSocketServer{
    int descriptor;
    sockaddr_in socketInformation;
};


class socketServer {
public:
    socketServer();
    void runServer();
    void sendMessage(const char *message);
private:
    //Attribute that the system returns when a new socket port is assigned
    int descriptor;

    //Information of the socket type and the type of connection made with the other socket port (clients)
    sockaddr_in socketInformation;

    bool createSocket();
    bool connectWithClients();

    static void *clientController(void *object);

    vector<int> clients;
};


#endif //COMUNICATIONTEST_SOCKETSERVER_H
