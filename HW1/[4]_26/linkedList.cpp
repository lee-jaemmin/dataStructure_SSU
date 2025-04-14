#include "linkedList.h"
#include <assert.h>

//20212861 이재민민

List::List()
{
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

void List::insert(ListElementType &elem)
{
    Link addedNode = new Node;
    addedNode->elem = elem;

    /* if(head == 0) { // 최초 삽입이다.
        head = addedNode;
    }
    else {
        tail->next = addedNode;
    }
    tail = addedNode;
    addedNode->next = nullptr; */

    // head에 추가하는 과정 구현
    
    //최초 삽입이면 
    if(head == nullptr) {
        tail = addedNode;
        tail->next = nullptr;
    }
    else {
        addedNode->next = head;
    }
    head = addedNode;
}

bool List::first(ListElementType &elem) // 처음 호출 됐을 때.
{
    if(head == 0)  { // 비어있다면 false
        return false;
    } 
    else {
        elem = head->elem;
        current = head;
        return true;
    }
        
}

bool List::next(ListElementType &elem)
{
    assert(current);

    if(current->next == 0) {// current가 끝이라면~
        return false;
    }
    else {
        current = current->next;
        elem = current->elem;
        return true;
    }
}

List::~List()
{
    // 맨 앞부터 소멸시킨다.
    while(head != 0) {
        Link delNode; // 삭제할 주소의 노드 포인터 선언
        delNode = head; // head 주소를 delNode에 넣어줌
        head = head->next; // head 하나 증가.
        delete delNode;
    }

}