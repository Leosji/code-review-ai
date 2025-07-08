#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

// Узел дерева
class Node {
public:
  int value;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;

  Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функции работы с деревом
std::shared_ptr<Node> buildTree(std::vector<std::string>& tokens, int& index);
void optimizeTree(std::shared_ptr<Node>& root);
void printTree(std::shared_ptr<Node> root, int depth = 0);
