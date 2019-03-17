#ifndef PLAYER_HPP
#define PLAYER_HPP

// Libraries
#include "LetterTile.hpp"

//! @brief
class Player{

private:
    LetterTile **playerDeck; //!< @brief
    int amountOfLetterTiles; //!< @brief
    int score; //!< @brief

public:

    //! @brief
    Player();

    //! @brief
    //! @param letterTile
    void addLetterTile(LetterTile *letterTile);

    //! @brief
    void initializePlayerDeck();

    //! @brief
    LetterTile** getPlayerDeck();

    //! @brief
    LetterTile* playLetterTile(int position);

    //! @brief
    int getScore();

    //! @brief
    //! @param score
    void setScore(int score);

    //! @brief
    //! @param scoreToAdd
    void addScore(int scoreToAdd);

    //! @brief
    int getAmountOfLetterTiles();

    //! @brief
    void printPlayerDeck();
};

#endif PLAYER_HPP
