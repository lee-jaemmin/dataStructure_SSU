#include <iostream>
#include "binaryTree.h"

using namespace std;

int main() {
    typedef BinaryTree <char> charTree;
    typedef charTree* charTreePtr;

    // Create tree from Figure 11-2
    // ======== Left subtree (B's subtree) ========
    // B's left child (D)
    charTreePtr bt1(new charTree);
    bt1->insert('D');
    
    // B's right child (E)
    charTreePtr bt2(new charTree);
    bt2->insert('E');
    
    // Create B node and link subtrees
    charTreePtr bt3(new charTree);
    bt3->insert('B');
    bt3->makeLeft(bt1);
    bt3->makeRight(bt2);

    // ======== Right subtree (C's subtree) ========
    // C's right child (F)
    charTreePtr bt4(new charTree);
    bt4->insert('F');
    
    // Create C node and link subtree
    charTreePtr bt5(new charTree);
    bt5->insert('C');
    bt5->makeRight(bt4);

    // ======== Create root node (A) ========
    charTreePtr bt6(new charTree);
    bt6->insert('A');
    bt6->makeLeft(bt3);
    bt6->makeRight(bt5);

    // ======== Print tree structure ========
    std::cout << "Root contains: " << bt6->getData() << std::endl;
    std::cout << "Left subtree root: " << bt6->left()->getData() << std::endl;
    std::cout << "Right subtree root: " << bt6->right()->getData() << std::endl;
    std::cout << "Leftmost child is: " << bt6->left()->left()->getData() << std::endl;
    std::cout << "Rightmost child is: " << bt6->right()->right()->getData() << std::endl;

    return 0;
}
