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

public:

    //! @brief Class Constructor
    PlayerMessage();

    /* -------------------------------------------
     *              SERIALIZATION
     * -------------------------------------------*/

    //! @brief Configure message attributes
    //! \param [in]id : message identifier
    //! \param [in]answer :  true/false
    void setMessage1_(int id,bool answer);

    //! @brief Configure message attributes
    //! \param [in]id : message identifier
    //! @param [in]word : Player word
    //! @param [in]fRow : Row of the first LetterTile
    //! @param [in]fCol : Column of the first LetterTile
    void setMessage2_(int id,string word,int fRow,int fCol,bool vertical);

    //! @brief Configure message attributes
    //! \param [in]id : message identifier
    //! \param [in]pass : true if playar wanna pass his turn/false if player wants replay his movements.
    void setMessage3_(int id,bool pass);

    //! @brief Configure message attributes
    //! \param [in]id : message identifier
    //! @param [in]exp_request: boolean that indicates if player wants to use expert validation
    //! @param [in]word : Player word
    void setMessage4_(int id,bool exp_request,string word);

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
    const string &getWord() const {
        return word;
    }

    int getFirstRow() const {
        return firstRow;
    }

    int getFirstCol() const {
        return firstCol;
    }

    bool getIsVertical() const {
        return isVertical;
    }

    int getID() const{
        return id;
    }

    //! @brief Gives a way to visualize the message in the console
    //! @return
    string toString();
};


#endif //SCRABBLE_SERVERMESSAGE_HPP
