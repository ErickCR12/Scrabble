#include "LetterTile.hpp"
#include <iostream>
using namespace std;

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
    std::cout<<this->letter;
}