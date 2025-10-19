#include <iostream>
#include <vector>

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
  
  // Constructor
  TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Inorder traversal function (recursive)
void Traversal(TreeNode* node) {
  if (node == nullptr) return;
  
  Traversal(node->left);
  std::cout << node->data << " ";
  Traversal(node->right);
}

// Clear function (recursive)
void Clear(TreeNode* root) {
  if (root == nullptr) return;
  Clear(root->left);
  Clear(root->right);
  delete root;
}

// Insert function (recursive)
TreeNode* Insert(TreeNode* root, const int& value) {
  if (root == nullptr) {
    return new TreeNode(value);
  }

  if (value < root->data) {
    root->left = Insert(root->left, value);
  } else if (value > root->data) {
    root->right = Insert(root->right, value);
  }

  return root;
}

int main() {
  // Build a binary tree manually
  //       4
  //      / \
  //     2   6
  //    / \ / \
  //   1  3 5  7
  
  TreeNode* root = new TreeNode(4);
  root = Insert(root, 2);
  root = Insert(root, 6);
  root = Insert(root, 1);
  root = Insert(root, 3);
  root = Insert(root, 5);
  root = Insert(root, 7);
  
  std::cout << "Inorder Traversal:" << std::endl;
  std::cout << "=============================" << std::endl;
  
  Traversal(root);
  std::cout << std::endl;
  
  // Clean up memory
  Clear(root);
  
  return 0;
}
