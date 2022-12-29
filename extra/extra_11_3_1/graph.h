#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <iomanip>

struct Node {
    int val;
    int weight;
    Node *next;
    Node(int _val, int _weight):val(_val),weight(_weight),next(nullptr){}
};
class list {
private:
    Node *head;
    Node *tail;
public:
    list():head(nullptr),tail(nullptr){}
    void add(int val, int weight);
    Node* get_head();
};

class graph {
private:
    int size;
    list **arr;
public:
    graph(int _size);
    void add(int src, int dest, int weight = 1);
    void print();
};



#endif