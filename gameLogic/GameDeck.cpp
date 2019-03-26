//
// Created by Erick Barrantes and Esteban Alvarado on 16/03/19.
//

//Libraries
#include "GameDeck.hpp"

// ------------------------------ GAME DECK FUNCTIONS ---------------------------------
GameDeck::GameDeck(){
    deckArray = (LetterTile**) malloc(totalTiles*sizeof(LetterTile*));
    amountOfLetters = 100;
    tilesCSVPath = "../TextFiles/tiles.csv";
    createLetterTiles();
}


void GameDeck::createLetterTiles(){
    // Uses ifstream class to read filesPath.csv and stores it in variable file.
    ifstream file(tilesCSVPath);
    // Creates a vector called row.
    vector<string> row;
    string line, temp;
    LetterTile *tile;
    int index = 0;
    if(file.is_open()) { // Verifies if file was opened.
        while (index != totalTiles){
            getline(file, line); // stores the string of a whole line of the csv to line variable.
            row.clear(); // Clears row values with every loop
            boost::split(row, line, boost::is_any_of(",")); // Splits line when a "," is found every column in vector
            // Creates new LetterTile with the information read from csv.
            tile = new LetterTile(row[0], stoi(row[1]), stoi(row[2])); // stoi a.k.a. string to int
            deckArray[index] = tile; // Adds new LetterTile to deckList.
            index++;
        }
        file.close();// Closes file.
    }else cout << "CSV not opened.";
}

LetterTile* GameDeck::giveRandomLetter() {
    // Checks if theres any letters remaining.
    if (amountOfLetters == 0) return nullptr;
    srand(time(NULL));
    int randomPosition = rand() % amountOfLetters + 1; // randomPosition is a random  int value from 1 to amountOfLetters.
    int counter = 0, index = 0;
    while (counter < randomPosition) { // start while and continue as long as counter < randomPosition.
        counter += deckArray[index]->getAmountRemaining(); // Adds to a counter the amount of letters in actual LetterTile
        index++;
    }index--;
    LetterTile *letterTile = deckArray[index];
    letterTile->decreaseAmountRemaining(); // decreases by one the amount of letter in actual LetterTile.
    amountOfLetters--; // Decreases amountOfLetters by one.
    return letterTile;
}

LetterTile* GameDeck::getLetterFromDeck(string letter){
    LetterTile *letterTile;
    for(int index = 0; index < totalTiles; index++){
        letterTile = deckArray[index];
        if(letterTile->getLetter() == letter) {cout<<"Match"<<endl; return letterTile;}
    }return nullptr;
}

void GameDeck::printDeck(){
    LetterTile *tile;
    for(int i = 0; i < 29; i++){
        tile = deckArray[i];
        cout << "[" << tile->getLetter() << ", " << tile->getAmountRemaining() << ", " << tile->getScore() << "] -> ";
    }cout << "NULL"<<endl;
}