//
// Created by esteban on 07/04/19.
//

#ifndef SCRABBLE_EXPERT_HPP
#define SCRABBLE_EXPERT_HPP

// Libraries
#include <iostream>

using namespace std;

//! Class word Expert, is a player that can validate and add
class Expert {
public:
    //! Constructor
    Expert();

    //! Send an SMS to the expert of the game
    //! \param [in]word: Word to validate
    void sendMessage(string word);

    //! Send a Request to the expert app to know if the word is approved
    //! \return [out]: if the word is accepted or not
    bool getResponse();
};


#endif //SCRABBLE_EXPERT_HPP
