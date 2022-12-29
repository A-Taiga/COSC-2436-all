#ifndef LIST_H
#define LIST_H
#include <iostream>
struct Node {
    std::string key;
    int val;
    Node* next;
    Node(std::string _key, int _val):key(_key),val(_val),next(nullptr){}
};
class list {
private:
    Node* head;
    Node* tail;
public:
    list():head(nullptr),tail(nullptr){}
    void push(std::string,int);
    bool pop();
    Node* front();
    bool empty();
};
#endif