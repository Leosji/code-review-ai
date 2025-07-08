#pragma once
#include <vector>
#include <string>

// Класс Graph выполняет загрузку графа и обход в ширину
class Graph
{
public:
  Graph();
  ~Graph();

  bool loadFromFile(const std::string& fileName); // Взято у ChatGPT (чтение через vector<vector>)
  std::vector<int> breadthFirstSearch(int startVertex); // Комбинировано: структура от ChatGPT, проверки от DeepSeek

private:
  int vertexCount;
  std::vector<std::vector<int>> adjacencyMatrix; // Использование vector вместо new — идея от ChatGPT

  void clear(); // ChatGPT
  bool isValidVertex(int vertex) const; // DeepSeek
};
