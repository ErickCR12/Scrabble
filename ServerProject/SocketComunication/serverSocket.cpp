#include "serverSocket.hpp"

// Constructor
serverSocket::serverSocket() {
}

/* ----------------------------------------
 *          SOCKET HANDLE METHODS
 * ---------------------------------------*/

// An interface to create the socket and add clients
bool serverSocket::initSocket() {
    if(!createSocket()){
        cout<<"Error al crear el socket"<<endl;
        throw string("Error al crear el socket");
    }
    if (!connectWithClients()){
        cout<<"Error al conectar con el kernel"<<endl;
        throw string("Error al conectar con el kernel");
    }

    return true;
}

// Configure the port, IP address and protocols for the connection.
bool serverSocket::createSocket() {
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(descriptor < 0){
        return false;
    }

    socketInformation.sin_family = AF_INET;

    //Allows that any computer that knows the server ip connects to it
    socketInformation.sin_addr.s_addr = INADDR_ANY;

    //Indicates the server socket port. The htons only allows "small" socket ports. htonl for "big" socket port.
    socketInformation.sin_port = htons(9050);

    //Optional: clean the structure before connecting to the clients. IDK why
    memset(&socketInformation.sin_zero,0, sizeof(socketInformation.sin_zero));

    return true;
}

/* ----------------------------------------
 *          CLIENT HANDLE METHODS
 * ---------------------------------------*/

// Method that makes the acceptance of clients to the connection. He adds them to the customer vector.
bool serverSocket::connectWithClients() {
    if((bind(descriptor, (sockaddr *)&socketInformation , (socklen_t) sizeof(socketInformation))) <0){
        return false;
    }
    //The 4 is the number of clients that we are going to listen from the server
    listen(descriptor,4);
    return true;
}


// Listen to your connection (This method runs on a thread created by serverSocket :: run ())
// and receives the messages from the client through the input buffer.
// [ESTE METODO ES MEJOR REESCRIBIRLO]
void* serverSocket::clientController(void *object) {
    dataSocketServer *data = (dataSocketServer*)object;

    while (true) {
        string message;
        while (true) {
            char buffer[300] = {0};
            //Another "blocking function". The while stops until the server receives a new message.
            int bytes = recv(data->descriptor, buffer, 300, 0);
            message.append(buffer, bytes);

            if (bytes <= 0){
                close(data->descriptor);
                pthread_exit(NULL);
            }
            if (bytes < 300) {
                break;
            }
        }
        //cout<<message<<endl;
        messageHandler(message);
    }

    close(data->descriptor);
    terminate();
}


// Method that is responsible for sending messages to all connected clients.
void serverSocket::sendMessage(const char *message) {
    for (int i = 0; i < clients.size(); i++) {

        cout << "bytes enviados " << send(clients[i], message, strlen(message), 0)<<endl;
    }
}




// Run the socket on the Server
// Create a thread for the listening of each client. [REDIRECT TO serverSocket::clientController()]
void serverSocket::runServer(int n) {


    while (true){
        cout<<"Esperando Cliente!"<<endl;
        dataSocketServer data;
        socklen_t structureSize = sizeof(data.socketInformation);

        //A "blocking function" is declared. The while stops until the server receives a new client.
        data.descriptor = accept(descriptor,(sockaddr *)&data.socketInformation,
                                 &structureSize);

        if(data.descriptor < 0){
            cout<<"Error al aceptar al cliente"<<endl;
        }else {
            if (clients.size() < n) {
                clients.push_back(data.descriptor);
                cout<<"Clientes conectados: "<<clients.size()<<endl;
            } else {
                cout<<"Juego lleno! Intenta crear tu propio juego!"<<endl;
            }

            // An inicial message for each client that try to connect
            //sendMessage("Te has unido al chat!");

            // [ES] Esta parte del codigo crea hilos para la interaccion
            //      del server con los clientes
            thread clientThread(&serverSocket::clientController,this,(void*) &data);  // Crea el Thread
            clientThread.detach(); // Pone a correr el Thread de manera independiente (Daemon)
        }
    }
    close(descriptor);
}

