#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

template<class T1, class T2>
struct Node {
    T1 key;
    T2 val;
    int height;
    Node<T1,T2> *left;
    Node<T1,T2> *right;
    Node(T1 _key, T2 _val):key(_key),val(_val),height(0),left(nullptr),right(nullptr){}
};

template<class T1, class T2>
class tree {

private:

    Node<T1,T2> *root;
    Node<T1,T2>* add(Node<T1,T2>*,Node<T1,T2>*);
    Node<T1,T2>* deletion(Node<T1,T2>*,T1);
    Node<T1,T2>* single_right(Node<T1,T2>*);
    Node<T1,T2>* single_left(Node<T1,T2>*);
    Node<T1,T2>* double_right(Node<T1,T2>*);
    Node<T1,T2>* double_left(Node<T1,T2>*);
    Node<T1,T2>* find(Node<T1,T2>*, T1);
    Node<T1,T2>* find_min(Node<T1,T2>*);
    int height(Node<T1,T2>*);
    int Bf(Node<T1,T2>*);
    void preorder_print(Node<T1,T2>*);
    void inorder_print(Node<T1,T2>*);
    void postorder_print(Node<T1,T2>*);

public:
    
    tree():root(nullptr){}
    void insert(T1,T2);
    T2 search(T1);
    void remove(T1);
    void level_order();
    void preorder();
    void inorder();
    void postorder();



};

#endif