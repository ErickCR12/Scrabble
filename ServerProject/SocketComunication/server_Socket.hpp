//
// Created by esteban on 28/03/19.
//

#ifndef SCRABBLE_SERVER_SOCKET_HPP
#define SCRABBLE_SERVER_SOCKET_HPP

// Libraries
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <thread> // This library is chosen for its simplicity (Although using pthread is not bad)
#include <vector>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;


struct dataSocketServer{
    int descriptor;
    sockaddr_in socketInfo;
};

#define PORT 9050

//! Socket class. It is responsible for managing the communication on the server side.
class server_Socket {

private:

    int descriptor; //!< Attribute that the system returns when a new socket port is assigned
    sockaddr_in socketInfo; //!< Information of the socket type and the type of connection made with the other socket port (clients)
    vector<int> clients; //!< Vector that stores all the descriptors that are connected to this socket.
    vector<dataSocketServer> cThreads; // vector that contains dataSocketServer. It is used to create the listenClient threads of each client.

    string code; //!< It indicades the code of the game
    int max_cap; //!< Maximun amount of clients
    int port; //!< port of this connection

    /* ------------------------------------
     *
     *      SOCKET PRIVATE METHODS
     *
     * -----------------------------------*/

    //! Configure the port, IP address and protocols for the connection.
    //! \return [out]: A bool that indicates if socket was created.
    bool createSocket();

    //! Method that makes the acceptance of clients to the connection. He adds them to the customer vector.
    //! \return [out]: A bool that indicates if a new client could connect.
    bool connectWithClients();

    //! Method that handles a listening loop to the client for receiving messages
    void listenClient(string* bufferText,dataSocketServer data);

    //! Create a thread for each client and listen to it separately
    void runThreads();

    //! Listen to your connection (This method runs on a thread created by socketServer :: run ())
    //! and receives the messages from the client through the input buffer.
    //! \param object [in]: socket of that specific connection
    //! \return [out]: void
    void* clientHandler(void* object);

public:

    /* ------------------------------------
    *
    *        SOCKET PUBLIC METHODS
    *
    * -----------------------------------*/

    //! @brief Constructor
    server_Socket();

    //! @brief Is an interface that calls createSocket() and connectWithClients()
    bool initSocket(int port = PORT);

    //! Add the first customer. No need for game code
    void addFirstClient();

    //! Add the other clients to the game (To the limit).
    //! @note REQUIRES GAME CODE
    void addClients();

    //! @brief Run the socket on the Server
    //! Create a thread for the listening of each client. [REDIRECT TO socketServer::clientController()]
    //! @param n[in]: Maximun amount of clients that socket can manage
    void runServer();

    //! @note This class must be implemented according to the needs of the developer
    //! @brief Its purpose is to work with the message received from the client.
    //! \param msg
    virtual void msgHandler(const char* msg);

    void setMaxCap(string info);

    int getMaxCap(){
        return max_cap;
    }

    //! @brief Method that is responsible for sending messages to all connected clients.
    //! \param message [in]: Messages that the server must send to clients
    void sendMessagetoAll(string msg);

    //! Send a message to a specific customer
    void sendSingleMessage(const char* msg,int descriptor);

    int getClientsAmt(){
        return cThreads.size();
    }

    void setCode(string code){
        this->code = code;
    }

    int getClient(int index){
        return clients[index];
    }

    void closeSocket(){
        close(descriptor);
        cout<<">> CERRANDO CONEXION...\n>> SOCKET TERMINADO"<<endl;
    }

};


#endif //SCRABBLE_SERVER_SOCKET_HPP
