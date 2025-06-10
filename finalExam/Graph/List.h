#ifndef LIST_H
#define LIST_H
#include "Graph.h"
#include <assert.h>

template <class ListElementType>
class ListIter; // 클래스 선언

template <class ListElementType>
class List 
{
    public: 
        List() : head(0) {};
        virtual void insert(const ListElementType &elem);
        bool first(ListElementType &elem);
        bool next(ListElementType &elem);
        friend class ListIter <ListElementType>;

    protected:
        struct Node;
        typedef Node* Link;
        struct Node 
        {
            ListElementType elem;
            Link next;
        };
        Link head;
};

template <class ListElementType>
class ListIter
{
protected:
    const List <ListElementType> &myList;
    typename List <ListElementType>:: Link iterPtr;
    ListElementType myEndFlag;

public:
    ListIter(const List <ListElementType> &l, ListElementType endFlag)
        : myList(l), myEndFlag(endFlag), iterPtr(0) {};

    virtual ListElementType operator++(); // 지금 가리키는 값 반환
};

template <class ListElementType>
ListElementType ListIter <ListElementType> :: operator++()
{
    if(iterPtr == nullptr) {
        iterPtr = myList.head;
    } else {
        iterPtr = iterPtr->next;
    }
    if(iterPtr) {
        return iterPtr->elem;
    } else {
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
}
#endif