#include "dummyHead.h"
#include <assert.h>
//20212861 이재민 

List::List()
{
    head = new Node;
    assert(head);
    head->next = 0;
    current = 0;
}


void List::insert(const ListElementType &elem)
{
    Link addedNode(new Node);
    addedNode->elem = elem;

    Link pred(head); // pred와 더미헤드 연결
    while(pred->next != 0 && pred->next->elem <= addedNode->elem) {
        pred = pred->next;
    }
    addedNode->next = pred->next;
    pred->next = addedNode;
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

void List::remove(const ListElementType &target)
{
    assert(head);
    Link pred, delNode;

    for(pred = head; pred->next != 0 && pred->next->elem < target; pred = pred->next);

    if(pred&&(pred->next) && (pred->next->elem == target)) {
        delNode = pred -> next;
        pred->next = delNode->next;
        delete delNode;
    }
}

