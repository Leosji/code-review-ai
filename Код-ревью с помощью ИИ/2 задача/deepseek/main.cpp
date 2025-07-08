// main.cpp
#include "CalcTree7.h"
#include <iostream>

int main()
{
  try
  {
    // Создаем дерево выражений из файла
    ExpressionTree tree("/Users/leost/Desktop/prog/code_review/test/test/final/01/input.txt");
    
    std::cout << "Original tree:" << std::endl;
    tree.printTree();
    
    // Упрощаем дерево
    tree.simplifyTree();
    
    std::cout << "\nSimplified tree:" << std::endl;
    tree.printTree();
    
    // Возвращаем указатель на корень (для проверки)
    TreeNode* root = tree.getRoot();
    std::cout << "\nRoot value: " << root->value << std::endl;
    
    return 0;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
}
