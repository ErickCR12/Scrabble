//
// Created by esteban on 13/03/19.
//

#ifndef SCRABBLE_SERVERBOARD_HPP
#define SCRABBLE_SERVERBOARD_HPP

#include "LetterTile.hpp"
#include "Dictionary.hpp"
#include <fstream>

/// @brief Tablero principal del juego manejado por el Servidor
class Board{

private:

  LetterTile **gameBoard;
  int scoreBoard;
  string **gameWords; // Una matriz que lleva cuales palabras ya 
  //estan en el board [ESTO SE PUEDE ELIMINAR SI SE DETERMINA QUE NO ES UTIL]

  // Inicializa la matriz de fichas
  void initBoard();

  // Inicializa la matriz de puntajes, lee el archivo txt
  void initScoreBoards();

  // Método que se comunica con
  bool checkWord(string word){
    return Dictionary::searchInDictionary(word);
  };

  // Este metodo no se exactamente como manejarlo...
  void addWord();

public:

  Board();

  // Retorna el puntaje de una posición de la matriz
  int getScore(row,col);

  // "Añade" una ficha en el tablero
  void addTile();

  // Se encarga de brindar los cambios que fueron hechos en un turno
  void updateBoard();
};

#endif //SCRABBLE_SERVERBOARD_HPP
