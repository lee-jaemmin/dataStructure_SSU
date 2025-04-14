#include <iostream>

typedef int ListElementType;


class List
{
    public:
        List();
        void insert(ListElementType &elem);
        bool first(ListElementType &elem);
        bool next(ListElementType &elem);
    private:
        struct Node;
        typedef Node* Link;
        struct Node {
            ListElementType elem;
            Link next;
        };

        Link head;
        Link tail;
        Link current;
};