#ifndef PLAYER_CPP
#define PLAYER_CPP

// Libraries
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
using namespace std;
int const totalLetterTiles = 7;

// Constructor
Player::Player() {
    playerBoard = Board::getBoardSingleton();
    initializePlayerDeck();
    score = 0;
    amountOfLetters = 0;
    myWord = "";
    positions = (int*) malloc(sizeof(int)*4);
    resetPositions();
}

/* -------------------------------------------------------------------------
 *                      INITIALIZATION FUNCTIONS
 * -------------------------------------------------------------------------*/

void Player::initializePlayerDeck(){
    for(int index = 0; index < totalLetterTiles; index++)
        playerDeck.push_back("");
}

void Player::addLettersToPlayerDeck(string letters) {
    boost::split(playerDeck, letters, boost::is_any_of(","));
    int lettersToAdd = playerDeck.size();
    amountOfLetters += lettersToAdd;
}

void Player::resetPlayerDeck(){
    playerDeck.clear();
    amountOfLetters = 0;
}

/* -------------------------------------------------------------------------
 *                      PLAYING FUNCTIONS
 * -------------------------------------------------------------------------*/

// Añadir una ficha a la palabra
void Player::addLetterToWord(int position, int row, int col) {

    if (position < 7) {
        string currentTile = playLetter(position);

        // En el caso de que al jugador quiera utilizar el comodin debe asignarle la letra que desea!
        if(currentTile == "blank"){
            cout<<"*Ingrese el valor que desea al blank: ";
            cin>>currentTile;
        }
        this->myWord += currentTile;

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
string Player::playLetter(int position){
    string letter = playerDeck[position];
    playerDeck[position] = "";
    amountOfLetters--;
    return letter;
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

    // Envia como cuarto parametro la igual de las columnas, si estas son iguales,
    // entonces la palabra es vertical
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
vector<string> Player::getPlayerDeck(){
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
    return amountOfLetters;
}

void Player::setAmountOfLetterTiles(int amount){
    amountOfLetters = amount;
}

void Player::setPlayerName(string name){
    playerName = name;
}

string Player::getPlayerName(){
    return playerName;
}

Board* Player::getBoard(){
    return playerBoard;
}

vector<DraggableTile*> Player::getWidgetsPlayerDeck(){
    return widgetsPlayerDeck;
}

void Player::addWidgetToDeck(DraggableTile* tile){
    widgetsPlayerDeck.push_back(tile);
}

void Player::resetWidgetsDeck(){
    widgetsPlayerDeck.clear();
}

// Muestra el Deck en consola
void Player::printPlayerDeck() {
    string tile;
    for(int index = 0; index < totalLetterTiles; index++){
        tile = playerDeck[index];
        // When we get LetterTiles for play these then points to nullptr
        if(tile != ""){
        cout << "[" << tile << "] -> ";
        } else cout<<"[EMPTY] -> ";
    }cout<<" END" << endl;
}

void Player::printPositions() {
    for(int index = 0; index<4;index++){
        cout<<"[ "<<positions[index]<<"]-> ";
    }cout<<"NULL"<<endl;
}

#endif //PLAYER_CPP
