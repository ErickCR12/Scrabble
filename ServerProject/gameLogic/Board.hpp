//
// Created by Esteban Alvarado on 15/03/19.
//

#ifndef SCRABBLE_BOARD_HPP
#define SCRABBLE_BOARD_HPP

// Libraries
#include "LetterTile.hpp"
#include "GameDeck.hpp"
#include "gtest/gtest.h"

//! @brief
class Board {

private:

    LetterTile *(*gameBoard)[15]; //!< @brief
    int (*scoreBoard)[15]; //! @brief
    string scorePath;

    //! @brief
    void initGameBoard();

    //! @brief
    void initScoreBoard();

public:

    //! @brief
    Board();

    //! @brief
    void printGameBoard();

    //! @brief
    void printScoreBoard();

    //! @brief
    //! @param row
    //! @param col
    void addLetterTile(int row, int col, LetterTile *newTile);

    //! @brief
    //! @param row
    //! @param col
    //! @return
    LetterTile *getLetterTile(int row, int col);

    //! @brief
    //! @param row
    //! @param col
    //! @return
    int getScore(int row, int col);
};

#endif SCRABBLE_BOARD_HPP
