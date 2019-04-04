#ifndef SCRABBLE_SERVER_HPP
#define SCRABBLE_SERVER_HPP

// Libraries
#include "../SocketComunication/server_Socket.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Server {

private:

   //Game* gm; //!< Instance of a game
   vector<Game*> matches;

public:

    //! Constructor
    Server();

    //! Creates a new game instance
    void new_game();

    //! Add clients to a game
    void launch_game();

};


#endif //SCRABBLE_SERVER_HPP
