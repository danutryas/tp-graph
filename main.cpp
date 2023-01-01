#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    Graph Gr;adrNode p;
    createGraph(Gr);
    adrNode G = Gr.start;

    p = newNode('A');
    addNode(G,p);
    p = newNode('B');
    addNode(G,p);
    p = newNode('C');
    addNode(G,p);
    p = newNode('D');
    addNode(G,p);

    addEdge(G,'B','D');
    addEdge(G,'A','B');
    addEdge(G,'A','D');
    addEdge(G,'A','C');

    printGraph(G);
    // node D tidak bisa menampilkan - B - A,
    // karena untuk menampilkan node B:-A-D , edge B-D harus ditambahkan dulu sebelum A-B,
    // sedangkan pada node D: - B - A, edge A-D harus ditambahkan sebelum B-D

    return 0;
}
