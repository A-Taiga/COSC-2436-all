#include <iostream>
#include "queue.cpp"
using namespace std;
int main() {
  queue<int> q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
 while(!q.empty())
   {
     cout << q.front() << " ";
     q.dequeue();
   }
  cout << endl;
  
  q.enqueue(10);
  q.enqueue(9);
  q.enqueue(8);
  q.enqueue(7);

  
  while(!q.empty())
   {
     cout << q.front() << " ";
     q.dequeue();
   }
  cout << endl;    
  
}