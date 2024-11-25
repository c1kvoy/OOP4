#include "Graph.h"
#include <iostream>

int main() {
    Graph g;

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);

    std::cout << "Shortest path from 0 to 3:" << std::endl;
    g.Deikstra(0, 3);

    return 0;
}