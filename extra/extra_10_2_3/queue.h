#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
struct Node
{
    int val;
    Node *next;
    Node(int _val, Node* _next = nullptr):val(_val),next(_next){}
};
class queue
{
private:
    Node *head;
    Node *tail;
public:
    queue():head(nullptr),tail(nullptr){}
    void enqueue(int _val);
    bool dequeue();
    int front();
    int back();
    bool empty();

};


#endif