#include "GraphBFS.h"
#include <iostream>
#include <vector>

int main()
{
  try
  {
    // Имя файла с графом
    const std::string fileName = "/Users/leost/Desktop/prog/code_review/test/test/final/01/filename.txt";
    
    // Вершина, с которой начинаем обход
    const int startVertex = 0;

    // Создаем граф и выполняем BFS
    GraphBFS graph(fileName);
    std::vector<int> traversalOrder = graph.breadthFirstSearch(startVertex);

    // Выводим результат
    std::cout << "BFS traversal starting from vertex " << startVertex << ":\n";
    for (int vertex : traversalOrder)
    {
      std::cout << vertex << " ";
    }
    std::cout << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
