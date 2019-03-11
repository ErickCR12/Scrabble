#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "AVLNode.hpp"

class AVLTree{

private: 
    AVLNode *root;
    int size;

public:

    AVLTree(){
        this->root = nullptr;
        this->size = 0;
    }
    
    void insertNode(string word){
        AVLNode *newNode = new AVLNode(word);
        insertNode(newNode);
        setTreeHeight();
        setBalanceFactor();
        balanceTree(root, word);
    }

    void insertNode(AVLNode *newNode){
        if(!searchNode(newNode->getWord())){
            if(isEmpty()) root = newNode;
            else insertNode(newNode, root);
            size++;
        }
    }

    void insertNode(AVLNode *newNode, AVLNode *actualNode){
        if(newNode->getWord() > actualNode->getWord()){
            if(!actualNode->getRightChild()) actualNode->setRightChild(newNode);
            else insertNode(newNode, actualNode->getRightChild());
        }else{
            if(!actualNode->getLeftChild())actualNode->setLeftChild(newNode);
            else insertNode(newNode, actualNode->getLeftChild());
        }
    }

    AVLNode *searchNode(string word){
        AVLNode *node = root;
        while(node != nullptr){
            if(node->getWord() == word) return node;
            else if(node->getWord() < word) node = node->getRightChild();
            else node = node->getLeftChild();
        }
        return nullptr;
    }
    
    void deleteNode(string word){
        AVLNode *nodeToDelete = searchNode(word);
        AVLNode *node = nodeToDelete;
        AVLNode *fatherNode = getFatherNode(word);
        if (nodeToDelete != nullptr){
            if (node->getRightChild() == nullptr) node = node->getLeftChild();
            else if (node->getLeftChild() == nullptr) node = node->getRightChild();
            else{
                AVLNode *temp = findMaxNode(node->getLeftChild());
                AVLNode *previousTemp = getFatherNode(temp->getWord());
                node->setWord(temp->getWord());
                if(previousTemp == node) previousTemp->setLeftChild(temp->getLeftChild());
                else previousTemp->setRightChild(temp->getLeftChild());
            }
            if (nodeToDelete == root) root = node;
            else if (fatherNode->getLeftChild() == nodeToDelete) fatherNode->setLeftChild(node);
            else fatherNode->setRightChild(node);
            size--;
        }
        setTreeHeight();
        setBalanceFactor();
        balanceTree(root, word);
    }
    
    void balanceTree(AVLNode *node, string word){
        if(node != nullptr){
           if(node->getWord() < word) balanceTree(node->getRightChild(), word);
           else balanceTree(node->getLeftChild(), word);
           int balanceFactor = node->getBalanceFactor();
           if(balanceFactor > 1 || balanceFactor < -1){
               defineRotationType(node);
           }
        }
        setTreeHeight();
        setBalanceFactor();
    }
    
    void defineRotationType(AVLNode *node){
        int balanceFactor = node->getBalanceFactor();
        if(balanceFactor < -1){
            if(node->getLeftChild()->getBalanceFactor() < 0) this->rightRotation(node);
            else this->leftRightDoubleRotation(node);
        }else if(balanceFactor > 1){
            if(node->getRightChild()->getBalanceFactor() > 0)this->leftRotation(node);
            else this->rightLeftDoubleRotation(node);
        }
    }
    
    void leftRotation(AVLNode *unbalancedNode){
        AVLNode *fatherNode = getFatherNode(unbalancedNode->getWord());
        AVLNode *rightChild = unbalancedNode->getRightChild();
        AVLNode *grandChildNode = rightChild->getLeftChild();
        rightChild->setLeftChild(unbalancedNode);
        rightChild->getLeftChild()->setRightChild(grandChildNode);
        if(unbalancedNode == root)root = rightChild;
        else if(fatherNode->getLeftChild() == unbalancedNode) fatherNode->setLeftChild(rightChild);
        else fatherNode->setRightChild(rightChild);
    }
    
    void rightRotation(AVLNode *unbalancedNode){
        AVLNode *fatherNode = getFatherNode(unbalancedNode->getWord());
        AVLNode *leftChild = unbalancedNode->getLeftChild();
        AVLNode *grandChildNode = leftChild->getRightChild();
        leftChild->setRightChild(unbalancedNode);
        leftChild->getRightChild()->setLeftChild(grandChildNode);
        if(unbalancedNode == root)root = leftChild;
        else if(fatherNode->getLeftChild() == unbalancedNode) fatherNode->setLeftChild(leftChild);
        else fatherNode->setRightChild(leftChild);
    }
    
    void leftRightDoubleRotation(AVLNode *unbalancedNode){
        leftRotation(unbalancedNode->getLeftChild());
        rightRotation(unbalancedNode);
    }
    
    void rightLeftDoubleRotation(AVLNode *unbalancedNode){
        rightRotation(unbalancedNode->getRightChild());
        leftRotation(unbalancedNode);
    }

    int getMaxDepth(AVLNode *node){
        if(node != nullptr){
            int leftDepth = getMaxDepth(node->getLeftChild());
            int rightDepth = getMaxDepth(node->getRightChild());
            if(leftDepth > rightDepth) return ++leftDepth;
            else return ++rightDepth;
        }else return 0;
    }
    
    void setTreeHeight(){
        setTreeHeight(root);
    }
    
    void setTreeHeight(AVLNode *node){
        if(node != nullptr){
            int maxDepth = getMaxDepth(node);
            node->setHeight(maxDepth);
            setTreeHeight(node->getLeftChild());
            setTreeHeight(node->getRightChild());
        }
    }
    
    void setBalanceFactor(){
        setBalanceFactor(root);
    }
    
    void setBalanceFactor(AVLNode *node){
        if(node != nullptr){
            AVLNode *leftChild = node->getLeftChild();
            AVLNode *rightChild = node->getRightChild();
            int leftHeight = (leftChild) ? leftChild->getHeight() : 0;
            int rightHeight = (rightChild) ? rightChild->getHeight() : 0;
            int balanceFactor = rightHeight - leftHeight;
            node->setBalanceFactor(balanceFactor);
            setBalanceFactor(leftChild);
            setBalanceFactor(rightChild);
        }
    }

    AVLNode *findMaxNode(AVLNode *node){
        while(node->getRightChild() != nullptr) node = node->getRightChild();
        return node;
    }

    AVLNode *getFatherNode(string data){
        for(AVLNode *node = root; node != nullptr;
            node = (node->getWord() < data) ? node->getRightChild() : node->getLeftChild()){
            if((node->getRightChild() != nullptr && node->getRightChild()->getWord() == data) ||
               (node->getLeftChild() != nullptr && node->getLeftChild()->getWord() == data))
                return node;
        }
        return nullptr;
    }

    AVLNode *getRoot() {
        return root;
    }

    void setRoot(AVLNode *root) {
        this->root = root;
    }

    int getSize() {
        return size;
    }

    void setSize(int size) {
        this->size = size;
    }

    bool isEmpty(){
        return root == nullptr;
    }

    void infixPrint(){
        infixPrint(root, "");
    }

    void infixPrint(AVLNode *node, string tabulation){
        if(node){
            infixPrint(node->getRightChild(), tabulation + "\t");
            cout << tabulation << node->getWord() << endl;
            infixPrint(node->getLeftChild(), tabulation + "\t");
        }
    }
};

#endif AVLTREE_HPP
