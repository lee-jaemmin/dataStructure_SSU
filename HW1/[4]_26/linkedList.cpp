#include <iostream>
#include "linkedList.h"
#include <assert.h>

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

    if(head == 0) { // 최초 삽입이다.
        head = addedNode;
        tail = addedNode;
    }
    else {
        tail->next = addedNode;
        addedNode->next = nullptr;
        tail = addedNode;
    }
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