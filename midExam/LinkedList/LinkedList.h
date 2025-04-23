typedef int ListElementType; 
//Inorder에 head, tail 관리
class List
{
    public:
        List();
        void insert(const ListElementType &elem);
        void remove(const ListElementType &target);
        bool isEmpty();
        bool isEnd();
        ~List();
    private:
        struct Node;
        typedef Node* Link;
        struct Node {
            ListElementType elem;
            Link next;
        };
        Link head;
        Link tail;
};

List::List()
{
    head = 0;
    tail = 0;
}

bool List::isEmpty()
{
    return (head == 0);    
}

bool List::isEnd()
{
    return (pred->next == 0);
}

void List::insert(const ListElementType &elem)
{
    //새 노드 생성, 데이터 삽입
    Link addedNode = new Node;
    addedNode->elem = elem;
    Link pred(head);

    while(!isEmpty() && !isEnd() && pred->elem < addedNode->elem && pred->next->elem < addedNode->elem) {
        pred = pred->next; 
    }
    
    //최초 혹은 최소
    if(head == pred) {
        // 최초라면
        if(head == 0) {
            tail = addedNode;
        } 
        addedNode->next = head;
        head = addedNode;
    } // 최대일 경우 
    else if (pred->next == 0) { 
        tail = addedNode;
        addedNode->next = pred->next;
        pred->next = addedNode;
    } else { // ordinary
        addedNode->next = pred->next;
        pred->next = addedNode;
    }    
}

void List::remove(const ListElementType &target)
{
    while (head->next != 0 && head->elem != target) {
        head = head->next;
    }

    if(head == 0) return;
    
    Link delNode = head;
    delete delNode;
}

void List::~List()
{
    while (head->next != 0) {
        Link delNode = head;
        head = head->next;
        delete delNode;
    }
}