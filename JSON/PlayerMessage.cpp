//
// Created by Esteban Alvarado on 20/03/19.
//

#include "PlayerMessage.hpp"
#include "../lib/rapidjson/prettywriter.h"
#include "../lib/rapidjson/stringbuffer.h"
#include "../lib/rapidjson/document.h"

using namespace rapidjson;

PlayerMessage::PlayerMessage(){
    word = "";
};

void PlayerMessage::setMessage(string word, int fRow,int fCol,int lRow, int lCol) {
    this-> word = word;
    this-> firstRow = fRow;
    this-> firstCol = fCol;
    this-> lastRow = lRow;
    this-> lastCol = lCol;
}

/* -------------------------------------------
 *              SERIALIZATION
 * -------------------------------------------*/

template <typename Writer>
void PlayerMessage::Serializer(Writer &writer) const {

    writer.StartObject();
    writer.String("word");
    writer.String(word.c_str());
    writer.String("firstRow");
    writer.Int(firstRow);
    writer.String("firstCol");
    writer.Int(firstCol);
    writer.String("lastRow");
    writer.Int(lastRow);
    writer.String("lastCol");
    writer.Int(lastCol);
    writer.EndObject();
}

string PlayerMessage::serialize() {
    StringBuffer sB;
    Writer<StringBuffer> writer(sB);
    Serializer(writer);
    return sB.GetString();
}

/* -------------------------------------------
 *              DESERIALIZATION
 * -------------------------------------------*/
    PlayerMessage* PlayerMessage::deserealize(const char* json) {

        PlayerMessage* parsedPlayer = new PlayerMessage();
        Document doc;
        doc.Parse(json);

        string pWord = doc["word"].GetString();
        int pFirstRow = doc["firstRow"].GetInt();
        int pFirstCol = doc["firstCol"].GetInt();
        int pLastRow = doc["lastRow"].GetInt();
        int pLastCol = doc["lastCol"].GetInt();

        parsedPlayer->setMessage(pWord,pFirstRow,pFirstCol,pLastRow,pLastCol);
        return parsedPlayer;
    }



string PlayerMessage::toString(){
    cout<<"Player[\n word: "<<word<<endl;
    printf(" fr: %d\n fc: %d\n lr: %d\n lc: %d\n]\n",firstRow,firstCol,lastRow,lastCol);
}