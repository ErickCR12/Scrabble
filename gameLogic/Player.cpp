#ifndef PLAYER_CPP
#define PLAYER_CPP

// Libraries
#include "Player.hpp"
#include "../JSON/PlayerMessage.hpp"

int const totalLetterTiles = 7;

// Constructor
Player::Player() {
    initializePlayerDeck();
    score = 0;
    amountOfLetterTiles = 0;
    myWord = "";
    positions = (int*) malloc(sizeof(int)*4);
    resetPositions();
    playerBoard = new Board();
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

// Añadir una ficha a la palabra
void Player::addLetterToWord(int position, int row, int col) {

    if (position < 7) {
        this->myWord += playLetterTile(position)->getLetter();

        // Almacena la primera y ultima posicion de las fichas de la palabra
        if(positions[0] == 100){
            positions[0] = row;
            positions[1] = col;
        } else {
            positions[2] = row;
            positions[3] = col;
        }

        // Esto es BASURA DE CONSOLA [SE PUEDE ELIMINAR Y NO PASA NADA]
        cout<<"* Tu palabra es: "<<myWord<<endl;
        printPositions();
        cout<<"* Deck: "; printPlayerDeck();
    }
}

// Selecciona una letra para jugarla
LetterTile* Player::playLetterTile(int position){
    LetterTile *letterToPlay = playerDeck[position];
    playerDeck[position] = nullptr;
    amountOfLetterTiles--;
    return letterToPlay;
}

// Setea el array de posiciones en 100 [Termino por defuault]
void Player::resetPositions() {
    for(int index = 0; index<4;index++){
        positions[index] = 100;
    }
}

// Prepara y envia el mensaje con la palabra construida
bool Player::sendMyWord() {

    PlayerMessage* myMessage = new PlayerMessage();

    // Envia como cuarto parametro la igual de las columnas, si estas son iguales, entonces la palabra es vertical
    myMessage->setMessage(myWord,positions[0],positions[1],positions[1]==positions[3]);

    string myJSON = myMessage->serialize();
    cout<<"* JSON: "<<myJSON<<endl;

    // Linea que envia el mensaje

    // Reinicia los atributos
    resetPositions();
    myWord = "";

}

/* -------------------------------------------------------------------------
 *                          GETTERS & SETTERS
 * -------------------------------------------------------------------------*/

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
        // When we get LetterTiles for play these then points to nullptr
        if(tile){
        cout << "[" << tile->getLetter() << ", " << tile->getAmountRemaining() << ", " << tile->getScore() << "] -> ";
        } else cout<<"NULL -> ";
    }cout << "NULL"<<endl;
}

void Player::printPositions() {
    for(int index = 0; index<4;index++){
        cout<<"[ "<<positions[index]<<"]-> ";
    }
    cout<<"NULL"<<endl;
}

#endif PLAYER_CPP