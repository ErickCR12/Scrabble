#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <fstream>

using namespace std;

class Dictionary{
private:

    string filePath;

public:

    Dictionary(){
        filePath = "../TextFiles/dictionary.txt";
    }

    bool searchInDictionary(string word){
        string line;
        ifstream dictionaryFile = ifstream(filePath);
        if(dictionaryFile.is_open()) {
            while (getline(dictionaryFile, line)) {
                line.erase(line.end() - 1);
                if(line.compare(word) == 0) return true;
            }
            dictionaryFile.close();
        }else{
            cout << "File could not be opened.";
        }
        return false;
    }
};

#endif DICTIONARY_HPP
