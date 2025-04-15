#include "cx7-5.h"
#include <assert.h>

//가장 뒤에 연결하는 링크드 리스트.

List::List()
{// 외부 정의. 멤버 변수 초기화
    head = 0;
    tail = 0;
    current = 0;
}

void List::insert(const ListElementType &elem)
{
    Link addedNode = new Node;
    assert(addedNode);
    addedNode->elem = elem;

    if(head == 0){ // head(external pointer)가 null이다. == 처음이다.
        head = addedNode;
    } 
    else {
        tail->next = addedNode; // tail (맨 끝 원소)의 뒤에 addedNode 연결
        tail = addedNode; // tail(맨 끝 원소) == 새 노드
        addedNode->next = 0; // 새 노드의 next를 null로 하여 마지막임을 표현.
    }


}