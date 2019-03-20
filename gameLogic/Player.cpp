#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Player.hpp"
int const totalLetterTiles = 7;

// Constructor
Player::Player() {
    initializePlayerDeck();
    score = 0;
    amountOfLetterTiles = 0;
}

/* -------------------------------------------------------------------------
 *                      INITIALIZATION FUNCTIONS
 * -------------------------------------------------------------------------*/

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

/* -------------------------------------------------------------------------
 *                      PLAYING FUNCTIONS
 * -------------------------------------------------------------------------*/

// Selecciona una letra para jugarla
LetterTile* Player::playLetterTile(int position){
    LetterTile *letterToPlay = playerDeck[position];
    playerDeck[position] = nullptr;
    return letterToPlay;
}

// Retorna el Deck del jugador
LetterTile** Player::getPlayerDeck(){
    return playerDeck;
}

// Retorna la puntuacion del jugador
int Player::getScore(){
    return score;
}

// Configurar el puntaje
void Player::setScore(int score) {
    Player::score = score;
}

// Sumar puntos al jugador
void Player::addScore(int scoreToAdd) {
    Player::score += scoreToAdd;
}

// Obtiene la cantidad de fichas del jugador
int Player::getAmountOfLetterTiles(){
    return amountOfLetterTiles;
}

// Muestra el Deck en consola
void Player::printPlayerDeck() {
    LetterTile *tile;
    for(int index = 0; index < totalLetterTiles; index++){
        tile = playerDeck[index];
        cout << "[" << tile->getLetter() << ", " << tile->getAmountRemaining() << ", " << tile->getScore() << "] -> ";
    }cout << "NULL"<<endl;
}


#endif PLAYER_CPP