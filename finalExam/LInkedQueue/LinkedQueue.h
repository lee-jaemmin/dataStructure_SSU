template <class QueueElementType>
class LinkedQueue
{
    private:
        struct Node;
        typedef Node* Link;
        struct Node
        {
            Link next;
            QueueElementType elem;
        };
        Link f;
        Link r;

    public:
        LinkedQueue() : f(0), r(0) {};
        bool isEmpty();
        void enqueue(const QueueElementType &elem);
        QueueElementType dequeue();
        QueueElementType front();
        ~LinkedQueue();
};

template <class QueueElementType>
bool LinkedQueue <QueueElementType> :: isEmpty()
{
    return (f == 0);
}

template <class QueueElementType>
void LinkedQueue <QueueElementType> :: enqueue(const QueueElementType &elem)
{
    Link addedNode = new Node;
    addedNode->elem = elem;

    // 처음 삽입
    if (isEmpty()) {
        addedNode->next = f;
        f = addedNode;
    } else {
        addedNode->next = r->next;
        r->next = addedNode;
    }
    r = addedNode;
}

template <class QueueElementType>
QueueElementType LinkedQueue <QueueElementType> :: dequeue()
{
    // assert(!isEmpty());
    while(!isEmpty()) {
        Link delNode = new Node;
        delNode = f;
        QueueElementType temp = delNode->elem;
        f = f->next;
        delete delNode;
        return temp;
    }
}

template <class QueueElementType>
QueueElementType LinkedQueue <QueueElementType> :: front()
{
    return (f->elem);
}

template <class QueueElementType>
LinkedQueue <QueueElementType> :: ~LinkedQueue()
{
    while(!isEmpty()) {
        Link delNode = new Node;
        delNode = f;
        f = f->next;
        delete delNode;
    }
}