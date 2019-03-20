#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Player.hpp"
int const totalLetterTiles = 7;

Player::Player() {
    initializePlayerDeck();
    score = 0;
    amountOfLetterTiles = 0;
}

void Player::initializePlayerDeck(){
    playerDeck = (LetterTile**) malloc(totalLetterTiles * sizeof(LetterTile*));
    for(int index = 0; index < totalLetterTiles; index++)
        playerDeck[index] = nullptr;
}

void Player::addLetterTile(LetterTile *letterTile) {
    int index = 0;
    while(playerDeck[index] != nullptr) index++;
    playerDeck[index] = letterTile;
    amountOfLetterTiles++;
}

LetterTile* Player::playLetterTile(int position){
    LetterTile *letterToPlay = playerDeck[position];
    playerDeck[position] = nullptr;
    return letterToPlay;
}

LetterTile** Player::getPlayerDeck(){
    return playerDeck;
}

int Player::getScore(){
    return score;
}

void Player::setScore(int score) {
    Player::score = score;
}

void Player::addScore(int scoreToAdd) {
    Player::score += scoreToAdd;
}

int Player::getAmountOfLetterTiles(){
    return amountOfLetterTiles;
}

void Player::printPlayerDeck() {
    LetterTile *tile;
    for(int index = 0; index < totalLetterTiles; index++){
        tile = playerDeck[index];
        cout << "[" << tile->getLetter() << ", " << tile->getAmountRemaining() << ", " << tile->getScore() << "] -> ";
    }cout << "NULL"<<endl;
}

#endif PLAYER_CPP