#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP

#include "Dictionary.hpp"
#include "Player.hpp"
#include "GameDeck.hpp"
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

Dictionary::Dictionary(){
    filePath = "../TextFiles/dictionary.txt";
}

bool Dictionary::searchInDictionary(string word) {
    string line;
    ifstream dictionaryFile = ifstream(filePath);
    if (dictionaryFile.is_open()) {
        while (getline(dictionaryFile, line)) {
            if (line.compare(word) == 0)
                return true;
        }
        dictionaryFile.close();
    } else {
        cout << "File could not be opened.";
    }
    return false;
}

void Dictionary::writeInDictionary(string word) {
    fstream dictionaryFile(filePath, ios::app); //ios::in | ios::out
    if(dictionaryFile.is_open()) {
        dictionaryFile << word + "\n";
        dictionaryFile.close();
    }else cout << "Couldn't write in file";
}

//    string line;
//    getline(dictionaryFile, line);
//    if(dictionaryFile.is_open()){
//        while(line < word) {
//            getline(dictionaryFile, line);
//        }
//        long position = dictionaryFile.tellg();
//        dictionaryFile.seekp(position - line.length() - 1);
//        word += "\n";
//        char wordArray[word.length()];
//        strcpy(wordArray, word.c_str());
//        dictionaryFile.write(wordArray, word.length());
//        dictionaryFile.close();
//    }else cout << "File couldn't be opened.";


#endif DICTIONARY_CPP