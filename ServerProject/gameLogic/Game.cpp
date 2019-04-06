//
// Created by Esteban Alvarado y Erick Barrantes on 25/03/19.
//

#include "Game.hpp"

// Constructor de juego: Inicializa los parametros
Game::Game() {

    // Inicializacion de los objetos del juego
    gameCode = codeGenerator();
    gameDictionary = Dictionary::getDictionaryInstance();
    gameBoard = new Board();
    gameDeck = new GameDeck();

    // INICIALIZACION DEL SOCKET
    setCode(getGameCode());
    try {
        initSocket();
    } catch (string ex) {
        cout<<ex;
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
    string line, code;

    if (file.is_open()) {

        srand(time(NULL)); // Esto se debe realizar para poder generar numeros aleatorios

        getline(file, line);
        boost::split(fileInfo, line, boost::is_any_of(",")); // Hace split sobre el texto

        for (int i = 0; i < 6; i++) {
            code += fileInfo[rand() % fileInfo.size()];
        }

        file.close();

    } else cout<<"txt not opened.";

    return code;
}

/* ---------------------------------------------------------------------
 *
 *                      METODOS DE SOCKET (HEREDADOS)
 *
 * ---------------------------------------------------------------------*/

void Game::add_players() {

    try {
        addFirstClient();
        ServerMessage* serv_msg= new ServerMessage();
        serv_msg->setMessage1_(1,getGameCode(),"Hello from server");
        string json = serv_msg->serialize();
        sendSingleMessage(json.c_str(),getClient(0));
        cout<<">> TO JOIN THIS GAME, USE THIS CODE: "<<getGameCode()<<endl;
        while (getClientsAmt() < getMaxCap()) {
            addClients();
        }
        /* ------------------------------------------------------
         * En¡ esta parte seria bueno colocar un hilo que se mantenga
         * escuchando pero que ya no acepte clientes sino que los
         * meta en un cola de espera!
         * ------------------------------------------------------*/
        sendMessagetoAll("TODO_LISTO_PARA_COMENZAR!");

    } catch (string ex) {
        cout<<ex;
    }

    start_game();
}

void Game::start_game() {

    runServer();
    thread play_t(&Game::play, this);
    play_t.join();
}

void Game::msgHandler(const char *msg) {
    string s_msg = msg;
    recieveMessage(s_msg);
}

/* ---------------------------------------------------------------------
 *
 *                      METODOS DE JUEGO
 *
 * ---------------------------------------------------------------------*/

void Game::play() {

    /*                  ESQUEMA DE EJECUCION DEL JUEGO
     * 1. Una funcion que le envie sus fichas a c/jugador y el turno actual
     * 2. Setear el turno = 1 y puntos = 0
     * 3. Si totalTiles != 0 ->
     * 4. Recibe el JSON de el jugador -> lo deserializa
     */
    currentTurn = 1;
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
    sendMessagetoAll(">> EL JUEGO HA TERMINADO");
    closeSocket();
}

bool Game::recieveMessage(string json) {

    cout<<"Entra bien a recieveMessage y el mensaje es: "<<json<<endl;
    // Deserializar el mensaje
    PlayerMessage *pJSON = new PlayerMessage();
    pJSON->deserealize(json.c_str());
    pJSON = pJSON->deserealize(json.c_str());

    switch (pJSON->getID()) {
        case 1:
            // Mensaje de confirmacion
            cout<<">> ID:1 --> CONFIRMACION"<<endl;
            break;
        case 2:
            // Mensaje de enviar la palabra
            cout<<">> ID:2 --> AÑADIR PALABRA"<<endl;
            validateWord(pJSON->getWord(), pJSON->getFirstRow(), pJSON->getFirstCol(), pJSON->getIsVertical());
            break;
        case 3:
            // Mensaje de pasar turno o jugar de nuevo
            cout<<">> ID:3 --> PASS/PLAY AGAIN"<<endl;
            break;
        case 4:
            cout<<">> ID:4 --> CONSULTAR AL EXPERTO"<<endl;
            // Mensaje de pedir experto
            break;
        default:
            cout<<">>ID NO IDENTIFICADO "<<endl;
            break;
    }

    return true;
}

// Añade la palabra
bool Game::addWord(string word, int row, int col, bool isVertical) {

    int index = 0;
    cout<<word.length()<<endl;

    // Se itera sobre la palabra para añadir cada letra al tablero
    for (int j = (isVertical) ? row : col; index < word.length(); j++) {

        string letter = "";
        letter += word[index];
        cout<<letter<<endl;

        // Obteniendo referencias del deck
        cout<<"Añadiendo ficha en:"<<((isVertical) ? j : row)<<((isVertical) ? col : j)<<endl;
        LetterTile *wLetter = gameDeck->getLetterFromDeck(letter);

        // Agregando al board
        cout<<wLetter->getLetter()<<endl;
        gameBoard->addLetterTile((isVertical) ? j : row, (isVertical) ? col : j, wLetter);
        index++;
    }
}

// Este método valida las palabras
bool Game::validateWord(string word, int row, int col, bool isVertical) {
    if (gameDictionary->searchInDictionary(word)) {

        addWord(word, row, col, isVertical); //Añadir la palabra
        ServerMessage* serv_msg = new ServerMessage();
        serv_msg->setMessage3_(3,true,10);
        string json = serv_msg->serialize();
        sendSingleMessage(json.c_str(),getClient(currentTurn-1));//Envia el mensaje de confirmacion
        nextTurn(); // Setea el sgte turno
        gameBoard->printGameBoard();

    } else {

        addWord(word, row, col, isVertical); // Añadir la palabra

        // Iteracion vertical
        string vert_word = verticalIterator(word, row, col, isVertical);

        if (gameDictionary->searchInDictionary(vert_word)) {
            gameBoard->printGameBoard();
            return true;
        }

        // Iteracion Horizontal
        string hor_word = horizontalIterator(word, row, col, isVertical);

        if (gameDictionary->searchInDictionary(hor_word)) {
            gameBoard->printGameBoard();
            return true;
        } else {
            resetBoard(word.length(), row, col, isVertical);
            cout<<"Palabra no encontrada"<<endl;
            gameBoard->printGameBoard();
        }
    }
}

// Itera la columna en la que se posicione la palabra buscando palabras que coincidan
string Game::verticalIterator(string word, int row, int col, bool isVertical) {

    cout<<"REVISION VERTICAL DOWN"<<endl;

    string vert_coincidence = (isVertical) ? word : "";
    // Comienza a recorrer desde la casilla siguiente
    for (int itr_row = (isVertical) ? row + word.length() : row; itr_row < 15; itr_row++) {

        LetterTile *l = gameBoard->getLetterTile(itr_row, col);
        if (l == nullptr) break;
        else vert_coincidence += l->getLetter();
        cout<<l->getLetter()<<endl;
    }

    cout<<"Revision VD: "<<vert_coincidence<<endl;

    cout<<"REVISION VERTICAL UP"<<endl;
    // Comienza a recorrer desde la casilla anterior al inicio de la palabra
    string up_words = "";
    for (int itr_row_ = row - 1; itr_row_ >= 0; itr_row_--) {

        LetterTile *l = gameBoard->getLetterTile(itr_row_, col);
        if (l == nullptr) break;
        else {
            up_words += l->getLetter();
            cout<<l->getLetter()<<endl;
            vert_coincidence = up_words + vert_coincidence;
        }
    }

    cout<<"* La palabra vertical formada es: "<<vert_coincidence<<endl;
    return vert_coincidence;
}

string Game::horizontalIterator(string word, int row, int col, bool isVertical) {
    cout<<"REVISION HORIZONTAL RIGTH"<<endl;

    string hor_coincidence = (isVertical) ? "" : word;
    // Comienza a recorrer desde la casilla siguiente
    for (int itr_col = (!isVertical) ? col + word.length() : col; itr_col < 15; itr_col++) {

        LetterTile *l = gameBoard->getLetterTile(row, itr_col);
        if (l == nullptr) break;
        else hor_coincidence += l->getLetter();
        cout<<l->getLetter()<<endl;
    }

    cout<<"Revision HR: "<<hor_coincidence<<endl;

    cout<<"REVISION HORIZONTAL LEFT"<<endl;
    // Comienza a recorrer desde la casilla anterior al inicio de la palabra
    string left_words = "";
    for (int itr_col_ = col - 1; itr_col_ >= 0; itr_col_--) {

        LetterTile *l = gameBoard->getLetterTile(row, itr_col_);
        if (l == nullptr) break;
        else {
            left_words += l->getLetter();
            cout<<l->getLetter()<<endl;
            hor_coincidence = left_words + hor_coincidence;
        }
    }

    cout<<"* La palabra horizontal formada es: "<<hor_coincidence<<endl;
    return hor_coincidence;
}


// Metodo que vuelve el Board a un estado previo si la palabra no es aceptada
void Game::resetBoard(int size, int row, int col, bool vertical) {
    int index = 0;
    for (int j = (vertical) ? row : col; index < size; j++) {

        // Eliminando la letra
        gameBoard->addLetterTile((vertical) ? j : row, (vertical) ? col : j, nullptr);
        index++;
    }
}

/* ---------------------------------------------------------------------
 *
 *                          GETTERS & SETTERS
 *
 * ---------------------------------------------------------------------*/


string Game::getGameCode() {
    return this->gameCode;
}

