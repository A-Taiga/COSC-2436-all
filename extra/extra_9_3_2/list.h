#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct Node {
    int num;
    Node *next;
};
class list {

private: 
    Node *head;
    Node *tail;
public:
    list();
    void add(int);
    void sort(Node *node_i, Node *node_j);
    Node* middle(Node* start, Node* last);
    bool search(int x);
    bool recursive_search(int x, Node *start, Node *end);
    void print();
    Node* get_head() {
        return this->head;
    }
    Node* get_tail() {
        return this->tail;
    }
};
#endif