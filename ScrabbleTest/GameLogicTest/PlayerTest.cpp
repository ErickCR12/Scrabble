//
// Created by esteban on 20/03/19.
//

#include "PlayerTest.hpp"
#include "../../gameLogic/GameDeck.hpp"
#include "../../gameLogic/Player.hpp"
#include "../../gameLogic/LetterTile.hpp"

void PlayerTest::test() {

    cout<<"-------------- PLAYER TEST --------------"<<endl;
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