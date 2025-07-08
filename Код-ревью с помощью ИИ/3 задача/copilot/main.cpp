#include "Graph.h"
#include <iostream>
#include <stdexcept>

int main() {
  try {
    Graph graph(0);
    graph.loadFromFile("/Users/leost/Desktop/prog/code_review/test/test/final/01/filename.txt"); // Загрузка данных из файла

    int startVertex;
    std::cout << "Введите стартовую вершину: ";
    std::cin >> startVertex;

    std::cout << "Обход в ширину: ";
    graph.breadthFirstSearch(startVertex);
  } catch (const std::exception& e) {
    std::cerr << "Ошибка: " << e.what() << std::endl;
  }

  return 0;
}
