#ifndef AVLNODE_HPP
#define AVLNODE_HPP

#include <iostream>
#include <string>
using namespace std;

class AVLNode{
private:

    int height;
    int balanceFactor;
    AVLNode *leftChild;
    AVLNode *rightChild;
    string word;
    
public:

    AVLNode(string word){
        this->leftChild = this->rightChild = nullptr;
        this->word = word;
        this->height = 0;
        this->balanceFactor = 0;
    }

    AVLNode *getLeftChild() {
        return leftChild;
    }

    void setLeftChild(AVLNode *leftChild) {
        this->leftChild = leftChild;
    }

    AVLNode *getRightChild() {
        return rightChild;
    }

    void setRightChild(AVLNode *rightChild) {
        this->rightChild = rightChild;
    }

    string getWord() {
        return word;
    }

    void setWord(string word) {
        this->word = word;
    }

    int getHeight() {
        return height;
    }

    void setHeight(int height) {
        this->height = height;
    }

    int getBalanceFactor() {
        return balanceFactor;
    }

    void setBalanceFactor(int balanceFactor) {
        this->balanceFactor = balanceFactor;
    }
    
};

#endif AVLNODE_HPP
