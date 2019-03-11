#ifndef NODE_HPP
#define NODE_HPP

#include "Collector.hpp"
#include "../Objects/LetterTile.hpp"
#include <string>
using namespace std;
class Node{
private:
    LetterTile *letterTile;
    Node *nextNode;

public:
    void* operator new(size_t size) {
        void* node;
        Collector *collector = Collector::getCollector();
        void* reference = collector->getMemoryReference();
        if(reference) {
            node = reference;
        }
        else {
            node = malloc(size);
        }
        return node;
    }

    Node(LetterTile *letterTile) {
        this->letterTile = letterTile;
        nextNode = nullptr;
    }

    LetterTile *getLetterTile(){
        return letterTile;
    }

    void setLetterTile(LetterTile *letterTile) {
        this->letterTile = letterTile;
    }

    Node *getNextNode(){
        return nextNode;
    }

    void setNextNode(Node *nextNode) {
        this->nextNode = nextNode;
    }

    void operator delete(void* nodeToDelete) {
        Collector *collector = Collector::getCollector();
        collector->addMemoryReference(nodeToDelete);
    }
};

void* Collector::getMemoryReference() {
    Node *nodeToReuse = nullptr;
    if(firstReference) {
        nodeToReuse = firstReference;
        firstReference = firstReference->getNextNode();
    }return nodeToReuse;
}

void Collector::addMemoryReference(void* voidPointer) {
    Node *newNode = (Node*) voidPointer;
    newNode->setNextNode(nullptr);
    if(!firstReference) {
        firstReference = newNode;
    }else {
        newNode->setNextNode(firstReference);
        firstReference = newNode;
    }
}

void Collector::printCollector() {
    cout << "Collector ([Memory Address]): \t";
    for(Node *node = firstReference; node != nullptr; node = node->getNextNode())
        cout<<"["<<node<<"] -> ";
    cout << "NULL" << endl;
}


#endif NODE_HPP