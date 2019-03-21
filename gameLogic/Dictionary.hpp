#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <string>

//! @brief Class Dictionary responsible of accessing dictionary.txt and searching for words in this text file.
class Dictionary{
private:

    std::string filePath; //!< @brief Path to file that contains dictionary in spanish.

public:

    //! @brief Dictionary constructor. Initializes filePath attribute with correct attribute to dictionary.txt
    Dictionary();

    //! @brief Receives a word to search in the dictionary text file.
    //! @param word string to compare with the dictionary words.
    //! @return bool indicating if the word exists in the dictionary.
    bool searchInDictionary(std::string word);

    void writeInDictionary(std::string word);
};

#endif DICTIONARY_HPP
