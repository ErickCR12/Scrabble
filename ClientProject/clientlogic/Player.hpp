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

    //! @brief Player class constructor
    Player();

    // --------------------------------------

    //! @brief Adds the letters in the string received as a parameter to playerDeck vector attribute
    //! @param string: letters to add to vector separated by commas
    void addLettersToPlayerDeck(string letters);

    //! @brief adds the tile in position to my word, in the row and column specified
    //! @param position: position in playerDeck of tile to add
    //! @param row where to add letter
    //! @param col where to add letter
    void addLetterToWord(int position,int row,int col);

    //! @brief resets the positions array.
    void resetPositions();

    //! \brief sendMyWord function creates a JSON to send the word created.
    //! \param word: created word to send
    //! \param firstRow: first row position of letter
    //! \param firstColumn: first column position of letter
    //! \param isVertical: indicates if the word is vertical or horizontal
    //! \return returns string in JSON format
    string sendMyWord(string word, int firstRow, int firstColumn, bool isVertical);

    // ---------------------------------------

    //! @brief getter for playerDeck attribute
    vector<string> getPlayerDeck();

    //! @brief getter for score attribute
    int getScore();

    //! @brief setter for score attribute
    //! @param score
    void setScore(int score);

    //! @brief adds the integer received to the actual score attribute
    void addScore(int scoreToAdd);

    //! @brief getter for amountOfLetterTiles attribute
    int getAmountOfLetterTiles();
    //! \brief setter for amountOfLetterTiles attribute
    void setAmountOfLetterTiles(int amount);
    //! \brief setterfor playerName attribute
    void setPlayerName(string name);
    //! \brief getter for playerName attribute
    string getPlayerName();
    //! \brief getter for board attribute
    Board* getBoard();

    //! \brief getter for widgetsPlayerDeck attribute
    vector<DraggableTile*> getWidgetsPlayerDeck();
    //! \brief add a new DraggableTile to the widgetsPlayerDeck attribute
    void addWidgetToDeck(DraggableTile* tile);
    //! \brief cleans the playerDeck vector attribute
    void resetPlayerDeck();
    //! \brief cleans the widgetDeck vector attribute
    void resetWidgetsDeck();

//    //! @brief
    void printPlayerDeck();

    //! @brief
    void printPositions();


};

#endif // PLAYER_HPP
