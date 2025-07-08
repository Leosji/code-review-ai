#include "GraphBFS.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>

GraphBFS::GraphBFS(const std::string& fileName)
  : adjacencyMatrix(nullptr), numVertices(0)
{
  loadGraphFromFile(fileName);
}

GraphBFS::~GraphBFS()
{
  // Освобождаем память, выделенную под матрицу смежности
  if (adjacencyMatrix != nullptr)
  {
    for (int i = 0; i < numVertices; ++i)
    {
      delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
  }
}

void GraphBFS::loadGraphFromFile(const std::string& fileName)
{
  std::ifstream inFile(fileName);
  if (!inFile.is_open())
  {
    throw std::runtime_error("Failed to open file: " + fileName);
  }

  // Читаем количество вершин
  inFile >> numVertices;

  // Выделяем память под матрицу смежности
  adjacencyMatrix = new int*[numVertices];
  for (int i = 0; i < numVertices; ++i)
  {
    adjacencyMatrix[i] = new int[numVertices];
    for (int j = 0; j < numVertices; ++j)
    {
      inFile >> adjacencyMatrix[i][j];
    }
  }
}

bool GraphBFS::isValidVertex(int vertex) const
{
  return vertex >= 0 && vertex < numVertices;
}

std::vector<int> GraphBFS::breadthFirstSearch(int k) const
{
  if (!isValidVertex(k))
  {
    throw std::out_of_range("Invalid starting vertex");
  }

  std::vector<int> result;
  std::queue<int> queue;
  std::set<int> visited;

  queue.push(k);
  visited.insert(k);

  while (!queue.empty())
  {
    int current = queue.front();
    queue.pop();
    result.push_back(current);

    // Собираем всех соседей текущей вершины
    std::vector<int> neighbors;
    for (int j = 0; j < numVertices; ++j)
    {
      if (adjacencyMatrix[current][j] != 0 && visited.find(j) == visited.end())
      {
        neighbors.push_back(j);
        visited.insert(j);
      }
    }

    // Сортируем соседей по возрастанию номеров
    std::sort(neighbors.begin(), neighbors.end());

    // Добавляем соседей в очередь
    for (int neighbor : neighbors)
    {
      queue.push(neighbor);
    }
  }

  return result;
}
