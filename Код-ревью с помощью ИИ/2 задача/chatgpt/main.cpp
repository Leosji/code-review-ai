#include "CalcTree.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  try
  {
    ifstream file("/Users/leost/Desktop/prog/code_review/test/test/final/01/filename.txt");

    if (!file)
    {
      cerr << "Не удалось открыть файл" << endl;
      return 1;
    }

    string expr;
    getline(file, expr);
    file.close();

    int pos = 0;
    TreeNode* root = buildTree(expr, pos);

    cout << "Исходное дерево:\n";
    printTree(root);

    TreeNode* simplified = simplifyTree(root);

    cout << "\nУпрощённое дерево:\n";
    printTree(simplified);

    freeTree(simplified);
  }
  catch (const exception& e)
  {
    cerr << "Ошибка: " << e.what() << endl;
    return 1;
  }

  return 0;
}
