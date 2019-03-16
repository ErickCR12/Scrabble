#include <iostream>
#include "Dictionary.hpp"

using namespace std;
Dictionary::Dictionary(){
    filePath = "../TextFiles/dictionary.txt";
}

bool Dictionary::searchInDictionary(string word){
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