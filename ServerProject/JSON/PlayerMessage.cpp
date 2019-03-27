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

void PlayerMessage::setMessage(string word, int fRow,int fCol,bool is_vertical) {
    this-> word = word;
    this-> firstRow = fRow;
    this-> firstCol = fCol;
    this-> isVertical = is_vertical;
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
    writer.String("is_Vertical");
    writer.Bool(isVertical);
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
        bool pVertical = doc["is_Vertical"].GetBool();

        parsedPlayer->setMessage(pWord,pFirstRow,pFirstCol,pVertical);
        return parsedPlayer;
    }



string PlayerMessage::toString(){
    cout<<"Player[\n word: "<<word<<endl;
    printf(" fr: %d\n fc: %d\n vertical: %c ]\n",firstRow,firstCol,isVertical);
}