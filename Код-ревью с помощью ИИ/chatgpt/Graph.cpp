#include "Graph.h"
#include <fstream>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std; //Fix me: using namespace локально, только в .cpp

// Конструктор
Graph::Graph()
{
  vertexCount = 0;
}

// Деструктор
Graph::~Graph()
{
  clear();
}

// Очистка памяти
void Graph::clear()
{
  adjacencyMatrix.clear();
  vertexCount = 0;
}

// Загрузка графа из файла
bool Graph::loadFromFile(const string& fileName)
{
  ifstream file(fileName);

  if (!file.is_open())
  {
    return false;
  }

  try
  {
    file >> vertexCount;

    if (vertexCount <= 0)
    {
      return false;
    }

    adjacencyMatrix.resize(vertexCount, vector<int>(vertexCount, 0));

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
    return false;
  }

  return true;
}

// Поиск в ширину
vector<int> Graph::bfs(int startVertex)
{
  vector<int> visited(vertexCount, 0);
  vector<int> result;

  if (startVertex < 0 || startVertex >= vertexCount)
  {
    return result;
  }

  queue<int> q;
  q.push(startVertex);
  visited[startVertex] = 1;

  while (!q.empty())
  {
    int current = q.front();
    q.pop();
    result.push_back(current);

    vector<int> neighbors;

    for (int j = 0; j < vertexCount; ++j)
    {
      if (adjacencyMatrix[current][j] != 0 && visited[j] == 0)
      {
        neighbors.push_back(j);
        visited[j] = 1;
      }
    }

    sort(neighbors.begin(), neighbors.end()); //Fix me: сортировка для соблюдения условия

    for (int j : neighbors)
    {
      q.push(j);
    }
  }

  return result;
}
