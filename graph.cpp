#include "graph.h"
#include <iostream>

using namespace std;

void createGraph(Graph &G){
    G.start = NULL;
};

adrNode newNode(char x){
    adrNode P = new elmNode;
    P->info = x;
    P->next = NULL;
    P->firstEdge = NULL;
    return P;
};

void addNode(adrNode &G, adrNode p){
    adrNode q = G;
    if (q == NULL) {
        G = p;
    }else {
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }
};
adrNode findNode(adrNode G,char x){
    adrNode P = G;
    if (P == NULL){
        cout << "Graph Kosong" << endl;
    }else {
        while(P->info != x && P != NULL){
            P = P->next;
        }
        return P;
    }
};
void addEdge(adrNode &G,char x, char y){
    if (isConnected(G,x,y)){
        cout << x<< " & "<< y<<" Already Connected"<< endl;
    }else {
        adrNode nodeX = findNode(G,x);
        adrNode nodeY = findNode(G,y);

        adrEdge tempX;
        adrEdge a = new elmEdge;
        a->info = nodeX->info;
        a->nextEdge = NULL;

        adrEdge tempY;
        adrEdge b = new elmEdge;
        b->info = nodeY->info;
        b->nextEdge = NULL;
        if (nodeX->firstEdge == NULL) {
            nodeX->firstEdge = b;
        }else {
            tempX = nodeX->firstEdge;
            b->nextEdge = tempX;
            nodeX->firstEdge = b;
        }

        if (nodeY->firstEdge == NULL){
            nodeY->firstEdge = a;
        }else {
            tempY = nodeY->firstEdge;
            a->nextEdge = tempY;
            nodeY->firstEdge = a;
        }
    }
};
bool isConnected(adrNode G,char x, char y){
    adrNode P = G;
    adrEdge Q;
    while(P != NULL){
        Q = P->firstEdge;
        if (P->info == x){
            if (Q != NULL) {
                while (Q != NULL){
                    if (Q->info == y){
                        return true;
                    }
                    Q = Q->nextEdge;
                }
            }
            return false;
        }
        P = P->next;
    }
};

void printGraph(adrNode G){
    adrNode p = G;
    adrEdge q;
    cout << "==================================" << endl;
    while (p != NULL){
        cout << "node " <<p->info << ":";
        q = p->firstEdge;
        while(q != NULL) {
            cout << " - " << q->info ;
            q = q->nextEdge;
        }
        cout << endl;
        p = p->next;
    }
    cout << "==================================" << endl;
};
