#include "Graph.h"
#include <fstream>
#include <queue>
#include <algorithm>
#include <stdexcept>
#include <iostream>

//Fix me: using namespace std локально, только внутри cpp
using namespace std;

// Конструктор
Graph::Graph()
{
  vertexCount = 0;
}

// Деструктор
Graph::~Graph()
{
  clear(); // ChatGPT
}

// Очистка графа
void Graph::clear()
{
  adjacencyMatrix.clear(); // ChatGPT
  vertexCount = 0;
}

// Проверка корректности вершины
bool Graph::isValidVertex(int vertex) const
{
  return vertex >= 0 && vertex < vertexCount; // DeepSeek
}

// Загрузка графа из файла
bool Graph::loadFromFile(const string& fileName)
{
  ifstream file(fileName);

  if (!file.is_open())
  {
    return false; // ChatGPT
  }

  try
  {
    file >> vertexCount;

    if (vertexCount <= 0)
    {
      return false; // ChatGPT
    }

    adjacencyMatrix.resize(vertexCount, vector<int>(vertexCount, 0)); // ChatGPT

    for (int i = 0; i < vertexCount; ++i)
    {
      for (int j = 0; j < vertexCount; ++j)
      {
        file >> adjacencyMatrix[i][j];
      }
    }
  }
  catch (...)
  {
    return false; // ChatGPT
  }

  return true;
}

// Выполняет BFS и возвращает список достижимых вершин
vector<int> Graph::breadthFirstSearch(int startVertex)
{
  vector<int> result; // ChatGPT
  vector<bool> visited; // Copilot
  queue<int> vertexQueue; // ChatGPT

  if (!isValidVertex(startVertex))
  {
    throw invalid_argument("Invalid starting vertex"); // DeepSeek
  }

  visited.resize(vertexCount, false);
  visited[startVertex] = true;
  vertexQueue.push(startVertex);

  while (!vertexQueue.empty())
  {
    int current = vertexQueue.front();
    vertexQueue.pop();
    result.push_back(current);

    vector<int> neighbors; // DeepSeek: временный список для сортировки

    for (int j = 0; j < vertexCount; ++j)
    {
      if (adjacencyMatrix[current][j] != 0 && !visited[j])
      {
        neighbors.push_back(j);
        visited[j] = true; // Copilot (перенос отметки "visited" внутрь if)
      }
    }

    sort(neighbors.begin(), neighbors.end()); // Общее решение всех моделей

    for (int neighbor : neighbors)
    {
      vertexQueue.push(neighbor);
    }
  }

  return result;
}
