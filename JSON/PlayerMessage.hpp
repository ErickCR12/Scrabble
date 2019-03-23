//
// Created by Esteban Alvarado on 20/03/19.
//

#ifndef SCRABBLE_PLAYERMESSAGE_HPP
#define SCRABBLE_PLAYERMESSAGE_HPP

// Libraries
#include <iostream>
#include "../lib/rapidjson/prettywriter.h"

using namespace std;

//! @brief Message class, responsible for sending the word selected
//! by the player to the server. This class serialized JSON and Parse to Player Massage.
class PlayerMessage {

private:
    string word;
    int firstRow;
    int firstCol;
    int lastRow;
    int lastCol;

    //! @brief Method responsible for serializing the object to JSON
    //! \tparam Writer
    //! \param writer
    template<typename Writer>
    void Serializer(Writer& writer) const;

public:

    //! @brief Class Constructor
    PlayerMessage();

    /* -------------------------------------------
     *              SERIALIZATION
     * -------------------------------------------*/

    //! @brief Configure message attributes
    //! @param [in]word : Player word
    //! @param [in]fRow : Row of the first LetterTile
    //! @param [in]fCol : Column of the first LetterTile
    //! @param [in]lRow : Row of the last LetterTile
    //! @param [in]lCol : Column of the last LetterTile
    void setMessage(string word,int fRow,int fCol, int lRow,int lCol);

    //! @brief Serializer Interface
    //! @return [out] :JSON of the object
    string serialize();

    /* -------------------------------------------
     *              DESERIALIZATION
     * -------------------------------------------*/

    //! @brief Parse JSON into PlayerMessage
    //! @param [in]json :JSON to Parse into an Object
    //! @return [out] :An instance of PlayerMessage
    PlayerMessage* deserealize(const char* json);

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

    int getLastRow() const {
        return lastRow;
    }

    int getLastCol() const {
        return lastCol;
    }

    //! @brief Gives a way to visualize the message in the console
    //! @return
    string toString();
};


#endif //SCRABBLE_PLAYERMESSAGE_HPP
