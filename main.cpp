#include <iostream>
#include "Objects/Dictionary.hpp"
#include "DataStructures/List.hpp"
#include "Objects/GameDeck.hpp"

int main() {
    Dictionary *dictionary = new Dictionary();
    cout<<"Searching for zutano: ";
    if(dictionary->searchInDictionary("zutano")) cout<<"Found."<<endl;
    else cout << "Not Found.\n\n\n";

    GameDeck *gd = new GameDeck();

    cout<<"Randomly extracting all letter tiles: "<<endl;
    LetterTile* l;
    for(int i = 0; i < 100; i++) {
        cout << "GameDeck [letter, amount, score]: ";
        gd->printDeck(); cout <<endl;
        l = gd->giveRandomLetter();
        cout << l->getLetter() << "\n\n";
    }

}