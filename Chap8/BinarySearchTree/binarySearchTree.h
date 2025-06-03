#ifndef BST_H
#define BST_H

#include "../BinaryTree/binaryTree.h" // BinaryTree<btElementType> 정의 포함

template <class btElementType>
class BST : public BinaryTree<btElementType> 
{
public:
    BST();
    using BinaryTree<btElementType>::nullTree;
    using BinaryTree<btElementType>::treeData;
    using BinaryTree<btElementType>::leftTree;
   using BinaryTree<btElementType>::rightTree;
    virtual void insert(const btElementType& d);
    BinaryTree<btElementType>* retrieve(const btElementType& d);
};

#endif // BST_H

template <class btElementType>
BST<btElementType>::BST() : BinaryTree<btElementType>() { }

template <class btElementType>
void BST<btElementType>::insert(const btElementType& d) 
{
    if (this->nullTree) {
        this->nullTree = false;
        this->leftTree = new BST<btElementType>();
        this->rightTree = new BST<btElementType>();
        this->treeData = d;
    }
    else if (d == this->treeData) {
        this->treeData = d; // 중복된 값은 덮어쓰기
    }
    else if (d < this->treeData) {
        this->leftTree->insert(d);
    }
    else {
        this->rightTree->insert(d);
    }
}

template <class btElementType>
BinaryTree<btElementType>* BST<btElementType>::retrieve(const btElementType& d) 
{
    if (this->nullTree || d == this->treeData) {
        return this;
    }
    else if (d < this->treeData) {
        return ((BST<btElementType>*)this->leftTree)->retrieve(d);
    }
    else {
        return ((BST<btElementType>*)this->rightTree)->retrieve(d);
    }
}
