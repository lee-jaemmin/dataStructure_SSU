template <class queueElementType>
class Queue
{
    public:
        Queue();
        void enqueue(queueElementType e);
        queueElementType dequeue();
        queueElementType front();
        bool isEmpty();
        ~Queue();

    private:
        struct Node;
        typedef Node* nodePtr;
        struct Node {
            queueElementType data;
            nodePtr next;
        };
        int f;
        int r;
};

template <class queueElementType>
Queue <queueElementType>::Queue()
{
    f = 0;
    r = 0;
}


template <class queueElementType>
void Queue <queueElementType>::enqueue(queueElementType elem)
{
    nodePtr n = new Node;
    assert(n); // n 잘 만들어졌나 확인
    n->data  = elem; // 데이터 삽입
    n->next = 0;

    if(r == 0) {
        f = n;
    } else {
        r->next = n;
    }
    r = n;
}

template <class queueElementType>
queueElementType Queue <queueElementType>::dequeue()
{
    assert(!isEmpty());   
    nodePtr delNode = new Node;
    delNode = f;
    queueElementType temp delNode->data;
    f = f->next;
    return temp;
}

template <class queueElementType>
queueElementType Queue <queueElementType>::front()
{
    assert(!isEmpty());
    queueElementType temp = f->data;
    return temp;
}


template <class queueElementType>
bool Queue <queueElementType>::isEmpty()
{
    return (f == 0);
}

template <class queueElementType>
Queue <queueElementType>::~Queue()
{
    // 맨 앞부터 소멸시킨다.
    while(f != 0) {
        nodePtr delNode; // 삭제할 주소의 노드 포인터 선언
        delNode = f; // f 주소를 delNode에 넣어줌
        f = f->next; // f 하나 증가.
        delete delNode;
    }

}