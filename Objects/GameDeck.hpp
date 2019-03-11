#ifndef GAMEDECK_HPP
#define GAMEDECK_HPP

#include <vector>
#include <boost/algorithm/string.hpp>

class GameDeck{
private:
    List *deckList;
    string tilesPath;

public:
    GameDeck(){
        deckList = new List();
        tilesPath = "../TextFiles/tiles.csv";
        createLetterTiles();
    }

    void createLetterTiles(){
        ifstream file(tilesPath);
        vector<string> row;
        string line, temp;
        if(file.is_open()) {
            while (getline(file, line)) {
                row.clear();
                boost::split(row, line, boost::is_any_of(","));
                LetterTile *tile = new LetterTile(row[0], stoi(row[1]), stoi(row[2]));
                deckList->addHead(tile);
            }
            file.close();
        }else cout << "CSV not opened.";
    }

    LetterTile *giveRandomLetter(){
        int amountOfLettersRemaining = deckList->getAmountOfLetters();
        if(amountOfLettersRemaining == 0) return nullptr;
        srand (time(NULL));
        int randomPosition = rand() % amountOfLettersRemaining + 1;
        cout << "Pos: " << randomPosition << endl;
        int counter = 0;
        Node *node = deckList->getHead();
        LetterTile *letterTile;
        bool letterFound = false;
        while(!letterFound) {
            counter += node->getLetterTile()->getAmountRemaining();
            if (counter >= randomPosition) {
                if (node->getLetterTile()->getAmountRemaining() != 0) {
                    letterTile = node->getLetterTile();
                    letterTile->decreaseAmountRemaining();
                    letterFound = true;
                }
            }
            if(!letterFound) node=node->getNextNode();
        }deckList->decreaseAmountOfLetters();
        return letterTile;
    }

    void printDeck(){
        LetterTile *tile;
        for(Node *node = deckList->getHead(); node; node = node->getNextNode()){
            tile = node->getLetterTile();
            cout << "[" << tile->getLetter() << ", " << tile->getAmountRemaining() << ", " << tile->getScore() << "] -> ";
        }cout << "NULL";
    }
};

#endif GAMEDECK_HPP
