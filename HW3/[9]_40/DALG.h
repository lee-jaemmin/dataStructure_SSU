#ifndef DALG_H
#define DALG_H

#include "ALG.h"

class DALGraph : public ALGraph
{
    public:
        DALGraph(int size) : ALGraph(size) {};
        virtual void addEdge(int fromV, int toV);
};

#endif

void DALGraph :: addEdge(int fromV, int toV)
{
    assert(fromV < n && fromV >= 0 && toV < n && toV >= 0);
    vertexList[fromV].insert(toV); // 단방향 작업
    m++; // edge 하나 증가
}