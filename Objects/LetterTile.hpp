#ifndef LETTERTILE_HPP
#define LETTERTILE_HPP

//! @brief This class represents each letter tile used in Scrabble.
class LetterTile{
private:

    string letter; //!< @brief String for letter that represents the instance.
    int amountRemaining; //!< @brief Amount of tiles available with this letter.
    int score; //!< @brief The score value for the letter tile.

public:
    /// @brief Constructor for LetterTile.
    /// @param letter String with letter to store.
    /// @param amountRemaining Amount of letter available.
    /// @param score Score awarded for this letter.
    LetterTile(string letter, int amountRemaining, int score){
        this->letter = letter;
        this->amountRemaining = amountRemaining;
        this->score = score;
    }

    //! @brief Returns the letter attribute
    //! @return string value stored in letter
    string getLetter(){
        return letter;
    }

    //! @brief Returns the amountRemaining attribute
    //! @return int value stored in amountRemaining
    int getAmountRemaining(){
        return amountRemaining;
    }

    //! @brief Decreases by one the attribute amountRemaining
    void decreaseAmountRemaining(){
        amountRemaining--;
    }

    //! @brief Returns the score attribute
    //! @return int value stored in score
    int getScore(){
        return score;
    }
};

#endif LETTERTILE_HPP
