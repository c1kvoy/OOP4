#include <iostream>
#include "Graph.h"

AdjList::AdjList() : count(0) {}

bool AdjList::addNeighbor(int node, int distance) {
    if (count < MAX_NEIGHBORS) {
        neighbors[count++] = {node, distance};
        return true;
    }
    return false;
}

const Neighbor* AdjList::getNeighbors() const {
    return neighbors;
}

int AdjList::getCount() const {
    return count;
}


void DeliveryGraph::addEdge(int from, int to, int distance) {
    AdjList neighbors;
    if (!adjListMap.find(from, neighbors)) {
        neighbors = AdjList();
    }
    if (neighbors.addNeighbor(to, distance)) {
        adjListMap.insert(from, neighbors);
    }
}

bool DeliveryGraph::getNeighbors(int node, Neighbor*& neighbors, int& count) {
    AdjList adjList;
    if (adjListMap.find(node, adjList)) {
        neighbors = const_cast<Neighbor*>(adjList.getNeighbors());
        count = adjList.getCount();
        return true;
    }
    return false;
}

void DeliveryGraph::dijkstra(int start, int end) {
    const int MAX_NODES = 100; // Предполагаем максимальное количество узлов
    int distances[MAX_NODES];
    bool visited[MAX_NODES] = {false};
    int previous[MAX_NODES];

    // Инициализация
    for (int i = 0; i < MAX_NODES; i++) {
        distances[i] = INT_MAX;
        previous[i] = -1;
    }
    distances[start] = 0;

    for (int count = 0; count < MAX_NODES - 1; count++) {
        // Находим вершину с минимальным расстоянием
        int minDistance = INT_MAX, minIndex = -1;
        for (int v = 0; v < MAX_NODES; v++) {
            if (!visited[v] && distances[v] <= minDistance) {
                minDistance = distances[v];
                minIndex = v;
            }
        }

        // Если не нашли доступную вершину, выходим
        if (minIndex == -1) break;

        visited[minIndex] = true;

        // Обновляем расстояния до соседних вершин
        Neighbor* neighbors;
        int neighborCount;
        if (getNeighbors(minIndex, neighbors, neighborCount)) {
            for (int i = 0; i < neighborCount; i++) {
                int v = neighbors[i].node;
                int weight = neighbors[i].distance;
                if (!visited[v] && distances[minIndex] != INT_MAX
                    && distances[minIndex] + weight < distances[v]) {
                    distances[v] = distances[minIndex] + weight;
                    previous[v] = minIndex;
                    }
            }
        }
    }

    if (distances[end] == INT_MAX) {
        std::cout << "Нет пути между " << start << " и " << end << std::endl;
    } else {
        std::cout << "Кратчайшее расстояние от " << start << " до " << end << ": " << distances[end] << std::endl;
        std::cout << "Путь: ";
        int current = end;
        while (current != -1) {
            std::cout << current << " ";
            current = previous[current];
        }
        std::cout << std::endl;
    }
}