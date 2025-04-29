const int maxQueue = 200;

template <class queueElementType>
class Queue
{
    public:
        Queue();
        void enqueue(queueElementType e);
        queueElementType dequeue();
        queueElementType front();
        bool isEmpty();
        bool isFull();

    private:
        int f;
        int r;
        int cnt;
        queueElementType queueAry[maxQueue];
};


int nextPos(int p)
{
    return ((p + 1) % maxQueue);
}

template <class queueElementType>
Queue <queueElementType> :: Queue()
{
    f = 0;
    r = 0;
    cnt = 0;
}

template <class queueElementType>
void Queue<queueElementType> :: enqueue(queueElementType e)
{
    assert(!isFull());
    queueAry[r] = e; // 넣고
    r = nextPos(r); // 올리고
    cnt++; // 카운트 증가
}

template <class queueElementType>
queueElementType Queue<queueElementType> :: dequeue()
{
    assert(!isEmpty());
    queueElementType elem = queueAry[f]; // 뺄 거 저장
    f = nextPos(f); // f 한칸 올리고
    cnt--; // 개수 하나 감소
    return elem;
}

template <class queueElementType>
queueElementType Queue <queueElementType> :: front()
{
    assert(!isEmpty());
    return queueAry[f];
}

template <class queueElementType>
bool Queue <queueElementType>::isEmpty()
{
    return (cnt == 0);
}

template <class queueElementType>
bool Queue <queueElementType>::isFull()
{
    return (cnt == maxQueue - 1);
}

