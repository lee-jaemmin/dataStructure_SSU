#include "dummyHead.h"
//20212861 이재민 

List::List()
{
    head = nullptr;
    tail = nullptr;
    current = nullptr;

    // 더미 헤드 생성
    Link dummyHead = new Node; // dummy head 생성
    head->next = nullptr;
    head = dummyHead;
    tail = dummyHead;
    //head, tail dummyhead로 
}


void List::insert(const ListElementType &elem)
{
    Link addedNode = new Node; // 새 노드 생성
    assert(addedNode); // 잘 생성됐나 확인
    addedNode->elem = elem;

    tail->next = addedNode; // dummyHead의 next에 새 노드 연걸
    tail = addedNode; // tail에 새 노드 저장 
    addedNode->next = nullptr; // 새 노드 next에 null
}

bool List::first(ListElementType &elem)
{
    if(head->next == 0) { // 아무것도 없으면 == dummyHead만 있고, dummy의 next는 null
        return false;
    }

    else {
        current = head->next;
        elem = current->elem;
        return true;
    }
    
}   

    bool List::next(ListElementType &elem)
    {
        if(current->next == nullptr) { // 더 이상 뒤로 갈 수 없으면
            return false;
        }
        else {//다음 꺼 불러올 때
            current = current->next; // 현재 위치를 한 칸 뒤로 이동
            elem = current->elem;
            return true;
        }
    }

List::~List()
{
    while(head != 0) {
        Link delNode(head);
        head = head->next;
        delete delNode;
    }
}