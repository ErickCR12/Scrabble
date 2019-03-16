#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../DataStructures/List.hpp"

class Player{
private:
    List *playerDeck;
    int score;

public:

    Player();

    List *getPlayerDeck();

    void setPlayerDeck(List *playerDeck);

    int getScore();

    void setScore(int score);
};

List *Player::getPlayerDeck(){
    return playerDeck;
}

void Player::setPlayerDeck(List *playerDeck) {
    Player::playerDeck = playerDeck;
}

int Player::getScore(){
    return score;
}

void Player::setScore(int score) {
    Player::score = score;
}

#endif PLAYER_HPP
