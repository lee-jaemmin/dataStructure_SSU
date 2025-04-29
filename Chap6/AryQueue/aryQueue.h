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
}

template <class queueElementType>
void Queue<queueElementType> :: enqueue(queueElementType e)
{
    assert(!isFull());
    r = nextPos(r);
    queueAry[r] = e;
}


template <class queueElementType>
queueElementType Queue<queueElementType> :: dequeue()
{
    assert(!isEmpty());
    f = nextPos(f);
    return queueAry[f];
}

template <class queueElementType>
queueElementType Queue <queueElementType> :: front()
{
    assert(!isEmpty());
    return queueAry[nextPos(f)];
}

template <class queueElementType>
bool Queue <queueElementType>::isEmpty()
{
    return (f == r);
}

template <class queueElementType>
bool Queue <queueElementType>::isFull()
{
    return (f == nextPos(r));
}

