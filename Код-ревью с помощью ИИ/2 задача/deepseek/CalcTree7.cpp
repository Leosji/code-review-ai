// CalcTree7.cpp
#include "CalcTree7.h"
#include <iostream>

// Реализация методов класса TreeNode
TreeNode::TreeNode(int val, TreeNode* l, TreeNode* r)
  : value(val), left(l), right(r)
{
}

TreeNode::~TreeNode()
{
  delete left;
  delete right;
}

// Реализация методов класса ExpressionTree
ExpressionTree::ExpressionTree(const std::string& filename)
  : root(nullptr)
{
  std::ifstream file(filename);
  if (!file.is_open())
  {
    throw std::runtime_error("Failed to open file");
  }

  std::string expression;
  std::getline(file, expression);
  file.close();

  std::vector<std::string> tokens;
  std::string token;
  for (char c : expression)
  {
    if (c == ' ')
    {
      if (!token.empty())
      {
        tokens.push_back(token);
        token.clear();
      }
    }
    else
    {
      token += c;
    }
  }
  if (!token.empty())
  {
    tokens.push_back(token);
  }

  size_t index = 0;
  root = buildTreeFromPrefix(tokens, index);
}

ExpressionTree::~ExpressionTree()
{
  clearTree(root);
}

TreeNode* ExpressionTree::getRoot() const
{
  return root;
}

// Построение дерева из префиксной записи
TreeNode* ExpressionTree::buildTreeFromPrefix(std::vector<std::string>& tokens,
                                             size_t& index)
{
  if (index >= tokens.size())
  {
    return nullptr;
  }

  std::string token = tokens[index++];
  TreeNode* node;

  // Проверяем, является ли токен оператором
  if (token == "+")
  {
    node = new TreeNode(-1);
    node->left = buildTreeFromPrefix(tokens, index);
    node->right = buildTreeFromPrefix(tokens, index);
  }
  else if (token == "-")
  {
    node = new TreeNode(-2);
    node->left = buildTreeFromPrefix(tokens, index);
    node->right = buildTreeFromPrefix(tokens, index);
  }
  else if (token == "*")
  {
    node = new TreeNode(-3);
    node->left = buildTreeFromPrefix(tokens, index);
    node->right = buildTreeFromPrefix(tokens, index);
  }
  else if (token == "/")
  {
    node = new TreeNode(-4);
    node->left = buildTreeFromPrefix(tokens, index);
    node->right = buildTreeFromPrefix(tokens, index);
  }
  else if (token == "%")
  {
    node = new TreeNode(-5);
    node->left = buildTreeFromPrefix(tokens, index);
    node->right = buildTreeFromPrefix(tokens, index);
  }
  else if (token == "^")
  {
    node = new TreeNode(-6);
    node->left = buildTreeFromPrefix(tokens, index);
    node->right = buildTreeFromPrefix(tokens, index);
  }
  else
  {
    // Если токен не оператор, это должен быть операнд
    try
    {
      int val = std::stoi(token);
      node = new TreeNode(val);
    }
    catch (...)
    {
      throw std::runtime_error("Invalid token in expression");
    }
  }

  return node;
}

// Вычисление значения поддерева
int ExpressionTree::evaluateSubtree(TreeNode* node)
{
  if (node == nullptr)
  {
    throw std::runtime_error("Invalid node during evaluation");
  }

  // Если узел - лист, возвращаем его значение
  if (isLeaf(node))
  {
    return node->value;
  }

  // Рекурсивно вычисляем левое и правое поддеревья
  int leftVal = evaluateSubtree(node->left);
  int rightVal = evaluateSubtree(node->right);
  int result;

  // Выполняем операцию в зависимости от кода операции
  switch (node->value)
  {
    case -1: // +
      result = leftVal + rightVal;
      break;
    case -2: // -
      result = leftVal - rightVal;
      break;
    case -3: // *
      result = leftVal * rightVal;
      break;
    case -4: // /
      if (rightVal == 0)
      {
        throw std::runtime_error("Division by zero");
      }
      result = leftVal / rightVal;
      break;
    case -5: // %
      if (rightVal == 0)
      {
        throw std::runtime_error("Modulo by zero");
      }
      result = leftVal % rightVal;
      break;
    case -6: // ^
      result = static_cast<int>(std::pow(leftVal, rightVal));
      break;
    default:
      throw std::runtime_error("Unknown operator");
  }

  return result;
}

// Проверка, является ли узел листом
bool ExpressionTree::isLeaf(TreeNode* node) const
{
  return node != nullptr && node->left == nullptr && node->right == nullptr;
}

// Вспомогательная функция для упрощения дерева
void ExpressionTree::simplifyTreeHelper(TreeNode*& node)
{
  if (node == nullptr || isLeaf(node))
  {
    return;
  }

  simplifyTreeHelper(node->left);
  simplifyTreeHelper(node->right);

  if (node->left != nullptr && node->right != nullptr &&
      isLeaf(node->left) && isLeaf(node->right))
  {
    try
    {
      int result = evaluateSubtree(node);
      if (result >= 0 && result <= 9)
      {
        // Удаляем старые узлы
        delete node->left;
        delete node->right;
        node->left = nullptr;
        node->right = nullptr;
        node->value = result;
      }
    }
    catch (...)
    {
      // Игнорируем ошибки вычислений (оставляем дерево как есть)
    }
  }
}

// Упрощение дерева
void ExpressionTree::simplifyTree()
{
  try
  {
    simplifyTreeHelper(root);
  }
  catch (...)
  {
    throw;
  }
}

// Очистка дерева
void ExpressionTree::clearTree(TreeNode* node)
{
  if (node != nullptr)
  {
    clearTree(node->left);
    clearTree(node->right);
    delete node;
  }
}

// Печать дерева (для тестирования)
void ExpressionTree::printTree() const
{
  printTreeHelper(root, 0);
}

// Вспомогательная функция для печати дерева
void ExpressionTree::printTreeHelper(TreeNode* node, int space) const
{
  if (node == nullptr)
  {
    return;
  }

  space += 2;

  printTreeHelper(node->right, space);

  std::cout << std::endl;
  for (int i = 2; i < space; i++)
  {
    std::cout << " ";
  }
  std::cout << node->value << "\n";

  printTreeHelper(node->left, space);
}
