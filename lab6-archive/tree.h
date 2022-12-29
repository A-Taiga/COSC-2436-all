#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cmath>
#include <queue>

struct Node {
    int val;
    int height;
    Node *left;
    Node *right;
    Node(int _val):val(_val),height(0),left(nullptr),right(nullptr){}
};
class tree {
private:
    Node *root;
    Node* add(Node*,Node*);
    Node* single_left(Node*);
    Node* single_right(Node*);
    Node* double_left(Node*);
    Node* double_right(Node*);
    int balance_factor(Node*);
    int height(Node*);


public:
    tree():root(nullptr){}
    void insert(int);
    std::string level_order();

};
#endif