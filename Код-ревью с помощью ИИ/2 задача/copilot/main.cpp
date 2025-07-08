#include "CalcTree.h"
#include <fstream>
#include <sstream>

int main() {
  std::ifstream file("/Users/leost/Desktop/prog/code_review/test/test/final/01/filename.txt");
  if (!file) {
    std::cerr << "Ошибка открытия файла\n";
    return 1;
  }

  std::string expression;
  std::getline(file, expression);
  file.close();

  std::istringstream iss(expression);
  std::vector<std::string> tokens;
  std::string token;
  while (iss >> token) {
    tokens.push_back(token);
  }

  int index = 0;
  auto root = buildTree(tokens, index);

  std::cout << "Исходное дерево:\n";
  printTree(root);

  optimizeTree(root);

  std::cout << "Оптимизированное дерево:\n";
  printTree(root);

  // Fix me (Добавил вывод указателя и значения корня)
  std::cout << "Указатель на корень: " << root.get() << "\n";
  if (root) {
    std::cout << "Значение корня: " << root->value << "\n";
  } else {
    std::cerr << "Ошибка: Корень дерева отсутствует!\n";
  }
}
