#pragma once
#include <vector>
#include <queue>
#include <iostream>

class Graph {
public:
  Graph(int vertexCount);  // Конструктор
  void loadFromFile(const std::string& fileName); // Загрузка из файла
  void breadthFirstSearch(int startVertex); // Поиск в ширину

private:
  int vertexCount;
  std::vector<std::vector<int>> adjacencyMatrix; // Матрица смежности
};
