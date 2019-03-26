//
// Created by Esteban Alvarado on 18/03/19.
//

#ifndef SCRABBLE_GAME_HPP
#define SCRABBLE_GAME_HPP

//Libraries
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "GameDeck.hpp"
#include "Dictionary.hpp"
#include "Board.hpp"
#include "../JSON/PlayerMessage.hpp"

using namespace std;

//! @brief
class Game {
private:

    string gameCode; //!< Game code to connect whit current game
    int* players; //!< Array whit player ID
    int currentTurn; //!< Current player turn

    /*
     {
        "letterTile": 'a-e-f-g-e-e-q',
        arrayletras[0].jpg <-- esto se puede hacer!
     }

     */

    GameDeck* gameDeck; //!< game LetterTile deck
    Board* gameBoard; //!< game Board
    Dictionary* gameDictionary; //!< Reference to dictionary

    //! @brief
    //! \return
    string codeGenerator();

    //! @brief
    //! \param word
    //! \param row
    //! \param col
    //! \param isVertical
    //! \return
    bool addWord(string word,int row,int col,bool isVertical);

public:

    //! @brief
    //! @param players
    //! @param code
    Game(int players);

    //! @brief
    void nextTurn();

    //! @brief
    int getCurrentTurn();

    //!
    //! \return
    bool recieveMessage(string json);

    //!
    //! \return
    string getGameCode();

};


#endif //SCRABBLE_GAME_HPP
