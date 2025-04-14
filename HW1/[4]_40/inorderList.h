typedef int ListElementType;

//20212861 이재민

class List
{
    public:
        List();
        void insert(ListElementType &elem);
        bool first(ListElementType &elem);
        bool next(ListElementType &elem);
        ~List(); // 소멸자 정의.
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