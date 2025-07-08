#pragma once
#include <string>

// Узел дерева
struct TreeNode
{
  int value; // Операция (от -1 до -6) или число (0–9)
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val);
  ~TreeNode();
};

TreeNode* buildTree(const std::string& expression, int& pos);
TreeNode* simplifyTree(TreeNode* root);
void printTree(TreeNode* node, int depth = 0);
int evaluate(TreeNode* node);
void freeTree(TreeNode* node);
