//
// Created by Esteban Alvarado on 18/03/19.
//

#ifndef SCRABBLE_GAME_HPP
#define SCRABBLE_GAME_HPP

//Libraries
#include "GameDeck.hpp"
#include "Dictionary.hpp"
#include "Board.hpp"

using namespace std;

//! @brief
class Game {
private:

    string gameCode; //!<
    int* players; //!<
    int currentTurn; //!<

    GameDeck* gameDeck; //!<
    Board* gameBoard; //!<
    Dictionary* gameDictionary; //!<

public:

    //! @brief
    //! @param players
    //! @param code
    Game(int players,string code);

    //! @brief
    void nextTurn();

    //! @brief
    int getCurrentTurn();

    bool addWord(LetterTile**  );

};


#endif //SCRABBLE_GAME_HPP
