typedef int ListElementType;


class List {
    public: 
        List(); // 생성자 선언만 함. 외부에서 정의할 예정.
        void insert(const ListElementType &elem);
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