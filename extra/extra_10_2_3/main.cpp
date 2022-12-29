//extra_10_2_3 queue as linked list
#include <iostream>
#include "queue.h"
using namespace std;
int main()
{
    queue q;
    cout << "into queue: ";
    for(int i = 1; i <= 20; i++)
    {
        cout << i << " ";
        q.enqueue(i);
    }
    cout << endl;
    cout << "out of queue ";
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.dequeue();
    }
    cout << endl;
    return 0;
}