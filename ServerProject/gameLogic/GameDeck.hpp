#ifndef GAMEDECK_HPP
#define GAMEDECK_HPP

#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "LetterTile.hpp"


int const totalTiles = 29;

//! It contains a list where each node stores an instance of LetterTile for each available letter, in total it has
//! 29 nodes.
//! @brief Represents the deck of the game with the full amount of LetterTiles.

class GameDeck{
private:

    LetterTile **deckArray; //!< @brief List with all the LetterTile instances of the game.
    int amountOfLetters; //!< @brief int value with total amount of letters available. Starts as a 100.
    string tilesCSVPath; //!< @brief Path to file in csv format that contains attributes to instance LetterTile.

public:
    //! Initializes List, amountOfLetters, tilesPath and calls createLetterTiles() method to instance every LetterTile
    //! and insert them to deckList.
    //! @brief GameDeck constructor.
    GameDeck();

    //! This method reads a CSV text file, that follows this format: Letter,Amount,Score.
    //! Reads line by line and adds the value of every column to a vector structure.
    //! @brief Reads tiles.csv, creates every instance of LetterTile and adds them to deckList.
    void createLetterTiles();

    //! @brief Takes in consideration all the amount of letters remaining to randomly return a referecence of a
    //! LetterTile with at least a letter remaining.
    //! @return LetterTile obtained randomly.
    LetterTile* giveRandomLetter();

    LetterTile* getLetterFromDeck(string letter);

    int getAmountofLetters(){
        return amountOfLetters;
    }

    //! @brief Prints the Deck on console.
    void printDeck();
};

#endif GAMEDECK_HPP
