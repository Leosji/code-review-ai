#include "CalcTree.h"
#include <sstream>
#include <cmath>

std::shared_ptr<Node> buildTree(std::vector<std::string>& tokens, int& index) {
  if (index >= tokens.size()) return nullptr;

  std::string token = tokens[index++];
  int val = (isdigit(token[0])) ? std::stoi(token) :
    (token == "+" ? -1 : token == "-" ? -2 :
     token == "*" ? -3 : token == "/" ? -4 :
     token == "%" ? -5 : token == "^" ? -6 : 0);

  auto node = std::make_shared<Node>(val);
  std::cout << "Создан узел: " << val << std::endl;  // Fix me (Добавил вывод узла)

  if (val < 0) {
    node->left = buildTree(tokens, index);
    node->right = buildTree(tokens, index);
  }

  return node;
}

void optimizeTree(std::shared_ptr<Node>& root) {
  if (!root || root->value >= 0) return;

  optimizeTree(root->left);
  optimizeTree(root->right);

  if (root->left && root->right &&
      root->left->value >= 0 && root->right->value >= 0) {
    int result;
    switch (root->value) {
      case -1: result = root->left->value + root->right->value; break;
      case -2: result = root->left->value - root->right->value; break;
      case -3: result = root->left->value * root->right->value; break;
      case -4: result = root->right->value != 0 ? root->left->value / root->right->value : 0; break;
      case -5: result = root->right->value != 0 ? root->left->value % root->right->value : 0; break;
      case -6: result = std::pow(root->left->value, root->right->value); break;
      default: result = 0;
    }
    if (result >= 0 && result <= 9) {
      root->value = result;
      root->left = root->right = nullptr;
    }
  }
}

// Функция для форматированного вывода дерева
void printTree(std::shared_ptr<Node> root, int depth) {
  if (!root) return;

  printTree(root->right, depth + 1);

  std::cout << std::string(depth * 4, ' ') << root->value << "\n";  // Fix me (Добавил визуализацию)

  printTree(root->left, depth + 1);
}
