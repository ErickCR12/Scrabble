#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
// Libraries
#include "json/PlayerMessage.hpp"
#include <vector>
#include <boost/algorithm/string.hpp>
#include "Board.hpp"
#include "gui/DraggableTile.h"

using namespace std;
//! @brief
class Player{

private:

    vector<DraggableTile*> widgetsPlayerDeck;
    vector<string> playerDeck; //!< @brief
    Board* playerBoard; //!< @brief
    string myWord;
    string playerName;

    int amountOfLetters; //!< @brief
    int score; //!< @brief
    int *positions;

    //! @brief
    void initializePlayerDeck();

    //! @brief
    //! \param position
    //! \return
    string playLetter(int position);

public:

    //! @brief
    Player();

    // --------------------------------------

    //! @brief
    //! @param letterTile
    void addLettersToPlayerDeck(string letters);

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
    vector<string> getPlayerDeck();

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
    void setAmountOfLetterTiles(int amount);

    void setPlayerName(string name);

    string getPlayerName();

    Board* getBoard();

    vector<DraggableTile*> getWidgetsPlayerDeck();

    void addWidgetToDeck(DraggableTile* tile);
    void resetPlayerDeck();
    void resetWidgetsDeck();

//    //! @brief
    void printPlayerDeck();

    //! @brief
    void printPositions();


};

#endif PLAYER_HPP
