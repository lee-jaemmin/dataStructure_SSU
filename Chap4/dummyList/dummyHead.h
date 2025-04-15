//20212861 이재민 

typedef int ListElementType;

class List
{
    public:
        List();
        void insert(const ListElementType &elem);
        bool first(ListElementType &elem);
        bool next(ListElementType &elem);
        ~List();


    private:
        struct Node;
        typedef Node* Link;

        struct Node {
            ListElementType elem;
            Link next;
        };

        Link head;
        Link current;
        Link tail;
};