#ifndef STACK_H
#define STACK_H
#include <iostream>
template<class T>
struct Node
{
    T val;
    Node *next;
    Node(T _val):val(_val),next(nullptr){}
    Node(){}
};
template<class T>
class stack
{
private:
    Node<T> *head;
    int size;
public:
    stack():head(nullptr),size(0){}
    void pop();
    void push(T);
    T top();
    bool empty();
    int get_size();
};
#endif