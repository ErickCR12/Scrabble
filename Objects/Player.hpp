//
// Created by esteban on 13/03/19.
//

#ifndef SCRABBLE_PLAYER_HPP
#define SCRABBLE_PLAYER_HPP

#include <fstream>

class playerDeck; //Debo crear esta clase

class Player{
private:

  string name;
  int playerScore;
  playerDeck* myDeck; // Esto es un array de tamaño 7
  // Debe haber una lista que lleve las fichas que se colocan

public:

  Player(string name){
    this->name = name;
  }

  int getPlayerScore();

  void setPlayerScore(int newScore);

  void selectTile(); // Este metodo es un poco abstracto y aun no he definido bien que es lo que exactamente va a hacer.
  
}
#endif //SCRABBLE_PLAYER_HPP
