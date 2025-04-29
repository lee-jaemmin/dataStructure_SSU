#include "queue.h"

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

