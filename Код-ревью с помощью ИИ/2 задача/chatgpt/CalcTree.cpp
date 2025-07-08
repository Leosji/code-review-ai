#include "CalcTree.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <stdexcept>

using namespace std;

// Конструктор
TreeNode::TreeNode(int val)
  : value(val), left(nullptr), right(nullptr)
{
}

// Деструктор
TreeNode::~TreeNode()
{
  delete left;
  delete right;
}

// Разбор выражения и построение дерева
TreeNode* buildTree(const string& expression, int& pos)
{
  while (pos < expression.length() && expression[pos] == ' ')
  {
    ++pos;
  }

  if (pos >= expression.length())
  {
    return nullptr;
  }

  char ch = expression[pos];
  ++pos;

  if (isdigit(ch))
  {
    return new TreeNode(ch - '0');
  }

  int opCode;

  if (ch == '+')
  {
    opCode = -1;
  }
  else if (ch == '-')
  {
    opCode = -2;
  }
  else if (ch == '*')
  {
    opCode = -3;
  }
  else if (ch == '/')
  {
    opCode = -4;
  }
  else if (ch == '%')
  {
    opCode = -5;
  }
  else if (ch == '^')
  {
    opCode = -6;
  }
  else
  {
    throw runtime_error("Неверный символ в выражении");
  }

  TreeNode* node = new TreeNode(opCode);
  node->left = buildTree(expression, pos);
  node->right = buildTree(expression, pos);

  return node;
}

// Оценка выражения
int evaluate(TreeNode* node)
{
  if (!node)
  {
    throw runtime_error("Пустой узел дерева");
  }

  if (node->value >= 0)
  {
    return node->value;
  }

  int leftVal = evaluate(node->left);
  int rightVal = evaluate(node->right);

  if (node->value == -1)
  {
    return leftVal + rightVal;
  }

  if (node->value == -2)
  {
    return leftVal - rightVal;
  }

  if (node->value == -3)
  {
    return leftVal * rightVal;
  }

  if (node->value == -4)
  {
    if (rightVal == 0)
    {
      throw runtime_error("Деление на ноль");
    }

    return leftVal / rightVal;
  }

  if (node->value == -5)
  {
    if (rightVal == 0)
    {
      throw runtime_error("Остаток от деления на ноль");
    }

    return leftVal % rightVal;
  }

  if (node->value == -6)
  {
    return static_cast<int>(pow(leftVal, rightVal));
  }

  throw runtime_error("Неизвестная операция");
}

// Упрощение дерева
TreeNode* simplifyTree(TreeNode* root)
{
  if (!root)
  {
    return nullptr;
  }

  root->left = simplifyTree(root->left);
  root->right = simplifyTree(root->right);

  if (root->value < 0 &&
      root->left && root->right &&
      root->left->value >= 0 && root->right->value >= 0)
  {
    try
    {
      int result = evaluate(root);

      if (result >= 0 && result <= 9)
      {
        delete root;
        return new TreeNode(result); //Fix me: заменено поддерево числом
      }
    }
    catch (...)
    {
      // Пропустить замену при ошибке вычисления
    }
  }

  return root;
}

// Печать дерева (отладка)
void printTree(TreeNode* node, int depth)
{
  if (!node)
  {
    return;
  }

  printTree(node->right, depth + 1);

  for (int i = 0; i < depth; ++i)
  {
    cout << "  ";
  }

  if (node->value >= 0)
  {
    cout << node->value << endl;
  }
  else
  {
    char op;

    if (node->value == -1)
    {
      op = '+';
    }
    else if (node->value == -2)
    {
      op = '-';
    }
    else if (node->value == -3)
    {
      op = '*';
    }
    else if (node->value == -4)
    {
      op = '/';
    }
    else if (node->value == -5)
    {
      op = '%';
    }
    else
    {
      op = '^';
    }

    cout << op << endl;
  }

  printTree(node->left, depth + 1);
}

// Очистка дерева
void freeTree(TreeNode* node)
{
  delete node;
}
