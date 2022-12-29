#include "stack.h"
template<class T>
void stack<T>::pop()
{
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    size--;
}
template<class T>
void stack<T>::push(T _val)
{
    Node<T> *new_n = new Node<T>(_val);
    new_n->next = head;
    head = new_n;
    size++;
}
template<class T>
T stack<T>::top()
{
    return head->val;
}
template<class T>
bool stack<T>::empty()
{
    if(head == nullptr)
    {
        return true;
    } else {
        return false;
    }
}
template<class T>
int stack<T>::get_size()
{
    return size;
}