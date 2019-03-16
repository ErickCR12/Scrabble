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

    bool hasAvailableSpace();

    int getScore();

    void setScore(int score);
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
    for(int index = 0; index < totalLetterTiles; index++){
        if(playerDeck[index] == nullptr) {
            playerDeck[index] = letterTile;
            break;
        }
    }amountOfLetterTiles++;
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

#endif PLAYER_HPP
