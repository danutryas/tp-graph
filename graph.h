#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <cstddef>


#include <iostream>

using namespace std;

typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;

struct Graph {
    adrNode start;
};

struct elmNode {
    char info;
    adrEdge firstEdge;
    adrNode next;
};

struct elmEdge {
    char info;
    adrEdge nextEdge;
};

void createGraph(Graph &G);
adrNode newNode(char x);
void addNode(adrNode &G, adrNode p);
adrNode findNode(adrNode G,char x);
void addEdge(adrNode &G,char x, char y);
bool isConnected(adrNode G,char x, char y);
void printGraph(adrNode G);


#endif // GRAPH_H_INCLUDED
