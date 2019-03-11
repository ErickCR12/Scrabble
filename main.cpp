#include <iostream>
#include "DataStructures/List.hpp"
#include "Dictionary.hpp"

int main() {
    Dictionary *dictionary = new Dictionary();
    if(dictionary->searchInDictionary("zutano")) cout<<"Found.";
    else cout << "Not Found.";
}