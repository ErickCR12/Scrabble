#ifndef GAMEDECK_HPP
#define GAMEDECK_HPP

#include <vector>
#include <boost/algorithm/string.hpp>
#include "DataStructures/LetterTile.hpp"

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

    void printDeck(){
        LetterTile *tile;
        for(Node *node = deckList->getHead(); node; node = node->getNextNode()){
            tile = node->getLetterTile();
            cout << "[" << tile->getLetter() << ", " << tile->getAmountRemaining() << ", " << tile->getScore() << "] -> ";
        }cout << "NULL";
    }
};

#endif GAMEDECK_HPP
