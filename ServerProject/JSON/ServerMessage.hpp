//
// Created by esteban on 20/03/19.
//

#ifndef SCRABBLE_SERVERMESSAGE_HPP
#define SCRABBLE_SERVERMESSAGE_HPP

// Libraries
#include <iostream>

using namespace std;

class ServerMessage {

    int id; // Indica el tipo de mensaje que se va a serializar

    string word;
    int firstRow;
    int firstCol;
    bool isVertical;

    bool answer;
    bool pass;
    bool exp_request;

    int points;
    string gameCode;
    string letterTiles;
    string msg;

    int currentPlayer;
    int winner;
    int your_Player;

    //! @brief Method responsible for serializing the object to JSON
    //! @note CONFIRM
    //! \tparam Writer
    //! \param writer
    template<typename Writer>
    void Serializer1_(Writer &writer) const;

    //! @brief Method responsible for serializing the object to JSON
    //! @note SEND WORD
    //! \tparam Writer
    //! \param writer
    template<typename Writer>
    void Serializer2_(Writer &writer) const;

    //! @brief Method responsible for serializing the object to JSON
    //! @note PASS/PLAY_AGAIN
    //! \tparam Writer
    //! \param writer
    template<typename Writer>
    void Serializer3_(Writer &writer) const;

    //! @brief Method responsible for serializing the object to JSON
    //! @note EXPERT_REQUEST
    //! \tparam Writer
    //! \param writer
    template<typename Writer>
    void Serializer4_(Writer &writer) const;

    //! @brief Method responsible for serializing the object to JSON
    //! @note EXPERT_REQUEST
    //! \tparam Writer
    //! \param writer
    template<typename Writer>
    void Serializer5_(Writer &writer) const;

public:

    //! @brief Class Constructor
    ServerMessage();

    /* -------------------------------------------
     *              SERIALIZATION
     * -------------------------------------------*/

    //!
    //! \param id
    //! \param gameCode
    //! \param msg
    void setMessage1_(int id,string gameCode,string msg);

    //!
    //! \param id
    //! \param tiles
    //! \param your_player
    void setMessage2_(int id,string tiles,int your_player);

    //!
    //! \param id
    //! \param accepted
    //! \param points
    void setMessage3_(int id,bool accepted,int points);

    //!
    //! \param id
    //! \param exp_request
    //! \param word
    void setMessage4_(int id,string word,int firstRow,int firstCol,bool isVertical);

    //!
    //! \param id
    //! \param exp_request
    //! \param word
    void setMessage5_(int id,int winner);

    //! @brief Serializer Interface
    //! @return [out] :JSON of the object
    string serialize();

    /* -------------------------------------------
     *              DESERIALIZATION
     * -------------------------------------------*/

    //! @brief Parse JSON into PlayerMessage
    //! @param [in]json :JSON to Parse into an Object
    //! @return [out] :An instance of PlayerMessage
    ServerMessage* deserealize(const char* json);

    /* -------------------------------------------
     *                  GETTERS
     * -------------------------------------------*/
    int getId() const;

    const string &getWord() const;

    int getFirstRow() const;

    int getFirstCol() const;

    bool isIsVertical() const;

    bool isAnswer() const;

    bool isPass() const;

    bool isExp_request() const;

    int getPoints() const;

    const string &getGameCode() const;

    const string &getLetterTiles() const;

    const string &getMsg() const;

    int getCurrentPlayer() const;

    int getWinner() const;

    int getYour_Player() const;

    //! @brief Gives a way to visualize the message in the console
    //! @return
    string toString();
};


#endif //SCRABBLE_SERVERMESSAGE_HPP
