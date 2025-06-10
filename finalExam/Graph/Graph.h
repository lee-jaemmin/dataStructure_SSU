#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
protected:
    int n; // # of vertex
    int m; // # of edge

public:
    Graph(int size) : n(size), m(0) {};
    virtual int vertexSize() {return n;}
    virtual int edgeSize() {return m;}
    virtual void addEdge(int fromV, int toV) = 0; // pure virtual, 어차피 자식 클래스에서 다 바뀜.
};

#endif