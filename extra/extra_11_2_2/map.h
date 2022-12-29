#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <queue>
#include <cmath>

template<class T>
struct Node {
    T key;
    int frequency;
    int height;
    Node<T>* left;
    Node<T>* right;
    Node(T _key):key(_key),frequency(1),height(0),left(nullptr),right(nullptr){}
};

template<class T>
class map {
private:
    Node<T>* root;
    int size;
    Node<T>* add(Node<T>*,Node<T>*);
    Node<T>* single_right(Node<T>*);
    Node<T>* single_left(Node<T>*);
    Node<T>* double_right(Node<T>*);
    Node<T>* double_left(Node<T>*);
    int balance_factor(Node<T>*);
    int height(Node<T>*);
    void print_inorder(Node<T>*);
    int get_node_count(Node<T>*);
public:
    map():root(nullptr),size(0){}
    void insert(T);
    void print();
    void level_order();
    int get_size();
    int get_height();
    int element_count();
};

#endif