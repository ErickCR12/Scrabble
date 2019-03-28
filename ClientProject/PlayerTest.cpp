#include "PlayerTest.hpp"

void PlayerTest::test1(){
    Player *player = new Player();
    cout << "Adding 'a,b,c,d,e' to playerDeck:" << endl;
    player->addLettersToPlayerDeck("a,b,c,d,e");
    player->printPlayerDeck();

    cout << "\nAdding 'v,z' to playerDeck:" << endl;
    player->addLettersToPlayerDeck("v,z");
    player->printPlayerDeck();

    cout << "\nAdding 'a,s,d,r' to playerDeck:" << endl;
    player->addLettersToPlayerDeck("a,s,d,r");
    player->printPlayerDeck();

    cout << "\nAdding letter in position 2 to word: " << endl;
    player->addLetterToWord(2, 0, 0);

}
