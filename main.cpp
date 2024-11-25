#include "Graph.h"

int main() {
    DeliveryGraph graph;

    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 6);
    graph.addEdge(2, 3, 3);

    graph.dijkstra(0, 3);

    return 0;
}