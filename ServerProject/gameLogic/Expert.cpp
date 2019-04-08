//
// Created by esteban on 07/04/19.
//

#include "Expert.hpp"

Expert::Expert() {

}

void Expert::sendMessage(string word) {

    //Esta línea es la que envía el SMS al teléfono de @OscarAraya18
    //El archivo .py se encuente en el directorio cmake-build-debug

    const char* requestedWord = word.c_str();
    const char* defaultMessage = "python sendSms.py ";

    string completeMessage = defaultMessage;
    completeMessage += requestedWord;

    const char* sendCommand = completeMessage.c_str();

    system(sendCommand);
    cout<<">>SMS sended succesfully"<<endl;
}

bool Expert::getResponse() {
    string ans = "";
    // Aqui va el app
    return false;
}
