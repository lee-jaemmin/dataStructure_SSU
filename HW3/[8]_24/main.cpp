#include <iostream>
#include "binaryTree.h"
// 20212861 이재민
using namespace std;

int main() 
{
    typedef BinaryTree <char> charTree;
    typedef charTree* charTreePtr;

    // 최상단 G 생성
    charTreePtr bt1 = new charTree;
    bt1->insert('G');
    
    // G 왼쪽 자식 E
    charTreePtr bt2 = new charTree;
    bt2->insert('E');

    // G 오른쪽 자식 F
    charTreePtr bt3 = new charTree;
    bt3->insert('F');

    // G에 E,F 붙이기
    bt1->makeLeft(bt2);
    bt1->makeRight(bt3);

    // A 생성
    charTreePtr bt4 = new charTree;
    bt4->insert('A');

    // B 생성
    charTreePtr bt5 = new charTree;
    bt5->insert('B');

    // E에 A, B 붙이기
    bt2->makeLeft(bt4);
    bt2->makeRight(bt5);

    // C 생성
    charTreePtr bt6 = new charTree;
    bt6->insert('C');

    // D 생성
    charTreePtr bt7 = new charTree;
    bt7->insert('D');

    // F에 C, D 붙이기
    bt3->makeLeft(bt6);
    bt3->makeRight(bt7);

    // ======== Print tree structure ========
    std::cout << "Root contains: " << bt1->getData() << std::endl;
    std::cout << "Left subtree root: " << bt1->left()->getData() << std::endl;
    std::cout << "Right subtree root: " << bt1->right()->getData() << std::endl;
    std::cout << "Leftmost child is: " << bt1->left()->left()->getData() << std::endl;
    std::cout << "Rightmost child is: " << bt1->right()->right()->getData() << std::endl;

    return 0;
}
