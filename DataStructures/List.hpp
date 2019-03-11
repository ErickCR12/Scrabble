#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Node.hpp"
using namespace std;

class List {
private:
    Node *head;
    int length;
    int amountOfLetters;

public:

    List() {
        head = nullptr;
        length = 0;
        amountOfLetters = 100;
    }

    void addHead(LetterTile *letterTile) {
        Node *newHead = new Node(letterTile);
        newHead->setNextNode(head);
        head = newHead;
        length++;
    }

    void deleteNode(LetterTile *letterTile) {
        Node* node = head;
        if(!searchNode(letterTile->getLetter())) return;
        if(node->getLetterTile()->getLetter() == letterTile->getLetter()){
            head = node->getNextNode();
            delete(node);
        }else{
            while(node->getNextNode()->getLetterTile()->getLetter() != letterTile->getLetter())
                node = node->getNextNode();
            Node *nodeToDelete = node->getNextNode();
            node->setNextNode(nodeToDelete->getNextNode());
            delete(nodeToDelete);
        }length--;
    }

    Node *searchNode(string letter) {
        for(Node *node = head; node; node = node->getNextNode()) {
            if (node->getLetterTile()->getLetter().compare(letter) == 0) return node;
        }return nullptr;
    }

    Node *getHead(){
        return head;
    }

    int getAmountOfLetters(){
        return amountOfLetters;
    }

    void setAmountOfLetters(int amountOfLetters) {
        this->amountOfLetters = amountOfLetters;
    }

    void decreaseAmountOfLetters(){
        amountOfLetters--;
    }

    void setHead(Node *head) {
        this->head = head;
    }

    int getLength(){
        return length;
    }

    void setLength(int length) {
        this->length = length;
    }

    void printList() {
        cout << "List ([Data | Memory Address]): ";
        for(Node *node = head; node != nullptr; node = node->getNextNode())
            cout<<node->getLetterTile()->getLetter()<<endl;
        cout << "NULL" << endl;
    }
};

#endif LIST_HPP
