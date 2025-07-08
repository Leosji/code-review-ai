#include "Graph.h"
#include <iostream>
#include <stdexcept>
//тест 1 Стартовая вершина: 0, Ожидаемый вывод: 0 1 2 3
//тест 2 Стартовая вершина: 1, Ожидаемый вывод: 1 2
//тест 3 Стартовая вершина: 4, Ожидаемый вывод: 4 0 1 2
/*
 　 　 　 　    　..-､         ..--､
 　　　　　　　 ./:::::＼　　　 ／:::::ヽ
 　　　　　　　/::::::::::::;/:::::::::ヽ
 　　　　　　 /,.-‐''"′ 　　　  ＼:::::::|
 　　　　　／　 　　　　　　　　　　　　ヽ､::|
 　　　　/　　　　●　　　 　 　 　 　 　 　 ヽ|
 　　 　 l　　　､､､　　 　 　 　 　 　 ●　　 l
 　　　 .|　　　 　　　　(_人__丿　　､､､　 　|
 　 　 　l　　　　　　　　　　　　　　　　 　 l
 　　　　` ､　　　　　　　　 　 　 　　 　 　 /
 　　　　　　`ｰ ､__　　　 　 　 　　　 　.／
 　　　　　　　　　/`'''ｰ‐‐──‐‐‐┬--- ／
 */
int main()
{
  try
  {
    std::string fileName;
    int startVertex;

    std::cout << "Enter input file name: "; // Copilot (интерактивный ввод)
    std::cin >> fileName;

    std::cout << "Enter starting vertex (0-based): ";
    std::cin >> startVertex;

    Graph graph;

    if (!graph.loadFromFile(fileName))
    {
      std::cerr << "Failed to load graph from file." << std::endl; // ChatGPT
      return 1;
    }

    std::vector<int> reachable = graph.breadthFirstSearch(startVertex);

    std::cout << "Reachable vertices in BFS order: "; // Copilot
    for (int v : reachable)
    {
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl; // DeepSeek (std::exception)
    return 1;
  }

  return 0;
}
