#ifndef ALG_H
#define ALG_H
#include "Graph.h"
#include "List.h"
#include <assert.h>

typedef List <int> IntList;
typedef ListIter <int> IntListIter;

class ALGraph : public Graph
{
protected:
    IntList* vertexList;

public:
    ALGraph(int size) : Graph(size) {
        vertexList = new IntList[n];
        assert(vertexList);
    }
    friend class NeighborIter;
};

class NeighborIter : public IntListIter // friend: ALG 접근, 상속: ListIter 기능 상속
{
public:
    NeighborIter(const ALGraph &G, int startVertex)
        : IntListIter(G.vertexList[startVertex], G.n) {
            assert(startVertex < G.n);
        }
};


#endif