#include "GameDeck.hpp"
using namespace std;

GameDeck::GameDeck(){
    deckList = new List();
    amountOfLetters = 100;
    tilesPath = "../TextFiles/tiles.csv";
    createLetterTiles();
}

void GameDeck::createLetterTiles(){
    //! Uses ifstream class to read filesPath.csv and stores it in variable file.
    ifstream file(tilesPath);
    //! Creates a vector called row.
    vector<string> row;
    string line, temp;
    if(file.is_open()) { //! Verifies if file was opened.
        while (getline(file, line)) { //! stores the string of a whole line of the csv to line variable.
            row.clear(); //! Clears row values with every loop
            boost::split(row, line, boost::is_any_of(",")); //! Splits line when a "," is found every column in vector
            //! Creates new LetterTile with the information read from csv.
            LetterTile *tile = new LetterTile(row[0], stoi(row[1]), stoi(row[2])); // stoi a.ka. string to int
            deckList->addNode(tile); //! Adds new LetterTile to deckList.
        }
        file.close();//! Closes file.
    }else cout << "CSV not opened.";
}


LetterTile* GameDeck::giveRandomLetter(){
    //! Checks if theres any letters remaining.
    if(amountOfLetters == 0) return nullptr;
    srand (time(NULL));
    int randomPosition = rand() % amountOfLetters + 1; //! randomPosition is a random  int value from 1 to amountOfLetters.
    cout << "Pos: " << randomPosition << endl;
    int counter = 0; Node *node = deckList->getHead(); LetterTile *letterTile = nullptr; bool letterFound = false;
    //! while that loops until the letter in randomPosition is found, starting in the head of deckList.
    while(!letterFound) {
        counter += node->getLetterTile()->getAmountRemaining(); //! Adds to a counter the amount of letters in actual LetterTile
        if (counter >= randomPosition) { //! if counter is >= to the randomPosition, the letter is found.
            letterTile = node->getLetterTile();
            letterTile->decreaseAmountRemaining(); //! decreases by one the amount of letter in actual LetterTile.
            letterFound = true;
        }node=node->getNextNode(); //! Travels to nextNode with every loop.
    }amountOfLetters--; //! Decreases amountOfLetters by one.
    return letterTile;
}


void GameDeck::printDeck(){
    LetterTile *tile;
    for(Node *node = deckList->getHead(); node; node = node->getNextNode()){
        tile = node->getLetterTile();
        cout << "[" << tile->getLetter() << ", " << tile->getAmountRemaining() << ", " << tile->getScore() << "] -> ";
    }cout << "NULL";
}