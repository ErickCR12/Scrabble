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
#include "../SocketComunication/server_Socket.hpp"
#include "../JSON/PlayerMessage.hpp"
#include "../JSON/ServerMessage.hpp"
#include <thread>

using namespace std;

//! @brief Abstraction of a Scrabble game
class Game:server_Socket{

private:

    /* -------------------
     *  PRIVATE ATTRIBUTES
     * -------------------*/

    string gameCode; //!< Game code to connect whit current game
    int* playersID; //!< Array whit player ID
    int currentTurn; //!< Current player turn

    GameDeck* gameDeck; //!< game LetterTile deck
    Board* gameBoard; //!< game Board
    Dictionary* gameDictionary; //!< Reference to dictionary


    /* -------------------
     *   PRIVATE METHODS
     * -------------------*/

    //! @brief Generates an Id Code for the game. Its necessary for
    //! players that wants join to this game
    //! \return [out]: Game ID code. Example: Q&my4Y
    string codeGenerator();

    //! Receive the message from the clients.
    //! \return
    //bool recieveMessage(string json);
    bool recieveMessage(string json);

    //! @brief Main algorithm of the game. It is responsible for adding the words
    //! to the board, validating them, looking for possible combinations and
    //! returning their score.
    //! \param word [int]: Word to add
    //! \param row
    //! \param col
    //! \param isVertical [int]: bool flag that indicates if the added word is vertical
    //! \return [out] If word could be added.
    int addWord(vector<string> word,int row,int col,bool isVertical);

    //! Function that is responsible for executing the Word Finder algorithm,
    //! for the search of simple or compound words.
    //! \param word
    //! \param row
    //! \param col
    //! \param isVertical
    //! \return
    bool validateWord(string word, int row, int col, bool isVertical);

    //! Check if there are any words composed in the column of the word entered.
    //! \param word
    //! \param row
    //! \param col
    //! \param isVertical
    //! \return
    string verticalIterator(string word,int len, int row, int col,bool isVertical);

    //! Check if there are any words composed in the row of the word entered.
    //! \param word
    //! \param row
    //! \param col
    //! \param isVertical
    //! \return
    string horizontalIterator(string word,int len, int row, int col,bool isVertical);

    //! Send the tiles to the players
    void send_LetterTiles();

    //! @brief Change the turn by PlayerID
    void nextTurn(){
        if(currentTurn<getMaxCap()) currentTurn++;
        else currentTurn=0;
    }


    //! Resets the Board if word isnt accepted
    //! \param position vector with recent positions added
    void resetBoard(int word_len,int row,int col,bool vertical);

public:


    /* -------------------
     *  PUBLIC METHODS
     * -------------------*/

    //! @brief Constructor
    //! @param players Amount of players of the game
    //! @param gameSocket A pointer
    Game();

    /* -------------------
     *  SOCKET FUNCTIONS
     * -------------------*/

    //! Function responsible for adding the n players to the game
    void add_players();

    //! Initialize the listening threads of each client and once achieved, start the game.
    void start_game();

    //! Is responsible for managing what is done with the message received from the client
    //! \param msg[in]: Message sended by the client
    void msgHandler(const char* msg) override;

    /* -------------------
     *    GAME FUNCTIONS
     * -------------------*/

    //! Function that keeps the game active as long as the amount
    //! of LetterTiles is greater than zero
    void play();

    string dealTiles(int amount);


    /* ----------------------
     *   GETTERS & SETTERS
     * ----------------------*/

    //! Getter of gameCode attribute
    //! \return [out]: A game code to join him.
    string getGameCode();

    //! @brief Returns the current Turn PlayerID
    int getCurrentTurn();

};

#endif //SCRABBLE_GAME_HPP
