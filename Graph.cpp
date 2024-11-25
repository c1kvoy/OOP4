#include "Graph.h"
#include <iostream>

Edge::Edge(): neighbor(0), weight(0) {}

Edge::Edge(int n, int w): neighbor(n), weight(w) {}
Edge::~Edge() {}

Graph::Graph() {
    for (int i = 0; i < 100; ++i) {
        edgeCount[i] = 0;
    }
}

void Graph::addEdge(int u, int v, int weight) {
    Edge* edges = new Edge[EDGES];
    if (!adjList.find(u, edges)) {
        for (int i = 0; i < EDGES; ++i) {
            edges[i] = Edge();
        }
    }

    if (edgeCount[u] < EDGES) {
        edges[edgeCount[u]++] = Edge(v, weight);
        adjList.insert(u, edges);
    }
}

void Graph::Deikstra(int start, int end) {
    constexpr int INF = 1e9;
    int distances[100];
    int previous[100];
    bool visited[100] = {false};

    for (int i = 0; i < 100; ++i) {
        distances[i] = INF;
        previous[i] = -1;
    }

    distances[start] = 0;

    for (int i = 0; i < 100; ++i) {
        int minDist = INF;
        int current = -1;

        for (int j = 0; j < 100; ++j) {
            if (!visited[j] && distances[j] < minDist) {
                minDist = distances[j];
                current = j;
            }
        }

        if (current == -1) break;

        visited[current] = true;

        Edge* edges = nullptr;
        if (adjList.find(current, edges)) {
            for (int j = 0; j < edgeCount[current]; ++j) {
                Edge& edge = edges[j];
                int newDist = distances[current] + edge.weight;

                if (newDist < distances[edge.neighbor]) {
                    distances[edge.neighbor] = newDist;
                    previous[edge.neighbor] = current;
                }
            }
        }
    }

    int path[100];
    int pathLength = 0;

    for (int at = end; at != -1; at = previous[at]) {
        path[pathLength++] = at;
    }

    for (int i = pathLength - 1; i >= 0; --i) {
        if (i != 0) {
            std::cout << path[i] << " -> ";
        } else {
            std::cout << path[i] << std::endl;
        }
    }
}