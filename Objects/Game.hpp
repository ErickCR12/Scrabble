//
// Created by esteban on 14/03/19.
//

#ifndef SCRABBLE_GAME_HPP
#define SCRABBLE_GAME_HPP

#include "ServerBoard.hpp"
#include "../DataStructures/CircularList.hpp"

class Game{

private:
  Board* board = new Board();
  CircularList **Players;

public:

  Game(); // Esta instancia es creada por el Game Handler --- Sockets

  void addPlayer();

};

#endif //SCRABBLE_GAME_HPP
