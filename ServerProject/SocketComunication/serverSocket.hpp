#ifndef COMUNICATIONTEST_SOCKETSERVER_H
#define COMUNICATIONTEST_SOCKETSERVER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <thread>
#include <vector>
#include <unistd.h>


using namespace std;

struct dataSocketServer{
    int descriptor;
    sockaddr_in socketInformation;
};

//! @brief
class serverSocket {

public:
    //! @brief Constructor
    serverSocket();

    //! @brief Is an interface that calls createSocket() and connectWithClients()
    bool initSocket();

    //! @brief Run the socket on the Server
    //! Create a thread for the listening of each client. [REDIRECT TO socketServer::clientController()]
    //! @param n[in]: Maximun amount of clients that socket can manage
    void runServer(int n);

    void messageHandler(string message);

    //! @brief Method that is responsible for sending messages to all connected clients.
    //! \param message [in]: Messages that the server must send to clients
    void sendMessage(const char *message);

    int getClients(){
        return clients.size();
    }

private:

    int descriptor; //!< Attribute that the system returns when a new socket port is assigned
    sockaddr_in socketInformation; //!< Information of the socket type and the type of connection made with the other socket port (clients)
    vector<int> clients; //!< Vector that stores all the descriptors that are connected to this socket.
    vector<thread> cThreads; // La uso para correr los procesos

    /* ------------------------------------
     *      SOCKET PUBLIC METHODS
     * -----------------------------------*/

    //! Configure the port, IP address and protocols for the connection.
    //! \return [out]: A bool that indicates if socket was created.
    bool createSocket();

    //! Method that makes the acceptance of clients to the connection. He adds them to the customer vector.
    //! \return [out]: A bool that indicates if a new client could connect.
    bool connectWithClients();

    //! Listen to your connection (This method runs on a thread created by socketServer :: run ())
    //! and receives the messages from the client through the input buffer.
    //! \param object [in]: socket of that specific connection
    //! \return [out]: void
    void* clientController(void *object);
};



#endif //COMUNICATIONTEST_SOCKETSERVER_H
