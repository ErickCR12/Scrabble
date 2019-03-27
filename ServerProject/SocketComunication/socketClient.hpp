#ifndef COMUNICATIONTEST_SOCKETCLIENT_H
#define COMUNICATIONTEST_SOCKETCLIENT_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

class socketClient {
public:
    socketClient();
    bool connectToServer();

    void newMessage(string message);

    void sendMessage(const char *message);


private:
    //Attribute that the system returns when a new socket port is assigned
    int descriptor;

    //Information of the socket type and the type of connection made with the other socket port (clients)
    sockaddr_in socketInformation;

    static void *controller(void *object);

};


#endif //COMUNICATIONTEST_SOCKETCLIENT_H
