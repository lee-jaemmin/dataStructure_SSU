#include "UAMG.h"
#include <fstream>
#include <iostream>
using namespace std;
//20212861 이재민

int main()
{
    const char* inFileName = "C:/src/dataStructure_SSU/HW3/[9]_40/graph.dat";

    fstream ifs(inFileName);
    assert(ifs);

    int n;
    ifs >> n;
    uAMGraph G(n);
    cout << "Created graph; n = " << G.vertexSize() << endl;

    int u, v; // u -> v
    while(ifs >> u) {
        ifs >> v;
        G.addEdge(u, v);
    }
    
    cout << "Edges in graph: m = " << G.edgeSize() << endl;

    int step;
    
    for(step = 0; step < n; step++) {
        for(u = 0; u < n; u++) {
            for(v = 0; v < n; v++) {
                if(G.edgeMember(u, step) && G.edgeMember(step, v)) {
                    G.addEdge(u, v);
                }
            }
        }
    }
    for(u = 0; u < n; u++) {
            cout << u << "\t:";
            for(v = 0; v < n; v++) {
                cout << (G.edgeMember(u, v) ? "T" : "F");
            }
            cout << endl;
        }
    return 0;
}