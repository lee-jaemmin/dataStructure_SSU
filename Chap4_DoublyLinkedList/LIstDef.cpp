#include <iostream>
#include "List.h"
#include <assert.h>


List::List() //생성자
{
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}


void List::insert(ListElementType &elem)
{
    Link addedNode = new Node;
    addedNode->elem = elem;

    Link pred = head; // 항상 맨 앞 원소를 가리키게!

    //최초 삽입 시
    if(head == nullptr) {
        addedNode->prev = nullptr;
        addedNode->next = nullptr;
        head = addedNode;
        tail = addedNode;
        return;
    }

    // 최솟값 삽입 시
    else if(addedNode->elem < pred->elem) {
        addedNode->next = head;
        pred->prev = addedNode;
        addedNode->prev = nullptr;
        head = addedNode;
        return;
    }

  
    while(pred->next != nullptr && pred->next->elem <= addedNode->elem) {
        pred = pred->next;
    }

    //최댓값 삽입 시
    if(pred->next == nullptr) {
        addedNode->prev = tail;
        tail->next = addedNode;
        addedNode->next = nullptr;
        tail = addedNode;
        return;
    }

    //중간 삽입
    addedNode->next = pred->next;
    addedNode->prev = pred;
    pred->next->prev = addedNode;
    pred->next = addedNode;
    

        
}

bool List::first(ListElementType &elem) 
{
    assert(head); // if no head, something is very wrong!
  
    if (head == 0) {
        return false;
    }
    else {
    current = head;
    elem = current->elem;
    return true;
    }    
}



bool List::next(ListElementType &elem)
{
    assert(current);
 
    // After each call, current always points to the item
    // that next has just returned.
    if (current->next == 0){
        return false;
    } // no next element available
    else {
    current = current->next;
    elem = current->elem;
    return true;
    }
}