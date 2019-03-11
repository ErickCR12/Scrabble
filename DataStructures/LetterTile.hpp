#ifndef LETTERTILE_HPP
#define LETTERTILE_HPP

class LetterTile{
private:
    string letter;
    int amountRemaining;
    int score;

public:
    LetterTile(string letter, int amountRemaining, int score){
        this->letter = letter;
        this->amountRemaining = amountRemaining;
        this->score = score;
    }

    string getLetter(){
        return letter;
    }

    void setLetter(string letter) {
        this->letter = letter;
    }

    int getAmountRemaining(){
        return amountRemaining;
    }

    void setAmountRemaining(int amountRemaining) {
        this->amountRemaining = amountRemaining;
    }

    int getScore(){
        return score;
    }

    void setScore(int score) {
        this->score = score;
    }
};

#endif LETTERTILE_HPP
