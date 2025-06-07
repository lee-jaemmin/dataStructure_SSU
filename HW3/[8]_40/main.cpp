#include <iostream>
#include "binarySearchTree.h"
//20212861 이재민
using namespace std;

int main()
{
    typedef BST<int> intBST;
    typedef intBST* intBSTPtr;

    intBSTPtr b = new intBST;
    // 삽입 시작
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

    // 11 있나 확인
    intBSTPtr get11 = (BST<int> *) b -> retrieve(11);
    // 있으면 있는 트리의 주소
    // 없으면 nullTree (맨 밑의 leaf) 주소 반환
    if(get11->isEmpty()) {
        cout << "11 not found" << endl;
    } else {
        cout << "11 found" << endl;
    }

    // 13 있나 확인
    intBSTPtr get13 = (BST<int> *) b -> retrieve(13);    
    if(get13->isEmpty()) {
        cout << "13 not found" << endl;
    } else {
        cout << "13 found" << endl;
    }

    return 0;
}