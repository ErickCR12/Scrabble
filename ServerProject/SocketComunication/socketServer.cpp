#include "socketServer.hpp"

// Constructor
socketServer::socketServer() {
}

/* ----------------------------------------
 *          SOCKET HANDLE METHODS
 * ---------------------------------------*/

// Configure the port, IP address and protocols for the connection.
bool socketServer::createSocket() {
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(descriptor < 0){
        return false;
    }

    socketInformation.sin_family = AF_INET;

    //Allows that any computer that knows the server ip connects to it
    socketInformation.sin_addr.s_addr = INADDR_ANY;

    //Indicates the server socket port. The htons only allows "small" socket ports. htonl for "big" socket port.
    socketInformation.sin_port = htons(4050);

    //Optional: clean the structure before connecting to the clients. IDK why
    memset(&socketInformation.sin_zero,0, sizeof(socketInformation.sin_zero));

    return true;
}

/* ----------------------------------------
 *          CLIENT HANDLE METHODS
 * ---------------------------------------*/

// Method that makes the acceptance of clients to the connection. He adds them to the customer vector.
bool socketServer::connectWithClients() {
    if((bind(descriptor, (sockaddr *)&socketInformation , (socklen_t) sizeof(socketInformation))) <0){
        return false;
    }
    //The 4 is the number of clients that we are going to listen from the server
    listen(descriptor,4);
    return true;
}


// Listen to your connection (This method runs on a thread created by socketServer :: run ())
// and receives the messages from the client through the input buffer.
void* socketServer::clientController(void *object) {
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
        cout<<message<<endl;
    }

    close(data->descriptor);
    pthread_exit(NULL);
}


// Method that is responsible for sending messages to all connected clients.
void socketServer::sendMessage(const char *message) {
    for (int i = 0; i < clients.size(); i++) {

        cout << "bytes enviados " << send(clients[i], message, strlen(message), 0);
    }
}

// Run the socket on the Server
// Create a thread for the listening of each client. [REDIRECT TO socketServer::clientController()]
void socketServer::runServer() {
    cout<<"Exc"<<endl;
    if(!createSocket()){
        cout<<"Error al crear el socket"<<endl;
        throw string("Error al crear el socket");
    }
    if (!connectWithClients()){
        cout<<"Error al conectar con el kernel"<<endl;
        throw string("Error al conectar con el kernel");
    }

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
            clients.push_back(data.descriptor);

            // An inicial message for each client that try to connect
            //sendMessage("Te has unido al chat!");

            // [ES] Esta parte del codigo crea hilos para la interaccion
            //      del server con los clientes.
            pthread_t thread;
            pthread_create(&thread,0,socketServer::clientController, (void *) &data);  // Crea el Thread
            pthread_detach(thread); // Pone a correr el Thread de manera independiente (Daemon)

        }
    }
    close(descriptor);
}
