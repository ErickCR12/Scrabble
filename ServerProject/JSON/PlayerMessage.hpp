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
    int id; // Indica el tipo de mensaje que se va a serializar
    string word;
    int firstRow;
    int firstCol;
    bool isVertical;

    //! @brief Method responsible for serializing the object to JSON
    //! \tparam Writer
    //! \param writer
    template<typename Writer>
    void Serializer1_(Writer &writer) const;

    //! @brief Method responsible for serializing the object to JSON
    //! \tparam Writer
    //! \param writer
    template<typename Writer>
    void Serializer2_(Writer &writer) const;

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
    void setMessage1_(int id,string word,int fRow,int fCol,bool vertical);
    void setMessage2_(int id,string word,int fRow,int fCol,bool vertical);

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


#endif //SCRABBLE_PLAYERMESSAGE_HPP
