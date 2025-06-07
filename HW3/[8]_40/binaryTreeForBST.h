#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <assert.h>
//20212861 이재민

template <class btElementType>
class BinaryTree 
{
    public:
        BinaryTree();
        bool isEmpty() const; 
        btElementType getData() const;
        BinaryTree* left(); 
        BinaryTree* right();
        virtual void insert(const btElementType &data); // virtual 함수 사용
        void makeLeft(BinaryTree* T1);
        void makeRight(BinaryTree* T1);

    // 자녀 클래스의 접근을 위해 protected로 바꿈
    protected:
        btElementType treeData;
        bool nullTree;
        BinaryTree* leftChild;
        BinaryTree* rightChild;
};

template <class btElementType>
BinaryTree <btElementType> :: BinaryTree()
{
    nullTree = true;
    leftChild = nullptr;
    rightChild = nullptr;
}

template <class btElementType>
bool BinaryTree <btElementType> :: isEmpty() const
{
    return nullTree;
}

template <class btElementType>
btElementType BinaryTree <btElementType> :: getData() const
{
    assert(!isEmpty());
    return treeData;
}

template <class btElementType>
void BinaryTree <btElementType> :: insert(const btElementType &data)
{
    treeData = data;
    if(nullTree) {
        nullTree = false;
        leftChild = new BinaryTree;
        rightChild = new BinaryTree;
    }
}

template <class btElementType>
BinaryTree<btElementType>* BinaryTree <btElementType> :: left()
{
    assert(!isEmpty()); 
    return leftChild;    
}

template <class btElementType>
BinaryTree<btElementType>* BinaryTree <btElementType> :: right()
{
    assert(!isEmpty()); 
    return rightChild;    
}

template <class btElementType>
void BinaryTree <btElementType> :: makeLeft(BinaryTree* T1)
{
    assert(!isEmpty()); 
    assert(left()->isEmpty());
    delete left(); 
    leftChild = T1;
}

template <class btElementType>
void BinaryTree <btElementType> :: makeRight(BinaryTree* T1)
{
    assert(!isEmpty());
    assert(right()->isEmpty()); 
    delete right(); 
    rightChild = T1;
}
#endif // BINARY_TREE_H
