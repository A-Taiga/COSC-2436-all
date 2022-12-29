#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <queue>
#include <cmath>
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
    Node* single_right(Node*);
    Node* single_left(Node*);
    Node* double_right(Node*);
    Node* double_left(Node*);
    int height(Node*);
    int balance_factor(Node*);
    void print_preorder(Node*);
    void print_inorder(Node*);
    void print_postorder(Node*);
    Node* remove_node(Node*,int);
    Node* find_min(Node*);
public:
    tree():root(nullptr){};
    void insert(int val);
    void preorder();
    void inorder();
    void postorder();
    void level_order();
    int tree_height();
    void remove(int);


};
#endif