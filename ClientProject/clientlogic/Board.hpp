#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
using namespace std;
class Board{
private:
    static Board* boardSingleton;//!
    string word;
    vector<vector<int>> wordPositions;

    Board();
    void initializeBoard();

public:
    string gameBoard[15][15];

    //! \brief Method to get Board singleton
    //! \return Board*
    static Board* getBoardSingleton();

    //! \brief Adds letter parameter in board[x][y]
    //! \param letter Letter to add
    //! \param x position in row
    //! \param y position in column
    void addLetterToBoard(string letter, int x, int y);

    //! \brief Getter for word attribute
    //! \return string: word attribute
    string getWord();

    //! \brief Getter for wordPositions attribute
    //! \return vector<vector<int>> wordPositions attribute
    vector<vector<int>> getWordPositions();

    //! \brief setWord word attribute setter
    //! \param string: new value for word
    void setWord(string word);

    void setWordPositions(vector<vector<int>> wordPositions);

    //! \brief clears wordPositions attribute
    //!'
    void resetWordVector();
};

#endif // BOARD_H
