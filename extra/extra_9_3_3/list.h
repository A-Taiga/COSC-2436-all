#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
struct Node {
    int value;
    Node *next;
};
class list {
private:
    Node *head;
public:
    list();
    void add(int);
    void print();
    void sort(Node* node_i, Node *node_j);
    Node* get_head();

};
#endif