#include <iostream>
#include "cx7-10.h"
#include <assert.h>

// dummy head 만들기.


List::List()
{
    head = new Node;
    assert(head);
    head->next = 0;
    current = 0;
}


void List::remove(const ListElementType &target)
{
    assert(head);
    Link pred, delNode;
    for(pred = head; pred->next != 0 && pred->next->elem < target; pred = pred->next);

    if(pred && (pred->next) && (pred->next->elem == target)) {
        delNode = pred->next;
        pred->next = delNode -> next;
        delete delNode;
    }
}
