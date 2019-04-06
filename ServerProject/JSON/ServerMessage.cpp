//
// Created by esteban on 20/03/19.
//

#include "ServerMessage.hpp"

#include "../lib/rapidjson/prettywriter.h"
#include "../lib/rapidjson/stringbuffer.h"
#include "../lib/rapidjson/document.h"

using namespace rapidjson;

ServerMessage::ServerMessage(){
    id = 1; // By default
    word = "";
};


void ServerMessage::setMessage1_(int id, string gameCode, string msg) {
    this-> id = id,
    this-> gameCode = gameCode;
    this-> msg = msg;
}

void ServerMessage::setMessage2_(int id, string tiles, int your_player) {
    this-> id = id,
    this-> letterTiles = tiles;
    this-> your_Player = your_player;
}

void ServerMessage::setMessage3_(int id, bool accepted, int points) {
    this-> id = id,
    this-> answer = accepted;
    this-> points = points;
}

void ServerMessage::setMessage4_(int id, string word,int firstRow,int firstCol,bool isVertical) {
    this-> id = id,
    this-> exp_request = exp_request;
    this-> word = word;
}

void ServerMessage::setMessage5_(int id, int winner) {
    this->id = id;
    this->winner = winner;
}

/* -------------------------------------------
 *              SERIALIZATION
 * -------------------------------------------*/

template <typename Writer>
void ServerMessage::Serializer1_(Writer &writer) const{
    writer.StartObject();
    writer.String("id");
    writer.Int(id);
    writer.String("gameCode");
    writer.String(gameCode.c_str());
    writer.String("msg");
    writer.String(msg.c_str());
    writer.EndObject();
}

template <typename Writer>
void ServerMessage::Serializer2_(Writer &writer) const {
    writer.StartObject();
    writer.String("id");
    writer.Int(id);
    writer.String("tiles");
    writer.String(letterTiles.c_str());
    writer.String("your_player");
    writer.Int(your_Player);
    writer.EndObject();
}

template <typename Writer>
void ServerMessage::Serializer3_(Writer &writer) const{

    writer.StartObject();
    writer.String("id");
    writer.Int(id);
    writer.String("answer");
    writer.Bool(answer);
    writer.String("points");
    writer.Int(points);
    writer.EndObject();
}

template <typename Writer>
void ServerMessage::Serializer4_(Writer &writer) const{
    writer.StartObject();
    writer.String("id");
    writer.Int(id);
    writer.String("word");
    writer.String(word.c_str());
    writer.String("firstRow");
    writer.Int(firstRow);
    writer.String("firstCol");
    writer.Int(firstCol);
    writer.String("is_Vertical");
    writer.Bool(isVertical);
    writer.EndObject();
}

template <typename Writer>
void ServerMessage::Serializer5_(Writer &writer) const{
    writer.StartObject();
    writer.String("id");
    writer.Int(id);
    writer.String("winner");
    writer.Int(winner);
    writer.EndObject();
}
//------------------------------------------------------

string ServerMessage::serialize() {
    StringBuffer sB;
    Writer<StringBuffer> writer(sB);
    switch (this->id){
        case 1:
            Serializer1_(writer);
            break;
        case 2:
            Serializer2_(writer);
            break;
        case 3:
            Serializer3_(writer);
            break;
        case 4:
            Serializer4_(writer);
            break;
        case 5:
            Serializer5_(writer);
            break;
        default:
            cout<<">> NO HAY NINGUNA COINCIDENCIA"<<endl;
            break;
    }

    return sB.GetString();
}

/* -------------------------------------------
 *              DESERIALIZATION
 * -------------------------------------------*/
ServerMessage* ServerMessage::deserealize(const char* json) {

    ServerMessage* parsedPlayer = new ServerMessage();
    Document doc;
    doc.Parse(json);

    int id = doc["id"].GetInt();

    switch (id){
        case 1: {
            string gameCode = doc["gameCode"].GetString();
            string msg = doc["msg"].GetString();
            parsedPlayer->setMessage1_(id,gameCode,msg);
            break;
        }
        case 2: {
            string letterTiles = doc["tiles"].GetString();
            int player = doc["your_player"].GetInt();
            parsedPlayer->setMessage2_(id, letterTiles,player);
            break;
        }
        case 3: {
            bool accepted = doc["accepted"].GetBool();
            int points = doc["points"].GetInt();
            parsedPlayer->setMessage3_(id, accepted,points);
            break;
        }
        case 4:{
            string pWord = doc["word"].GetString();
            int pFirstRow = doc["firstRow"].GetInt();
            int pFirstCol = doc["firstCol"].GetInt();
            bool pVertical = doc["is_Vertical"].GetBool();

            parsedPlayer->setMessage4_(id, pWord, pFirstRow, pFirstCol, pVertical);
            break;
        }
        case 5:{
            int winner = doc["winner"].GetInt();
            parsedPlayer->setMessage5_(id,winner);
            break;
        }
        default:
            return nullptr;
    }

    return parsedPlayer;
}



string ServerMessage::toString(){
    cout<<"Player[\n word: "<<word<<endl;
    printf(" fr: %d\n fc: %d\n vertical: %c ]\n",firstRow,firstCol,isVertical);
}

/* -------------------------------------------
 *                  GETTERS
 * -------------------------------------------*/

int ServerMessage::getId() const {
    return id;
}

const string &ServerMessage::getWord() const {
    return word;
}

int ServerMessage::getFirstRow() const {
    return firstRow;
}

int ServerMessage::getFirstCol() const {
    return firstCol;
}

bool ServerMessage::isIsVertical() const {
    return isVertical;
}

bool ServerMessage::isAnswer() const {
    return answer;
}

bool ServerMessage::isPass() const {
    return pass;
}

bool ServerMessage::isExp_request() const {
    return exp_request;
}

int ServerMessage::getPoints() const {
    return points;
}

const string &ServerMessage::getGameCode() const {
    return gameCode;
}

const string &ServerMessage::getLetterTiles() const {
    return letterTiles;
}

const string &ServerMessage::getMsg() const {
    return msg;
}

int ServerMessage::getCurrentPlayer() const {
    return currentPlayer;
}

int ServerMessage::getWinner() const {
    return winner;
}

int ServerMessage::getYour_Player() const {
    return your_Player;
}
