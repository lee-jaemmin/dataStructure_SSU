#include <iostream>
#include "binarySearchTree.h"


int main() 
{
    typedef BST<int> intBST;
    typedef intBST* intBSTPtr;

    intBSTPtr b(new intBST);

    b->insert(17);
    b->insert(10);
    b->insert(26);
    b->insert(6);
    b->insert(14);
    b->insert(20);
    b->insert(28);
    b->insert(11);
    b->insert(31);
    b->insert(37);
    b->insert(12);

    // is 11 in the tree?
    intBSTPtr get11((BST<int>*)b->retrieve(11));
    if (get11->isEmpty())
        std::cout << "11 not found.\n";
    else
        std::cout << "11 found.\n";

    // is 13 in the tree?
    intBSTPtr get13((BST<int>*)b->retrieve(13));
    if (get13->isEmpty())
        std::cout << "13 not found.\n";
    else
        std::cout << "13 found.\n";

    return 0;
}
