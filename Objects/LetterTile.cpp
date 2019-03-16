#ifndef LETTERTILE_CPP
#define LETTERTILE_CPP

#include "LetterTile.hpp"

LetterTile::LetterTile(string letter, int amountRemaining, int score){
this->letter = letter;
this->amountRemaining = amountRemaining;
this->score = score;
}


string LetterTile::getLetter(){
    return letter;
}

int LetterTile::getAmountRemaining(){
    return amountRemaining;
}

void LetterTile::decreaseAmountRemaining(){
    amountRemaining--;
}

int LetterTile::getScore(){
    return score;
}

void LetterTile::toString(){
    cout<<this->letter;
}

#endif LETTERTILE_CPP