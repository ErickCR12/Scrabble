#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../DataStructures/List.hpp"
#include "LetterTile.hpp"

class Player{
private:
    LetterTile **playerDeck;
    int amountOfLetterTiles;
    int score;

public:

    Player();

    void addLetterTile(LetterTile *letterTile);

    void initializePlayerDeck();

    LetterTile** getPlayerDeck();

    LetterTile* playLetterTile(int position);

    int getScore();

    void setScore(int score);

    void addScore(int scoreToAdd);

    int getAmountOfLetterTiles();
};

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

#endif PLAYER_HPP
