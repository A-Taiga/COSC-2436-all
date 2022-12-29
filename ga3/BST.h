#include <iostream>
using namespace std;

struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;
};

class BST {
private:
  TreeNode *root;
  bool added;

public:
  BST() { root = nullptr; };
  void traverse(TreeNode *curr, int v) {
    if (curr == nullptr)
      return;
    if (curr->left == nullptr && curr->value > v) {
      TreeNode *temp = new TreeNode();
      temp->value = v;
      curr->left = temp;
      return;
    }
    if (curr->right == nullptr && curr->value < v) {
      TreeNode *temp = new TreeNode();
      temp->value = v;
      curr->right = temp;
      return;
    }
    if (curr->value > v)
      traverse(curr->left, v);
    else
      traverse(curr->right, v);
  };

  void insert(int v) {
    if (root == nullptr) {
      TreeNode *temp = new TreeNode();
      temp->value = v;
      root = temp;
      return;
    }

    traverse(root, v);
  };
  TreeNode *getRoot() { return root; }
  string preOrder(TreeNode *curr, string direction) {
    if (curr == nullptr)
      return "";
    string str;
		string temp = direction;
    str += direction + " " + to_string(curr->value) + "\n";
		temp = direction.substr(0, direction.find("]")) + "l" + "]";
    str += preOrder(curr->left, temp);
		temp = direction.substr(0, direction.find("]")) + "r" + "]";
    str += preOrder(curr->right, temp);
    return str;
  }
  // string postOrder(TreeNode *curr) {
  //   if (curr == nullptr)
  //     return "";
  //   string str;
  //   str += postOrder(curr->left);
  //   str += postOrder(curr->right);
  //   str += curr->message + "\n";
  //   return str;
  // }
  // string inOrder(TreeNode *curr) {
  //   if (curr == nullptr)
  //     return "";
  // string str;
  //   str += inOrder(curr->left);
  //   str += curr->message + "\n";
  //   str += inOrder(curr->right);
  // return str;
  // }
};