#include "PlayerTest.hpp"

//void PlayerTest::test1(){
//    Player *player = new Player();
//    cout << "Adding 'a,b,c,d,e' to playerDeck:" << endl;
//    player->addLettersToPlayerDeck("a,b,c,d,e");
//    player->printPlayerDeck();

//    cout << "\nAdding 'v,z' to playerDeck:" << endl;
//    player->addLettersToPlayerDeck("v,z");
//    player->printPlayerDeck();

//    cout << "\nAdding 'a,s,d,r' to playerDeck:" << endl;
//    player->addLettersToPlayerDeck("a,s,d,r");
//    player->printPlayerDeck();

//    cout << "\nAdding letter in position 2 to word: " << endl;
//    player->addLetterToWord(2, 0, 0);

//}

void PlayerTest::test1() {

    cout<<"-------------- PLAYER TEST 1 --------------"<<endl;

    cout<<"\nCreando player1..."<<endl;
    Player* player1 = new Player();
    cout<<"Creando player2..."<<endl;
    Player* player2 = new Player();

    cout<<"Llenando deck de player1..."<<endl;
    player1->addLettersToPlayerDeck("c,a,b,a,ll,o,s");

    cout<<"Llenando deck de player2..."<<endl;
    player2->addLettersToPlayerDeck("f,e,o,s,v,r,c");

    cout<<"Deck player1: ";
    player1->printPlayerDeck();
    cout<<"Deck player2: ";
    player2->printPlayerDeck();
}

// Prueba de ingreso de palabras
void PlayerTest::test2() {
    cout<<"-------------- PLAYER TEST 2 --------------"<<endl;

    cout<<"\nCreando player1..."<<endl;
    Player* player1 = new Player();

    cout<<"Llenando deck de player1..."<<endl;
    player1->addLettersToPlayerDeck("c,a,b,a,ll,o,s");


    cout<<"Deck player1: ";
    player1->printPlayerDeck();

    int index = 0;
    while(index < 7){
        player1->addLetterToWord(index, 0, index);
        index++;
    }
//    bool ready = true;
//    while(ready && player1->getAmountOfLetterTiles()>0){
//        int position,row,col;
//        cout<<"* Ingrese la posicion de la letra: ";
//        cin>>position;
//        cout<<"* Ingrese la fila: ";
//        cin>>row;
//        cout<<"* Ingrese la columna: ";
//        cin>>col;
//        player1->addLetterToWord(position,row,col);

//        string ans;
//        cout<<"* ¿Desea añadir otra letra? S/N ";
//        cin>>ans;

//        if(ans == "N") ready = false;
//    }

    player1->sendMyWord();


}
