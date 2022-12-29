#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <ostream>

template<typename T>
struct Node {

    T data;
    Node<T>* next;

};

template<typename T>
class list {

private:
Node<T> *head;

public:
    list();
	void push_back(T);
	void push_front(T);
	void remove_head();
	void remove_tail();
	void print(std::ostream&);
	~list();
};
#endif