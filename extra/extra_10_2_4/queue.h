#ifndef QUEUE_H
#define QUEUE_H
template<class T>
struct Node {
  T val;
  Node<T> *next;
};
template<class T>
class queue {
private:
  Node<T> *head;
  Node<T> *tail;
public:
  queue():head(nullptr),tail(nullptr){}
  void enqueue(int _val);
  bool dequeue();
  bool empty();
  T front();
  T back();
};
#endif