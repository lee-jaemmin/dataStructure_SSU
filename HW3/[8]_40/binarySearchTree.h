#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "binaryTreeForBST.h"
//20212861 이재민

template <class btElementType>
class BST : public BinaryTree <btElementType>
{   
    public:
        BST();
        virtual void insert(const btElementType &data);
        virtual BinaryTree <btElementType>* retrieve(const btElementType &d);
        // 손자 클래스에서 재사용할 수도 잇으므로 virtual 사용
        // 반환형이 BST* 이면 재사용성 떨어짐 BT* 여야 BT 상속 받은 모든 클래스 사용 가능
        // d를 넣으면 그 주소를 찾아오는 함수
        using BinaryTree <btElementType> :: nullTree;
        using BinaryTree <btElementType> :: treeData;
        using BinaryTree <btElementType> :: leftChild;
        using BinaryTree <btElementType> :: rightChild;
};   

#endif // BINARY_SEARCH_TREE

template <class btElementType>
void BST <btElementType> :: insert(const btElementType &d)
{
    if(nullTree) { // this->BST; BST의 isEmpty == BT의 isEmpty
        nullTree = false;
        leftChild = new BST; // 여기다가 BT를 쓰면 leftChild->retrieve나 insert시 BT의 함수가 호출됨 -> 오류.
        rightChild = new BST;
        treeData = d;
    }

    else if (d == treeData) {
        treeData = d;
    }
    else if (d > treeData) {
        rightChild->insert(d);
    }
    else {
        leftChild->insert(d);
    }
}

template <class btElementType>
BinaryTree <btElementType>* BST <btElementType> :: retrieve(const btElementType &d)
{
    if(nullTree || d == treeData) {
        return this;
    } 
    else if (d < treeData) {
        return ((BST <btElementType> *) leftChild)->retrieve(d);
    }
    else {
        return ((BST <btElementType> *) rightChild)->retrieve(d);
    }
} // recursion으로 구현

template <class btElementType>
BST <btElementType> :: BST() : BinaryTree <btElementType>() {}