#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iostream>
struct Node {
    std::string job;
    double time;
    Node *next;
};
class priority_queue {
private:
    Node *front;

public:
    priority_queue():front(nullptr){}
    void enqueue(std::string,double);
    bool dequeue();
    Node* peek();
    bool empty();


};
#endif