//
// Created by esteban on 20/03/19.
//

#include "../../gameLogic/Board.hpp"
#include "BoardTest.hpp"

void BoardTest::test1(){
    cout<< "------------ BOARD TEST 1 ------------"<<endl;

    Board* myBoard = new Board();
    myBoard->printGameBoard();
    LetterTile* tile = new LetterTile("a",12,1);
    myBoard->addLetterTile(0,0,tile);
    cout<<endl;
    myBoard->printGameBoard();
    myBoard->getLetterTile(0,0);
    myBoard->getLetterTile(0,1);

}

void BoardTest::test2() {

    cout<< "------------ BOARD TEST 2 ------------"<<endl;
    Board* myBoard = new Board();
    myBoard->printScoreBoard();
    cout<<"* Score on [0][0]: "<<myBoard->getScore(0,0)<<endl;
    cout<<"* Score on [1][0]: "<<myBoard->getScore(1,0)<<endl;
    cout<<"* Score on [7][7]: "<<myBoard->getScore(7,7)<<endl<<endl;

}