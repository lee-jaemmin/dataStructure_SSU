#include "cx7-5.h"
#include <assert.h>

//중간에 연결하는 링크드 리스트. + tail 관리

void List::insert(const ListElementType &elem)
{
    Link addedNode = new Node;
    assert(addedNode);
    addedNode->elem = elem;

    if(head == 0 && tail == 0) { // 최초 삽입 시 tail 관리.
        head = addedNode;
        tail = addedNode;
    }

    else if(elem <= head->elem){ // 처음이거나 가장 작은 값일 경우
        addedNode->next = head;
        head = addedNode; // 순서 바뀌면 안 됨. 해보셈. head에 aNode를 이미 넣었기 때문에 자기 자신의 next에 자기를 넣는 꼴임.
    } 
    else {
        Link pred = head; // pred를 맨 앞 원소에 연결
        while(pred->next != 0 && pred->next->elem <= addedNode->elem) {
            pred = pred->next; // 다음 꺼
        }
        addedNode->next = pred->next;
        pred->next = addedNode;
        
        if(addedNode->next == 0) { // 최댓값 tail관리.
            tail = addedNode;
        }
        
    }


}