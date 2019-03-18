#include "socketClient.h"

socketClient::socketClient() {

}

bool socketClient::connectToServer() {
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(descriptor < 0){
        return false;
    }

    socketInformation.sin_family = AF_INET;

    //Allows that any computer that knows the server ip connects to it
    socketInformation.sin_addr.s_addr = INADDR_ANY;

    //Indicates the server socket port. The htons only allows "small" socket ports. htonl for "big" socket port.
    socketInformation.sin_port = ntohs(4050);

    //Optional: clean the structure before connecting to the clients. IDK why
    memset(&socketInformation.sin_zero,0, sizeof(socketInformation.sin_zero));

    if(connect(descriptor,(sockaddr*)&socketInformation , (socklen_t) sizeof(socketInformation)) <0){
        return false;
    }

    pthread_t threadClient;
    pthread_create(&threadClient,0,socketClient::controller,(void *)this);
    pthread_detach(threadClient);

    return true;

}

void* socketClient::controller(void *object) {
    socketClient *connection = (socketClient*) object;

    while (true) {
        string message;
        while (true) {
            char buffer[10] = {0};
            //Another "blocking function". The while stops until the server receives a new message.
            int bytes = recv(connection->descriptor, buffer, 10, 0);
            message.append(buffer, bytes);

            if (bytes <= 0){
                close(connection->descriptor);
                pthread_exit(NULL);
            }
            if (bytes < 10) {
                break;
            }

        }
        cout <<message <<endl;
    }
    //close(connection->descriptor);
    //pthread_exit(NULL);
}


void socketClient::sendMessage(const char *message) {
    cout<<"bytes enviados "<< send(descriptor,message,strlen(message),0)<<endl;

}