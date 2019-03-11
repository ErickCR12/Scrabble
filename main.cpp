#include <iostream>
#include "DataStructures/AVLTree.hpp"

int main() {
    AVLTree *tree = new AVLTree();
    tree->insertNode("a");
    tree->insertNode("b");
    tree->insertNode("c");
    tree->insertNode("d");
    tree->insertNode("e");
    tree->infixPrint();
}