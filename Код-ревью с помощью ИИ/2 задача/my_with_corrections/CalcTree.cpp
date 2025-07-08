#include "CalcTree.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>

// Конструктор узла дерева
TreeNode::TreeNode(int val)
  : value(val), left(nullptr), right(nullptr)
{
}

// Деструктор узла дерева
TreeNode::~TreeNode()
{
  delete left;
  delete right;
}

// Конструктор ExpressionTree ChatGPT
ExpressionTree::ExpressionTree(const std::string& expr)
  : root(nullptr)
{
  std::vector<std::string> tokens;
  tokenize(expr, tokens);
  int index = 0;
  root = buildTreeFromTokens(tokens, index);
}

// Деструктор ExpressionTree
ExpressionTree::~ExpressionTree()
{
  clearTree(root);
}

// Разбиение строки на токены ChatGPT
void ExpressionTree::tokenize(const std::string& expr, std::vector<std::string>& tokens)
{
  std::istringstream iss(expr);
  std::string token;

  while (iss >> token)
  {
    tokens.push_back(token);
  }
}

// Построение дерева из токенов ChatGPT
TreeNode* ExpressionTree::buildTreeFromTokens(const std::vector<std::string>& tokens, int& index)
{
  if (index >= tokens.size())
  {
    return nullptr;
  }

  const std::string& token = tokens[index++];
  int val;

  if (isdigit(token[0]))
  {
    val = std::stoi(token);
  }
  else if (token == "+") val = -1;
  else if (token == "-") val = -2;
  else if (token == "*") val = -3;
  else if (token == "/") val = -4;
  else if (token == "%") val = -5;
  else if (token == "^") val = -6;
  else
  {
    throw std::runtime_error("Недопустимый символ в выражении");
  }

  TreeNode* node = new TreeNode(val);

  if (val < 0)
  {
    node->left = buildTreeFromTokens(tokens, index);
    node->right = buildTreeFromTokens(tokens, index);
  }

  return node;
}

// Печать дерева с ветвями псевдографики
void ExpressionTree::printTree() const
{
  printTreeHelper(root, "", true);
}

void ExpressionTree::printTreeHelper(TreeNode* node, std::string prefix, bool isLeft) const
{
  if (!node)
    return;

  if (node->right)
  {
    printTreeHelper(node->right, prefix + (isLeft ? "│   " : "    "), false);
  }

  std::cout << prefix;

  std::cout << (isLeft ? "└── " : "┌── ");

  std::cout << node->value << std::endl;

  if (node->left)
  {
    printTreeHelper(node->left, prefix + (isLeft ? "    " : "│   "), true);
  }
}

// Очистка дерева ChatGPT
void ExpressionTree::clearTree(TreeNode* node)
{
  if (node)
  {
    clearTree(node->left);
    clearTree(node->right);
    
  }
}

// Получение корня
TreeNode* ExpressionTree::getRoot() const
{
  return root;
}

// Проверка, является ли узел листом
bool ExpressionTree::isLeaf(TreeNode* node) const
{
  return node != nullptr && node->left == nullptr && node->right == nullptr;
}

// Упрощение дерева Copilot
void ExpressionTree::simplifyTree()
{
  simplifyHelper(root);
}

void ExpressionTree::simplifyHelper(TreeNode*& node)
{
  if (!node || isLeaf(node))
  {
    return;
  }

  simplifyHelper(node->left);
  simplifyHelper(node->right);

  if (isLeaf(node->left) && isLeaf(node->right))
  {
    try
    {
      int result = evaluate(node);
      if (result >= 0 && result <= 9)
      {
        delete node->left;
        delete node->right;
        node->left = nullptr;
        node->right = nullptr;
        node->value = result; // Поддерево заменено числом
      }
    }
    catch (...) {}
  }
}

// Вычисление значения выражения DeepSeek
int ExpressionTree::evaluate(TreeNode* node)
{
  if (!node)
  {
    throw std::runtime_error("Пустой узел");
  }

  if (node->value >= 0)
  {
    return node->value;
  }

  int leftVal = evaluate(node->left);
  int rightVal = evaluate(node->right);

  switch (node->value)
  {
    case -1: return leftVal + rightVal;
    case -2: return leftVal - rightVal;
    case -3: return leftVal * rightVal;
    case -4:
      if (rightVal == 0) throw std::runtime_error("Деление на ноль");
      return leftVal / rightVal;
    case -5:
      if (rightVal == 0) throw std::runtime_error("Остаток от деления на ноль");
      return leftVal % rightVal;
    case -6: return static_cast<int>(std::pow(leftVal, rightVal));
    default: throw std::runtime_error("Неизвестная операция");
  }
}
