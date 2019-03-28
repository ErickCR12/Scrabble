//
// Created by Esteban Alvarado y Erick Barrantes on 25/03/19.
//

#include "Game.hpp"

// Constructor de juego: Inicializa los parametros
Game::Game(int players){
    gameCode = codeGenerator();
    gameDictionary = Dictionary::getDictionaryInstance();
    gameBoard = new Board();
    gameDeck = new GameDeck();
}


/* ---------------------------------------------------------------------
 *
 *                      METODOS DE INICIALIZACION
 *
 * ---------------------------------------------------------------------*/

// Genera el codigo alfanumerico para unirse a este juego
string Game::codeGenerator() {

    string codePath = "../TextFiles/alphanum.txt";
    ifstream file(codePath);

    vector<string> fileInfo;
    string line,code;

    if (file.is_open()) {

        srand(time(NULL)); // Esto se debe realizar para poder generar numeros aleatorios

        getline(file, line);
        boost::split(fileInfo, line, boost::is_any_of(",")); // Hace split sobre el texto

        for (int i= 0; i < 6; i++) {
            code+=fileInfo[rand()%fileInfo.size()];
        }

        file.close();

    } else cout << "txt not opened.";

    return code;
}


/* ---------------------------------------------------------------------
 *
 *                      METODOS DE JUEGO
 *
 * ---------------------------------------------------------------------*/

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
        cout<<"palabra encontrada"<<endl;
        int index = 0;
        cout<<word.length()<<endl;
        for(int j = (isVertical)? row:col;index < word.length();j++) {

            string letter = "";
            letter += word[index];
            cout<<letter<<endl;
            cout<<"Añadiendo ficha en:"<<((isVertical)? j:row)<<((isVertical)?col:j )<<endl;
            LetterTile *wLetter = gameDeck->getLetterFromDeck(letter);
            cout<<wLetter->getLetter()<<endl;
            gameBoard->addLetterTile((isVertical)? j:row,(isVertical)? col:j,wLetter);
            index++;

        }

        gameBoard->printGameBoard();
    } else cout<<"No encontrada"<<endl;
}


/* ---------------------------------------------------------------------
 *
 *                          GETTERS & SETTERS
 *
 * ---------------------------------------------------------------------*/


string Game::getGameCode() {
    return this->gameCode;
}
