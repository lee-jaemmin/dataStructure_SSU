//20212861 이재민

typedef int ListElementType;

const int maxlistSize = 1000;

class List
{
    public:
        List(); // 생성자 선언..
        bool first(ListElementType &elem); // 첫번째 가져오는 함수 선언.
        bool next(ListElementType &elem); // 다음꺼 가져오는 함수 선언.
        bool prev(ListElementType &elem); // 이전꺼 가져오는 함수 선언.
        void insert(ListElementType &elem); // 삽입 하는 함수 선언.

    private:
        
        
        struct Node; // Node를 먼저 선언해야 Node*을 쓰겠죠?
        typedef Node* Link; // Node* 를 Link라고 지정

        struct Node {
            ListElementType elem;
            Link next; // 다음 노드 주소를 담을 포인터
            Link prev; // 이전 노드 주소를 담을 포인터
        };

        Link head;
        Link current;
        Link tail;

};