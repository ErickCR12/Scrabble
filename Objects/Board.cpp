//
// Created by Esteban Alvarado on 15/03/19.
//

// Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include "Board.hpp"

using namespace std;

// ------------------------------ GAME BOARD FUNCTIONS ---------------------------------

int const row = 15; int const col = 15;

// Constructor
Board::Board() {

    // Memory allocation
    gameBoard = (LetterTile* (*)[15]) malloc(sizeof((*gameBoard))*15);
    scoreBoard = (int (*)[15]) malloc(sizeof(*scoreBoard)*15);

    // Initialize both Boards
    initGameBoard();
    initScoreBoard();
}

// Matrix initializer
void Board::initGameBoard() {

    //The board can only be initialized once.
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            gameBoard[i][j] = nullptr;
        }
    }
    cout<<"¡Board has been initialized successfully!"<<endl;
}

// Show the matrix in console.
void Board::printGameBoard() {

    cout<< " ------------ SCRABBLE BOARD ----------"<<endl;
    for (int i = 0; i < row; ++i) {

        for (int j = 0; j < col; ++j) {
            cout<<"[";
            if(gameBoard[i][j]) gameBoard[i][j]->toString();
            else cout<<" ";
            cout<<"]";
        }
        cout<<endl;
    }
    cout<<"\n\n";
}

// Add a tile in to the board
void Board::addLetterTile(int row, int col, LetterTile* newTile) {
    this->gameBoard[row][col] = newTile;
}

// Get a tile from the board
LetterTile* Board::getLetterTile(int row, int col) {
    LetterTile* tile = gameBoard[row][col];
    if(tile){
        cout<<"Board ["<<row<<"]["<<col<<"] -> "<< tile ->getLetter()<<endl;
        return tile;
    }
    cout<<"Error: There is no Tile in this address ["<<row<<"]["<<col<<"]"<<endl;
    return nullptr;
}


// ------------------------------------------------------------------------------------

// ------------------------------ SCOREBOARD FUNCTIONS ---------------------------------

// Score matrix initializer
void Board::initScoreBoard() {

    // Uses ifstream class to read filesPath.csv and stores it in variable file.
    ifstream file(scorePath);

    //Creates a vector called board_row.
    vector<string> board_row;
    string line, temp;

    if(file.is_open()) {
        int fileRow = 0;
        while (getline(file, line)) { // Stores the string of a whole line of the csv to line variable.

            board_row.clear(); //Clears board_row values with every loop
            boost::split(board_row, line, boost::is_any_of(",")); //Splits line when a "," is found every column in vector

            //! Initialize scoreBoard read from csv.
            for(int fileCol = 0; fileCol<col;fileCol++){
                scoreBoard[fileRow][fileCol] = stoi(board_row[fileCol]);
            }
            fileRow++;
        }
    }
}

// Show the matrix in console.
void Board::printScoreBoard() {

    cout<< " ------------ SCORES BOARD ----------"<<endl;
    for (int i = 0; i < row; ++i) {

        for (int j = 0; j < col; ++j) {
            cout<<"[";
            if(scoreBoard[i][j] != 1)cout<<scoreBoard[i][j];
            else cout<<" ";
            cout<<"]";
        }
        cout<<endl;
    }
    cout<<"\n\n";
}

// Returns the
int Board::getScore(int row, int col) {
    return scoreBoard[row][col];
}
