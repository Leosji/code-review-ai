#pragma once
#include <vector>
#include <string>

// Класс Graph реализует граф и обход в ширину
class Graph
{
public:
  Graph();
  ~Graph();

  bool loadFromFile(const std::string& fileName);
  std::vector<int> bfs(int startVertex);

private:
  std::vector<std::vector<int>> adjacencyMatrix;
  int vertexCount;

  void clear();
};
