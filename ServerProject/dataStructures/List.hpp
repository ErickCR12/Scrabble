#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Node.hpp"

/// @brief Implementation of a simple linked list formed by Node objects.
/// @note ** This list has a memory manager called collector.
class List {
private:

    Node *head; //!< @brief First Node instance in the List.
    int length; //!< @brief Amount of nodes in the List.

public:

    //! @brief Constructor for List class.
    List() {
        head = nullptr;
        length = 0;
    }

    //! @brief Adds node at the end of the list.
    //! @param letterTile LetterTile instance that is going to be stored in a Node and added in the list
    void addNode(LetterTile *letterTile) {
        Node *newNode = new Node(letterTile);
        if(!head) head = newNode;
        else{
            Node *node = head;
            while(node->getNextNode()) node = node->getNextNode();
            node->setNextNode(newNode);
        }length++;
    }

    //! This method searches the received parameter in the list and removes it if exist. If it doesn't exists,
    //! returns void and nothing is deleted.
    //! @brief Method responsible for deleting nodes from the list.
    //! @param letterTile LetterTile instance that is going to be removed from the list
    void deleteNode(LetterTile *letterTile) {
        if(!searchNode(letterTile->getLetter())) return;
        Node* node = head;
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

    //! @brief Searches node in the list.
    //! @param letter string with letter to look for in the list.
    Node *searchNode(string letter) {
        for(Node *node = head; node; node = node->getNextNode()) {
            if (node->getLetterTile()->getLetter().compare(letter) == 0) return node;
        }return nullptr;
    }

    //! @brief Returns the head attribute.
    //! @return Node type value stored in head.
    Node *getHead(){
        return head;
    }

    //! @brief Stores the received parameter on head attribute.
    //! @param head Node type value to store on head attribute.
    void setHead(Node *head) {
        this->head = head;
    }

    //! @brief Returns the length attribute.
    //! @return int type value stored in length.
    int getLength(){
        return length;
    }

    //! @brief Stores the received parameter on length attribute.
    //! @param length int type value to store in length attribute.
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
