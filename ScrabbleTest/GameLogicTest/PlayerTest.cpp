//
// Created by esteban on 20/03/19.
//

#include "PlayerTest.hpp"
#include "../../gameLogic/GameDeck.hpp"
#include "../../gameLogic/Player.hpp"
#include "../../gameLogic/LetterTile.hpp"

// Prueba de repartir el gameDeck de c/jugador
void PlayerTest::test1() {

    cout<<"-------------- PLAYER TEST 1 --------------"<<endl;
    GameDeck *gameDeck = new GameDeck();

    cout<<"\nCreando player1..."<<endl;
    Player* player1 = new Player();
    cout<<"Creando player2..."<<endl;
    Player* player2 = new Player();

    cout<<"Llenando deck de player1..."<<endl;
    while(player1->getAmountOfLetterTiles() != 7){
        LetterTile *randomLetterTile = gameDeck->giveRandomLetter();
        player1->addLetterTile(randomLetterTile);
    }

    cout<<"Llenando deck de player1..."<<endl;
    while(player2->getAmountOfLetterTiles() != 7){
        LetterTile *randomLetterTile = gameDeck->giveRandomLetter();
        player2->addLetterTile(randomLetterTile);
    }
    cout<<"Deck player1: ";
    player1->printPlayerDeck();
    cout<<"Deck player2: ";
    player2->printPlayerDeck();
}

// Prueba de ingreso de palabras
void PlayerTest::test2() {
    cout<<"-------------- PLAYER TEST 2 --------------"<<endl;
    GameDeck *gameDeck = new GameDeck();

    cout<<"\nCreando player1..."<<endl;
    Player* player1 = new Player();

    cout<<"Llenando deck de player1..."<<endl;
    while(player1->getAmountOfLetterTiles() != 7){
        LetterTile *randomLetterTile = gameDeck->giveRandomLetter();
        player1->addLetterTile(randomLetterTile);
    }

    cout<<"Deck player1: ";
    player1->printPlayerDeck();

    bool ready = true;
    while(ready && player1->getAmountOfLetterTiles()>0){
        int position,row,col;
        cout<<"* Ingrese la posicion de la letra: ";
        cin>>position;
        cout<<"* Ingrese la fila: ";
        cin>>row;
        cout<<"* Ingrese la columna: ";
        cin>>col;
        player1->addLetterToWord(position,row,col);

        string ans;
        cout<<"* ¿Desea añadir otra letra? S/N ";
        cin>>ans;

        if(ans == "N") ready = false;
    }

    player1->sendMyWord();


}