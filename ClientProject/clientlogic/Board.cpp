#ifndef BOARD_CPP
#define BOARD_CPP
#include "Board.hpp"
#include <string>
#include <iostream>
using namespace std;

Board::Board(){
    initializeBoard();
    word = "";
}

Board* Board::boardSingleton = nullptr;
Board* Board::getBoardSingleton(){
    if(boardSingleton == nullptr) boardSingleton = new Board();
    return boardSingleton;
}

void Board::initializeBoard(){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            gameBoard[i][j] = "";
        }
    }
}

void Board::addLetterToBoard(string letter, int x, int y){
    gameBoard[x][y] = letter;
    word += letter + ",";
    vector<int> positionsVector;
    positionsVector.push_back(x); positionsVector.push_back(y);
    wordPositions.push_back(positionsVector);
}

string Board::getWord(){
    return word;
}

vector<vector<int>> Board::getWordPositions(){
    return wordPositions;
}

void Board::setWord(string word){
    this->word = word;
}

void Board::resetWordVector(){
    wordPositions.clear();
    word = "";
}

#endif // BOARD_CPP
