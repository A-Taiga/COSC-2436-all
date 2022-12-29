#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
namespace myStack
{

struct Node
{
    int val;
    Node *next;
    Node(int _val):val(_val),next(nullptr){}
};

class stack
{
private:
    Node *head;
    int size;
public:
    stack():head(nullptr),size(0){}
    void push(int);
    bool pop();
    int top();
    int get_size();
    bool empty();
};

}
#endif