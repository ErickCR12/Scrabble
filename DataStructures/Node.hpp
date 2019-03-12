#ifndef NODE_HPP
#define NODE_HPP

#include "Collector.hpp"
#include "../Objects/LetterTile.hpp"
#include <string>
using namespace std;

//! @brief Structure that stores a LetterTile type attribute and a pointer to the next node.
class Node{
private:

    LetterTile *letterTile; //!< @brief LetterTile instance stored in this node.
    Node *nextNode;         //!< @brief Pointer to a Node instance called nextNode

public:
    /// The new operator is overloaded to access the collector in search of a recycled
    /// memory space, if it is not available a new space is reserved in the memory.
    /// @brief New operator overloaded
    /// @param size Size that the compiler assigns to the Node class.
    /// @return Memory address where the Node is going to be stored.
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

    /// @brief Constructor for Node class.
    /// @param letterTile LetterTile type object to store in this node.
    Node(LetterTile *letterTile) {
        this->letterTile = letterTile;
        nextNode = nullptr;
    }

    //! @brief Returns the letterTile attribute.
    //! @return LetterTile type value stored in letterTile.
    LetterTile *getLetterTile(){
        return letterTile;
    }

    //! @brief Stores the received parameter on letterTile attribute.
    //! @param letterTile LetterTile type value to store in letterType.
    void setLetterTile(LetterTile *letterTile) {
        this->letterTile = letterTile;
    }

    //! @brief Returns the nextNode attribute.
    //! @return Node type value stored in nextNode.
    Node *getNextNode(){
        return nextNode;
    }

    //! @brief Stores the received parameter on nextNode attribute.
    //! @param nextNode Node type value to store in nextNode.
    void setNextNode(Node *nextNode) {
        this->nextNode = nextNode;
    }

    /// @brief It is responsible for sending the memory nodes to the Collector to be recycled.
    /// @param memory Memory space that will be stored for later use.
    void operator delete(void* nodeToDelete) {
        Collector *collector = Collector::getCollector();
        collector->addMemoryReference(nodeToDelete);
    }
};

Node* Collector::getMemoryReference() {
    Node *nodeToReuse = nullptr;
    if(firstReference) {
        nodeToReuse = firstReference;
        firstReference = firstReference->getNextNode();
    }return nodeToReuse;
}

void Collector::addMemoryReference(void* memory) {
    Node *newNode = (Node*) memory;
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