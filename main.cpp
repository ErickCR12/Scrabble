#include <iostream>
#include "Dictionary.hpp"
#include "DataStructures/List.hpp"
#include "GameDeck.hpp"

int main() {
    Dictionary *dictionary = new Dictionary();
    cout<<"Searching for zutano: ";
    if(dictionary->searchInDictionary("zutano")) cout<<"Found."<<endl;
    else cout << "Not Found."<<endl;

    GameDeck *gd = new GameDeck();
    cout << "GameDeck [letter, amount, score]: ";gd->printDeck();
}