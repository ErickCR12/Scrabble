//
// Created by esteban on 20/03/19.
//

#include "DictionaryTest.hpp"
#include "../../gameLogic/Dictionary.hpp"
#include "../../gameLogic/GameDeck.hpp"

void DictionaryTest::test1(){

    cout<< "-------------- DICTIONATY TEST --------------"<<endl;
    Dictionary *dictionary = Dictionary::getDictionaryInstance();
    cout<<"Searching for hola: ";
    if(dictionary->searchInDictionary("hola")) cout<<"Found."<<endl;
    else cout << "Not Found.\n\n\n";
    //dictionary->writeInDictionary("palabraPrueba");

    cout<< "------------ ALSO GAME DECK TEST ------------"<<endl;
    GameDeck *gd = new GameDeck();
    cout<< ">> Game Deck : ";gd->printDeck();

    cout<<":: Randomly extracting all letter tiles: "<<endl;
    LetterTile* l;

    for(int i = 0; i < 100; i++) {
        //cout << "GameDeck [letter, amount, score]: ";
        //gd->printDeck();
        gd->giveRandomLetter();
        //cout << l->getLetter() << "\n\n";
    }
    cout<< ">> Game Deck : ";gd->printDeck();cout<<endl;
}