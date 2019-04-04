//
// Created by Esteban Alvarado y Erick Barrantes on 25/03/19.
//

#include "Game.hpp"

// Constructor de juego: Inicializa los parametros
Game::Game(){

    // Inicializacion de los objetos del juego
    gameCode = codeGenerator();
    gameDictionary = Dictionary::getDictionaryInstance();
    gameBoard = new Board();
    gameDeck = new GameDeck();

    // INICIALIZACION DEL SOCKET
    setCode(getGameCode());
    try {
        initSocket();
    }catch(string ex)
    {
        cout << ex;
    }

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
 *                      METODOS DE SOCKET (HEREDADOS)
 *
 * ---------------------------------------------------------------------*/

void Game::add_players() {
    cout<<"Todo bien por ahora desde::"<<gameCode<<endl;
    try{
        addFirstClient();
        while(getClientsAmt()<getMaxCap()){
            addClients();
        }
        sendMessagetoAll("TODO_LISTO!");
        cout<<"Todo bien agregando los clientes"<<endl;
    }catch(string ex)
    {
        cout << ex;
    }

    start_game();
}

void Game::start_game(){

    runServer();
    thread play_t(&Game::play,this);
    play_t.join();
}

void Game::msgHandler(const char* msg) {
    cout<<msg<<endl;
    string s_msg = msg;
    recieveMessage(s_msg);
}

/* ---------------------------------------------------------------------
 *
 *                      METODOS DE JUEGO
 *
 * ---------------------------------------------------------------------*/

void Game::play(){

    /*                  ESQUEMA DE EJECUCION DEL JUEGO
     * 1. Una funcion que le envie sus fichas a c/jugador y el turno actual
     * 2. Setear el turno = 1 y puntos = 0
     * 3. Si totalTiles != 0 ->
     * 4. Recibe el JSON de el jugador -> lo deserializa
     */
    while (totalTiles >= 0) {
        if (totalTiles == 0) {
            // Esta parte realiza lo que sea que se haga en el ultimo turno
        } else {
            string mensaje;
            cin>>mensaje;
            if (mensaje == "EXIT") break;
            sendMessagetoAll(mensaje.c_str());

        }
    }
}

bool Game::recieveMessage(string json) {

    cout<<"Entra bien a recieveMessage y el mensaje es: "<<json<<endl;
    // Deserializar el mensaje
    //PlayerMessage *pJSON = new PlayerMessage();
    // pJSON->deserealize(json.c_str());
    //pJSON = pJSON->deserealize(json.c_str());

    // Enviar la palabra
    //return addWord(pJSON->getWord(), pJSON->getFirstRow(), pJSON->getFirstCol(), pJSON->getIsVertical());


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

