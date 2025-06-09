#ifndef LIST_H
#define LIST_H
#include <assert.h>
//20212861 이재민

template <class ListElementType>
class ListIter; // nextNeighbor을 가진 클래스

template <class ListElementType>
class List
{
    public:
        List() : head(0) {}; // 원래는 선언만 해놓고 정의부에서 head 초기화.
                             // 이젠 초기화 리스트로 바로 head 초기화.
        virtual void insert(const ListElementType &elem);
        friend class ListIter <ListElementType>; // friend로 선언함으로써 free access를 얻어냄
                                                 // 많이 쓰는 List 클래스는 유지하면서도 새롭게 정의 가능.   
    protected:
        struct Node;
        typedef Node* Link;
        struct Node
        {
            Link next;
            ListElementType elem;
        };

        Link head;
};

template <class ListElementType>
class ListIter
{
    public:
        ListIter(const List <ListElementType> &l, ListElementType endFlag)
        : myList(l), myEndFlag(endFlag), iterPtr(0) {}; // myList에 l 연결 (주소 넘겨줌)

        virtual ListElementType operator++(); // operator overloading: 클래스 객체에 대해 연산이 가능!

    protected:
        const List <ListElementType> &myList; // List class에 접근할 레퍼런스 변수 선언
        typename List <ListElementType> :: Link iterPtr; // current 역할
        // 외부 클래스 (ListIter)에서 내부 타입 (typedef Node* Link)을 이용하기 위해서
        // 클래스명::타입명 과 같이 적어야 한다.
        ListElementType myEndFlag; // vertex 개수
};
#endif

template <class ListElementType>
ListElementType ListIter <ListElementType> :: operator++()
{
    // 만약 처음이면
    if(iterPtr == nullptr) {
        iterPtr = myList.head; // iterPtr에 내 리스트 head 연결
    } else {
        iterPtr = iterPtr->next; // 아니면 다음 꺼
    }
    // null이 아니면
    if(iterPtr) {
        return iterPtr->elem;
    } else { // null 이면 == 다 끝난 경우밖에 없음.
        return myEndFlag;
    }
}

template <class ListElementType>
void List<ListElementType> :: insert(const ListElementType &elem)
{
    Link addedNode = new Node;
    assert(addedNode);
    addedNode->elem = elem;
    addedNode->next = head; 
    head = addedNode;
} // 맨 앞에 새 노드 추가.