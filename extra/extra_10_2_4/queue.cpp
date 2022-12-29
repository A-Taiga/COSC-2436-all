#include "queue.h"
#include <iostream>
using namespace std;
template<class T>
void queue<T>::enqueue(int _val)
{
  Node<T> *new_node = new Node<T>();
  new_node->val = _val;
  new_node->next = nullptr;
  if(head == nullptr)
  {
    head = new_node;
    tail = new_node;
  } else {
    tail->next = new_node;
    tail = tail->next;
  }
}
template<class T>
bool queue<T>::dequeue()
{
  if(head == nullptr)
  {
    cout << "queue is empty" << endl;
    return false;
  } else {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
    return true;
  }
}
template<class T>
bool queue<T>::empty()
{
  if(head == nullptr)
    return true;
  return false;
}
template<class T>
T queue<T>::front()
{
  return head->val;
}
template<class T>
T queue<T>::back()
{
  return tail->val;
}