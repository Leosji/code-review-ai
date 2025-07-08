#pragma once

#include <string>
#include <vector>

// Узел дерева арифметического выражения
class TreeNode
{
public:
  int value; // значение от 0 до 9 или код операции (-1 до -6)
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val);
  ~TreeNode();
};

// Класс для построения и упрощения дерева выражений
class ExpressionTree
{
public:
  ExpressionTree(const std::string& expr);
  ~ExpressionTree();

  void printTree() const;
  void simplifyTree();
  TreeNode* getRoot() const;

private:
  TreeNode* root;

  TreeNode* buildTreeFromTokens(const std::vector<std::string>& tokens, int& index);
  void tokenize(const std::string& expr, std::vector<std::string>& tokens);

  // Объявляем с новыми параметрами для красивого вывода
  void printTreeHelper(TreeNode* node, std::string prefix, bool isLeft) const;

  void clearTree(TreeNode* node);
  int evaluate(TreeNode* node);
  bool isLeaf(TreeNode* node) const;
  void simplifyHelper(TreeNode*& node);
};
