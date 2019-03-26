//
// Created by Esteban Alvarado on 25/03/19.
//

#include "Game.hpp"

Game::Game(int players){
    gameCode = codeGenerator();
    gameDictionary = new Dictionary();
    gameBoard = new Board();
}

string Game::codeGenerator() {

    string codePath = "../TextFiles/alphanum.txt";
    // Uses ifstream class to read filesPath.csv and stores it in variable file.
    ifstream file(codePath);
    // Creates a vector called row.
    vector<string> row;
    string line,code;

    if (file.is_open()) {
        srand(time(NULL));
        getline(file, line);
        boost::split(row, line, boost::is_any_of(","));

        for (int i= 0; i < 6; i++) {
            code+=row[rand()%row.size()];
        }
        file.close();// Closes file.
    } else cout << "txt not opened.";

    return code;
}

string Game::getGameCode() {
    return gameCode;
}

bool Game::recieveMessage(string json) {

    // Deserializar el mensaje
    PlayerMessage* pJSON = new PlayerMessage();
    pJSON->deserealize(json.c_str());
    pJSON = pJSON->deserealize(json.c_str());

    // Enviar la palabra
    return addWord(pJSON->getWord(),pJSON->getFirstRow(),pJSON->getFirstCol(),pJSON->getIsVertical());
}

bool Game::addWord(string word, int row, int col, bool isVertical) {
    if(gameDictionary->searchInDictionary(word)){
        if(isVertical){
            int index = 0;
            const char* cWord = word.c_str();
            for(int j = col;j < word.length();j++){
                cout<<cWord[j]<<endl;
                //gameBoard->addLetterTile();
            }
        }
    } else cout<<"No encontrada"<<endl;
}