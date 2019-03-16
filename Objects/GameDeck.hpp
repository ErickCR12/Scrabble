#ifndef GAMEDECK_HPP
#define GAMEDECK_HPP

#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "LetterTile.hpp"
#include "../DataStructures/List.hpp"

//! It contains a list where each node stores an instance of LetterTile for each available letter, in total it has
//! 29 nodes.
//! @brief Represents the deck of the game with the full amount of LetterTiles.
int const totalTiles = 29;
class GameDeck{
private:

    LetterTile **deckArray; //!< @brief List with all the LetterTile instances of the game.
    int amountOfLetters; //!< @brief int value with total amount of letters available. Starts as a 100.
    string tilesPath; //!< @brief Path to file in csv format that contains attributes to instance LetterTile.

public:
    //! Initializes List, amountOfLetters, tilesPath and calls createLetterTiles() method to instance every LetterTile
    //! and insert them to deckList.
    //! @brief GameDeck constructor.
    GameDeck(){
        deckArray = (LetterTile**) malloc(totalTiles*sizeof(LetterTile*));
        amountOfLetters = 100;
        tilesPath = "../TextFiles/tiles.csv";
        createLetterTiles();
    }

    //! This method reads a CSV text file, that follows this format: Letter,Amount,Score.
    //! Reads line by line and adds the value of every column to a vector structure.
    //! @brief Reads tiles.csv, creates every instance of LetterTile and adds them to deckList.
    void createLetterTiles(){
        //! Uses ifstream class to read filesPath.csv and stores it in variable file.
        ifstream file(tilesPath);
        //! Creates a vector called row.
        vector<string> row;
        string line, temp;
        LetterTile *tile;
        int index = 0;
        if(file.is_open()) { //! Verifies if file was opened.
            while (index != totalTiles){
                getline(file, line); //! stores the string of a whole line of the csv to line variable.
                row.clear(); //! Clears row values with every loop
                boost::split(row, line, boost::is_any_of(",")); //! Splits line when a "," is found every column in vector
                //! Creates new LetterTile with the information read from csv.
                tile = new LetterTile(row[0], stoi(row[1]), stoi(row[2])); // stoi a.k.a. string to int
                deckArray[index] = tile; //! Adds new LetterTile to deckList.
                index++;
            }
            file.close();//! Closes file.
        }else cout << "CSV not opened.";
    }

    //! @brief Takes in consideration all the amount of letters remaining to randomly return a referecence of a
    //! LetterTile with at least a letter remaining.
    //! @return LetterTile obtained randomly.
    LetterTile *giveRandomLetter() {
        //! Checks if theres any letters remaining.
        if (amountOfLetters == 0) return nullptr;
        srand(time(NULL));
        int randomPosition = rand() % amountOfLetters + 1; //! randomPosition is a random  int value from 1 to amountOfLetters.
        int counter = 0, index = 0;
        while (counter < randomPosition) { //! start while and continue as long as counter < randomPosition.
            counter += deckArray[index]->getAmountRemaining(); //! Adds to a counter the amount of letters in actual LetterTile
            index++;
        }index--;
        LetterTile *letterTile = deckArray[index];
        letterTile->decreaseAmountRemaining(); //! decreases by one the amount of letter in actual LetterTile.
        amountOfLetters--; //! Decreases amountOfLetters by one.
        return letterTile;
    }


    void printDeck(){
        LetterTile *tile;
        for(int i = 0; i < 29; i++){
            tile = deckArray[i];
            cout << "[" << tile->getLetter() << ", " << tile->getAmountRemaining() << ", " << tile->getScore() << "] -> ";
        }cout << "NULL"<<endl;
    }
};

#endif GAMEDECK_HPP
