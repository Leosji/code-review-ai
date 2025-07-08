#include "CalcTree.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
  try
  {
    std::ifstream file("/Users/leost/Desktop/prog/code_review/test/test/final/01/filename.txt");

    if (!file)
    {
      std::cerr << "Ошибка открытия файла" << std::endl;
      return 1;
    }

    std::string expression;
    std::getline(file, expression);
    file.close();

    ExpressionTree tree(expression); //Fix me: оборачиваем всё в класс ExpressionTree

    std::cout << "Исходное дерево:\n";
    tree.printTree();

    tree.simplifyTree();

    std::cout << "\nУпрощённое дерево:\n";
    tree.printTree();

    TreeNode* root = tree.getRoot();
    std::cout << "\nУказатель на корень: " << root << std::endl;
    if (root != nullptr)
    {
      std::cout << "Значение корня: " << root->value << std::endl;
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << "Ошибка: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
