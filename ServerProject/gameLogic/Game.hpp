//
// Created by Esteban Alvarado on 18/03/19.
//


/* NOTA ----------------------------------------------------------------------------
 {
    "letterTile": 'a,e,f,g,e,e,q', <-- Asi es como se enviarian las fichas al cliente
    arrayletras[0].jpg <-- esto se puede hacer!
 }

 */

#ifndef SCRABBLE_GAME_HPP
#define SCRABBLE_GAME_HPP

//Libraries
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "GameDeck.hpp"
#include "Dictionary.hpp"
#include "Board.hpp"
#include "../SocketComunication/serverSocket.hpp"
#include "../JSON/PlayerMessage.hpp"

using namespace std;

//! @brief Abstraction of a Scrabble game
class Game {

private:

    /* -------------------
     *  PRIVATE ATTRIBUTES
     * -------------------*/

    string gameCode; //!< Game code to connect whit current game
    int* playersID; //!< Array whit player ID
    int currentTurn; //!< Current player turn
    serverSocket gameSocket; //!< Socket of the game

    GameDeck* gameDeck; //!< game LetterTile deck
    Board* gameBoard; //!< game Board
    Dictionary* gameDictionary; //!< Reference to dictionary


    //! @brief Generates an Id Code for the game. Its necessary for
    //! players that wants join to this game
    //! \return [out]: Game ID code. Example: Q&my4Y
    string codeGenerator();

    //! @brief Main algorithm of the game. It is responsible for adding the words
    //! to the board, validating them, looking for possible combinations and
    //! returning their score.
    //! \param word [int]: Word to add
    //! \param row
    //! \param col
    //! \param isVertical [int]: bool flag that indicates if the added word is vertical
    //! \return [out] If word could be added.
    bool addWord(string word,int row,int col,bool isVertical);


public:

    //! @brief Constructor
    //! @param players Amount of players of the game
    //! @param gameSocket A pointer
    Game(int players, serverSocket *gameSocket);

    //! @brief Change the turn by PlayerID
    void nextTurn();

    void setupGame();

    void play();

    //! Receive the message from the clients.
    //! \return
    bool recieveMessage(string json);

    /* ----------------------
     *   GETTERS & SETTERS
     * ----------------------*/

    string getGameCode();

    //! @brief Returns the current Turn PlayerID
    int getCurrentTurn();


};


#endif //SCRABBLE_GAME_HPP
