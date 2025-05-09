#include <iostream>
#include "List.h"
#include <assert.h>

using namespace std;

List::List() //생성자
{
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}


/*void List::insert(ListElementType &elem)
{
    cout << endl;
    Link addedNode = new Node;
    addedNode->elem = elem;

    Link pred = head; // 항상 맨 앞 원소를 가리키게!

    //최초 삽입 시
    if(head == nullptr) {
        addedNode->prev = nullptr;
        addedNode->next = nullptr;
        head = addedNode;
        tail = addedNode;
        cout << "[" << addedNode->elem <<"의 이전 노드]\n";
        cout << addedNode->prev << endl;
        cout << "[" << addedNode->elem <<"의 다음 노드]\n";
        cout << addedNode->next << endl;
        return;
    }

    // 최솟값 삽입 시
    else if(addedNode->elem < pred->elem) {
        addedNode->next = head;
        pred->prev = addedNode;
        addedNode->prev = nullptr;
        head = addedNode;
        cout << "[" << addedNode->elem <<"의 이전 노드]\n";
        cout << addedNode->prev << endl;
        cout << "[" << addedNode->elem <<"의 다음 노드]\n";
        cout << addedNode->next->elem << endl;
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
        cout << "[" << addedNode->elem <<"의 이전 노드]\n";
        cout << addedNode->prev->elem << endl;
        cout << "[" << addedNode->elem <<"의 다음 노드]\n";
        cout << addedNode->next << endl;
        return;
    }

    //중간 삽입
    addedNode->next = pred->next;
    addedNode->prev = pred;
    pred->next->prev = addedNode;
    pred->next = addedNode;
    
    cout << "[" << addedNode->elem <<"의 이전 노드]\n";
    cout << addedNode->prev->elem << endl;
    cout << "[" << addedNode->elem <<"의 다음 노드]\n";
    cout << addedNode->next->elem << endl;    
} */

void List::insert(const ListElementType &elem)
{
    //새 노드 생성, 데이터 삽입
    Link addedNode = new Node;
    addedNode->elem = elem;
    Link pred(head);

    while(!isEmpty() && !isEnd() && pred->elem < addedNode->elem && pred->next->elem < addedNode->elem) {
        pred = pred->next; 
    }
    
    //최초 혹은 최소
    if(head == pred) {
        // 최초라면
        if(head == 0) {
            tail = addedNode;
        } 
        addedNode->next = head;
        head = addedNode;
    } // 최대일 경우 
    else if (pred->next == 0) { 
        tail = addedNode;
        addedNode->next = pred->next;
        pred->next = addedNode;
    } else { // ordinary
        addedNode->next = pred->next;
        pred->next = addedNode;
    }    
}

bool List::first(ListElementType &elem) 
{
    assert(head); // if no head, something is very wrong!
  
    if (head == 0) {
        cout << "배열 원소 없음!" << endl;
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
        cout << "다음 원소 없음!" << endl;
        return false;
    } // no next element available
    else {
    current = current->next;
    elem = current->elem;
    return true;
    }
}

bool List::isEmpty()
{
    return (head == 0);    
}

bool List::isEnd()
{
    return (pred->next == 0);
}