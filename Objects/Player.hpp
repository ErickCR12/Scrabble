#ifndef PLAYER_HPP
#define PLAYER_HPP

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

#endif PLAYER_HPP
