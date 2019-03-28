#ifndef PLAYER_HPP
#define PLAYER_HPP

// Libraries
#include "LetterTile.hpp"
#include "Board.hpp"

//! @brief
class Player{

private:

    LetterTile **playerDeck; //!< @brief
    Board* playerBoard; //!< @brief
    string myWord;

    int amountOfLetterTiles; //!< @brief
    int score; //!< @brief
    int *positions;

    //! @brief
    void initializePlayerDeck();

    //! @brief
    //! \param position
    //! \return
    LetterTile* playLetterTile(int position);

public:

    //! @brief
    Player();

    // --------------------------------------

    //! @brief
    //! @param letterTile
    void addLetterTile(LetterTile *letterTile);

    //! @brief
    //! @param position
    //! @param row
    //! @param col
    //! @return
    void addLetterToWord(int position,int row,int col);

    //! @brief
    void resetPositions();

    //! @brief
    bool sendMyWord();

    // ---------------------------------------

    //! @brief
    LetterTile** getPlayerDeck();

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

    //! @brief
    void printPositions();


};

#endif PLAYER_HPP
