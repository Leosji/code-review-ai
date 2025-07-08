#include "Graph.h"
#include <fstream>
#include <algorithm>

Graph::Graph(int vertexCount) : vertexCount(vertexCount) {
  adjacencyMatrix.resize(vertexCount, std::vector<int>(vertexCount, 0));
}

void Graph::loadFromFile(const std::string& fileName) {
  std::ifstream file(fileName);
  if (!file) {
    throw std::runtime_error("Не удалось открыть файл");
  }

  file >> vertexCount;
  adjacencyMatrix.resize(vertexCount, std::vector<int>(vertexCount, 0));

  for (int i = 0; i < vertexCount; i++) {
    for (int j = 0; j < vertexCount; j++) {
      file >> adjacencyMatrix[i][j];
    }
  }
}

void Graph::breadthFirstSearch(int startVertex) {
  std::vector<bool> visited(vertexCount, false);
  std::queue<int> queue;
  queue.push(startVertex);
  visited[startVertex] = true;

  while (!queue.empty()) {
    int currentVertex = queue.front();
    queue.pop();
    std::cout << currentVertex << " ";

    std::vector<int> sortedNeighbors;
    for (int j = 0; j < vertexCount; j++) {
      if (adjacencyMatrix[currentVertex][j] != 0 && !visited[j]) {
        sortedNeighbors.push_back(j);
      }
    }

    std::sort(sortedNeighbors.begin(), sortedNeighbors.end()); // Сортировка вершин

    for (int neighbor : sortedNeighbors) {
      queue.push(neighbor);
      visited[neighbor] = true;
    }
  }
  std::cout << std::endl;
}
