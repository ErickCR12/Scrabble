#include <iostream>
#include "gamelogic/Dictionary.hpp"
#include "gamelogic/GameDeck.hpp"
#include "gamelogic/Board.hpp"
#include "gamelogic/Player.hpp"

void dictionaryTest();
void boardTest1();
void boardTest2();
void playerTest1();

int main() {
    dictionaryTest();
    boardTest1();
    boardTest2();
    playerTest1();
}

void dictionaryTest(){
    Dictionary *dictionary = new Dictionary();
    cout<<"Searching for zutano: ";
    if(dictionary->searchInDictionary("zutano")) cout<<"Found."<<endl;
    else cout << "Not Found.\n\n\n";

    GameDeck *gd = new GameDeck();
    gd->printDeck();
//
//    cout<<"Randomly extracting all letter tiles: "<<endl;
//    LetterTile* l;
//    for(int i = 0; i < 100; i++) {
//        cout << "GameDeck [letter, amount, score]: ";
//        gd->printDeck();
//        l = gd->giveRandomLetter();
//        cout << l->getLetter() << "\n\n";
//    }
}

void boardTest1(){
    Board* myBoard = new Board();
    myBoard->printGameBoard();
    LetterTile* tile = new LetterTile("a",12,1);
    myBoard->addLetterTile(0,0,tile);
    cout<<endl;
    myBoard->printGameBoard();
    myBoard->getLetterTile(0,0);
    myBoard->getLetterTile(0,1);

}

void boardTest2(){
    Board* myBoard = new Board();
    myBoard->printScoreBoard();
    cout<<myBoard->getScore(0,0)<<endl;
    cout<<myBoard->getScore(1,0)<<endl;
    cout<<myBoard->getScore(7,7)<<endl;
}

void playerTest1(){
    GameDeck *gameDeck = new GameDeck();

    cout<<"\nCreando player1..."<<endl;
    Player *player1 = new Player();
    cout<<"Creando player2..."<<endl;
    Player *player2 = new Player();

    cout<<"Llenando deck de player1..."<<endl;
    while(player1->getAmountOfLetterTiles() != 7){
        LetterTile *randomLetterTile = gameDeck->giveRandomLetter();
        player1->addLetterTile(randomLetterTile);
    }
    cout<<"Deck player1: "; player1->printPlayerDeck();

    cout<<"Llenando deck de player1..."<<endl;
    while(player2->getAmountOfLetterTiles() != 7){
        LetterTile *randomLetterTile = gameDeck->giveRandomLetter();
        player2->addLetterTile(randomLetterTile);
    }
    cout<<"Deck player2: "; player2->printPlayerDeck();
}

