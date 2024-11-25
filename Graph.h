#ifndef GRAPH_H
#define GRAPH_H

#include "HM.h"

struct Edge {
    int neighbor;
    int weight;

    Edge();
    Edge(int n, int w);
    ~Edge();
};

class Graph {
private:
    static const int EDGES = 100;
    Map<int, Edge*> adjList;  // Используем указатели на массивы
    int edgeCount[100];
public:
    Graph();
    void addEdge(int u, int v, int weight);
    void Deikstra(int start, int end);
};

#endif