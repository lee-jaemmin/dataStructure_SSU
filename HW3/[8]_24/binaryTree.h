#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <assert.h>
//20212861 이재민

template <class btElementType>
class BinaryTree 
{
    public:
        BinaryTree();
        bool isEmpty() const; // const: 멤버 변수의 값을 바꾸지 않겠다고 약속
        btElementType getData() const;
        BinaryTree* left(); // return address of left child
        BinaryTree* right();
        void insert(const btElementType &data);
        void makeLeft(BinaryTree* T1);
        void makeRight(BinaryTree* T1);

    private:
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
    // 두 가지 케이스: 비어있는 트리이거나 이미 차있는 트리
    // 삽입은 공통 실행 (갱신 vs 새로운 삽입)
    treeData = data;
    // 만약 빈 트리였으면 
    if(nullTree) {
        nullTree = false;
        leftChild = new BinaryTree;
        rightChild = new BinaryTree;
        // 새로운 BT 객체를 만들고 각 자식에 주소 넣어주기
    }
}

template <class btElementType>
//자료형: 가변타입을 가진 BinaryTree의 주소다.
BinaryTree<btElementType>* BinaryTree <btElementType> :: left()
{
    assert(!isEmpty()); // EmptyTree이면 안되니까
    return leftChild;    
}

template <class btElementType>
BinaryTree<btElementType>* BinaryTree <btElementType> :: right()
{
    assert(!isEmpty()); // EmptyTree이면 안되니까
    return rightChild;    
}

template <class btElementType>
void BinaryTree <btElementType> :: makeLeft(BinaryTree* T1)
{
    assert(!isEmpty()); // 나는 Empty가 아니고
    assert(left()->isEmpty()); // leftchild는 비어있어야 해
    delete left(); // 왼쪽 자식 (현재 nullTree인) 지우기
    leftChild = T1;
}

template <class btElementType>
void BinaryTree <btElementType> :: makeRight(BinaryTree* T1)
{
    assert(!isEmpty()); // 나는 Empty가 아니고
    assert(right()->isEmpty()); // leftchild는 비어있어야 해
    delete right(); // 왼쪽 자식 (현재 nullTree인) 지우기
    //댕글링 포인터
    rightChild = T1;
}
#endif // BINARY_TREE_H
