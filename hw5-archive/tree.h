#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cmath>
#include <queue>
#include <fstream>
#include <ostream>

using namespace std;

struct Node{
  int* keys;
  Node** childptr;
  bool leaf;
  int size;

  Node(int degree) {
    keys = new int[degree];
    childptr = new Node*[degree+1];
    leaf = true;
    size = 0;

    for(int i=0; i<degree; i++) {
      keys[i] = -1;
    }
    for(int i=0; i<degree+1; i++) {
      childptr[i] = nullptr;
    }
  }
};

class tree {
private:
    Node* root;
    int degree;
  

public:
    tree(int _degree):root(nullptr),degree(_degree){}
    void insert(int data);
    void addAtLeaf(Node *parent, Node *n, int data);
    void splitChild(Node* parent, Node* left);


    void print_level(int level,std::ofstream &out);
    int get_height(Node *root) 
    {
        if (root == nullptr)
          return 0;
        return 1 + get_height(root->childptr[0]);
    }
    int height()
    {
      return get_height(root);
    }

};

#endif