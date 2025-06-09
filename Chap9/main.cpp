#include "DALG.h"
#include "linkedListStack.h"
#include "LinkedQueue.h"
#include <fstream>

using namespace std;

int main()
{
    const char* inFileName = "graph.dat";

    fstream ifs(inFileName);
    assert(ifs);

    int n;
    ifs >> n;
    DALGraph G(n);
    cout << "Created graph; n = " << G.vertexSize() << endl;

    int u, v; // u -> v
    while(ifs >> u) {
        ifs >> v;
        G.addEdge(u, v);
    }
    
    cout << "Edges in graph: m = " << G.edgeSize() << endl;

    int* vertices = new int[n];
    assert(vertices);
    for(u = 0; u < n; u++) {
        vertices[u] = 0;
    }
    for(u = 0; u < n; u++) {
        NeighborIter ni(G,u);
        while((v = ++ni) != n) {
            vertices[v]++;
        }
    }

    // noInEdge모으기
    Stack <int> s;
    for(u = 0; u < n; u++) {
        if(vertices[u] == 0) {
            s.puhs(u);
        }
    }
    if(s.isEmpty()) {
        cout << "graph has a cycle!\n";
        return 0;
    }

    int cnt = 0;
    Queue <int> sortedEdges;
    while(!s.isEmpty()) {
        cnt++;
        u = s.pop();
        sortedEdges.enqueue(u);
        NeighborIter ni (G,u);
        while((v = ++ni) != n) {
            --vertices[v];
            if(vertices[v] == 0) {
                s.push(v);
            }
        }
    }

    if(cnt < n) {
        cout << "Couldn't complete top sort -- cycle exists\n";
        cout << "Ordering for top sort\n";
        while(!sortedEdges.isEmpty()) {
            cout << sortedEdges.dequeue() << '\t';
        }
        cout << endl;
        return n;
    }
    return 0;
}