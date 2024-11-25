#ifndef DELIVERYGRAPH_H
#define DELIVERYGRAPH_H

#include "HM.h"

struct Neighbor {
    int node;
    int distance;
};


class AdjList {
private:
    static const int MAX_NEIGHBORS = 10;
    Neighbor neighbors[MAX_NEIGHBORS];
    int count;

public:
    AdjList();
    bool addNeighbor(int node, int distance);
    const Neighbor* getNeighbors() const;
    int getCount() const;
};

class DeliveryGraph {
private:
    Map<int, AdjList> adjListMap;

public:
    void addEdge(int from, int to, int distance);
    bool getNeighbors(int node, Neighbor*& neighbors, int& count);
    void printGraph();
    void dijkstra(int start, int end);
};

#endif