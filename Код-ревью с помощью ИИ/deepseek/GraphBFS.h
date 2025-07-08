#pragma once

#include <vector>
#include <string>
#include <queue>
#include <set>

class GraphBFS
{
public:
  // Конструктор, принимающий имя файла с описанием графа
  GraphBFS(const std::string& fileName);

  // Деструктор для освобождения памяти
  ~GraphBFS();

  // Выполняет поиск в ширину от вершины k и возвращает порядок обхода
  std::vector<int> breadthFirstSearch(int k) const;

private:
  // Матрица смежности графа
  int** adjacencyMatrix;
  
  // Количество вершин в графе
  int numVertices;

  // Загружает граф из файла
  void loadGraphFromFile(const std::string& fileName);

  // Проверяет валидность вершины
  bool isValidVertex(int vertex) const;
};
