#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
using namespace std;
class Board{
private:
    static Board* boardSingleton;
    string word;
    vector<vector<int>> wordPositions;

    Board();
    void initializeBoard();

public:
    string gameBoard[15][15];

    static Board* getBoardSingleton();
    void addLetterToBoard(string letter, int x, int y);
    string getWord();
    vector<vector<int>> getWordPositions();
    void setWord(string word);
    void resetWordVector();
};

#endif // BOARD_H
