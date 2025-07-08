// CalcTree7.h
#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cmath>

// Класс для представления узла дерева выражения
class TreeNode
{
public:
  int value;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val, TreeNode* l = nullptr, TreeNode* r = nullptr);
  ~TreeNode();
};

// Основной класс для работы с деревом выражений
class ExpressionTree
{
public:
  ExpressionTree(const std::string& filename);
  ~ExpressionTree();

  TreeNode* getRoot() const;
  void simplifyTree();
  void printTree() const;

private:
  TreeNode* root;

  TreeNode* buildTreeFromPrefix(std::vector<std::string>& tokens, size_t& index);
  int evaluateSubtree(TreeNode* node);
  bool isLeaf(TreeNode* node) const;
  void clearTree(TreeNode* node);
  void printTreeHelper(TreeNode* node, int space) const;
  void simplifyTreeHelper(TreeNode*& node); // Добавлено объявление
};
