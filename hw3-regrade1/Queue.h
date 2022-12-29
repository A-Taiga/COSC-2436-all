#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <vector>
using namespace std;

// This file is provided to assist with the hw, but you can change or implement the solution in your own way.
// Hint: use queue to keep track of the matrix and the moves for the matrix.





struct Pair {
  vector<vector<char>> matrix;
  string moves;
  Pair(){}
  Pair(vector<vector<char>> _matrix, string _moves):matrix(_matrix),moves(_moves){}
};

struct qNode {
  Pair data;
  qNode *next;
};

class Queue {
private:
  qNode *front;
  qNode *rear;

public:
  Queue();
  bool isEmpty();
  void enqueue(Pair);
  Pair dequeue();
  Pair peek();
  void debug_print();
};

Queue::Queue() {
  front = nullptr;
  rear = nullptr;
}

bool Queue::isEmpty() { return (front == nullptr); }

void Queue::enqueue(Pair p) {
  qNode *temp = new qNode();
  temp->data = p;
  temp->next = nullptr;
  if (isEmpty()) {
    front = temp;
    rear = temp;
  } else {
    rear->next = temp;
    rear = temp;
  }
}

Pair Queue::dequeue() {
  Pair temp = front->data;
  qNode *del = front;
  front = front->next;
  delete del;
  return temp;
}

Pair Queue::peek() {
  Pair temp = front->data;
  return temp;
}

void Queue::debug_print()
{
  qNode *cu = front;

  while(cu != nullptr) {

    for(int i = 0; i < cu->data.matrix.size(); i++) {
      for(int j = 0; j < cu->data.matrix[0].size(); j++) {

        cout << cu->data.matrix[i][j] << " ";
      }
      cout << endl;
    }
    cout << cu->data.moves << endl;
    cout << endl;

    cu = cu->next;
  }
}



#endif