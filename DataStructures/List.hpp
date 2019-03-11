#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Node.hpp"
using namespace std;

class List {
private:
    Node *head;

public:

    List() {
        head = nullptr;
    }

    void addHead(LetterTile *letterTile) {
        Node *newHead = new Node(letterTile);
        newHead->setNextNode(head);
        head = newHead;
    }

    void deleteNode(LetterTile *letterTile) {
        Node* node = head;
        if(!searchNode(letterTile)) return;
        if(node->getLetterTile()->getLetter() == letterTile->getLetter()){
            head = node->getNextNode();
            delete(node);
        }else{
            while(node->getNextNode()->getLetterTile()->getLetter() != letterTile->getLetter())
                node = node->getNextNode();
            Node *nodeToDelete = node->getNextNode();
            node->setNextNode(nodeToDelete->getNextNode());
            delete(nodeToDelete);
        }
    }

    Node *searchNode(LetterTile *letterTile) {
        for(Node *node = head; node; node = node->getNextNode()) {
            if (node->getLetterTile()->getLetter().compare(letterTile->getLetter()) == 0) return node;
        }return nullptr;
    }

    Node *getHead(){
        return head;
    }

    void setHead(Node *head) {
        this->head = head;
    }

    void printList() {
        cout << "List ([Data | Memory Address]): ";
        for(Node *node = head; node != nullptr; node = node->getNextNode())
            cout<<node->getLetterTile()->getLetter()<<endl;
        cout << "NULL" << endl;
    }
};

#endif LIST_HPP
