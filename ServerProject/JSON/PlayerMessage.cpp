//
// Created by Esteban Alvarado on 20/03/19.
//

#include "PlayerMessage.hpp"
#include "../lib/rapidjson/prettywriter.h"
#include "../lib/rapidjson/stringbuffer.h"
#include "../lib/rapidjson/document.h"

using namespace rapidjson;

PlayerMessage::PlayerMessage(){
    id = 1; // By default
    word = "";
};


void PlayerMessage::setMessage1_(int id,bool answer) {
    this-> id = id,
    this-> answer = answer;
}

void PlayerMessage::setMessage2_(int id,string word, int fRow,int fCol,bool is_vertical) {
    this-> id = id,
    this-> word = word;
    this-> firstRow = fRow;
    this-> firstCol = fCol;
    this-> isVertical = is_vertical;
}

void PlayerMessage::setMessage3_(int id,bool pass) {
    this-> id = id,
    this-> pass = pass;
}

void PlayerMessage::setMessage4_(int id,string word, int fRow,int fCol,bool is_vertical) {
    this-> id = id,
    this-> word = word;
    this-> firstRow = fRow;
    this-> firstCol = fCol;
    this-> isVertical = is_vertical;
}

/* -------------------------------------------
 *              SERIALIZATION
 * -------------------------------------------*/

template <typename Writer>
void PlayerMessage::Serializer1_(Writer &writer) const{
    writer.StartObject();
    writer.String("id");
    writer.Int(id);
    writer.String("answer");
    writer.Bool(answer);
    writer.EndObject();
}

template <typename Writer>
void PlayerMessage::Serializer2_(Writer &writer) const {
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
void PlayerMessage::Serializer3_(Writer &writer) const{

    writer.StartObject();
    writer.String("id");
    writer.Int(id);
    writer.String("pass");
    writer.Bool(pass);
    writer.EndObject();
}

template <typename Writer>
void PlayerMessage::Serializer4_(Writer &writer) const{
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

//------------------------------------------------------

string PlayerMessage::serialize() {
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
        default:
            cout<<">> NO HAY NINGUNA COINCIDENCIA"<<endl;
            break;
    }

    return sB.GetString();
}

/* -------------------------------------------
 *              DESERIALIZATION
 * -------------------------------------------*/
    PlayerMessage* PlayerMessage::deserealize(const char* json) {

        PlayerMessage* parsedPlayer = new PlayerMessage();
        Document doc;
        doc.Parse(json);

        int id = doc["id"].GetInt();

        switch (id){
            case 1: {
                bool answer = doc["answer"].GetBool();
                parsedPlayer->setMessage1_(id, answer);
                break;
            }
            case 2: {
                string pWord = doc["word"].GetString();
                int pFirstRow = doc["firstRow"].GetInt();
                int pFirstCol = doc["firstCol"].GetInt();
                bool pVertical = doc["is_Vertical"].GetBool();

                parsedPlayer->setMessage2_(id, pWord, pFirstRow, pFirstCol, pVertical);
                break;
            }
            case 3: {
                bool pass = doc["pass"].GetBool();
                parsedPlayer->setMessage3_(id, pass);
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
            default:
                return nullptr;
        }

        return parsedPlayer;
    }



string PlayerMessage::toString(){
    cout<<"Player[\n word: "<<word<<endl;
    printf(" fr: %d\n fc: %d\n vertical: %c ]\n",firstRow,firstCol,isVertical);
}