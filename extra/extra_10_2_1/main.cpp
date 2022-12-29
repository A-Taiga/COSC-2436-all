// extra_10_2_1 queue as an array
#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    queue q(10);
    
    cout << "into queue: ";
    for(int i = 0; i < 10; i++)
    {
        int random = rand() % 9;
        cout << random << " ";
        q.enqueue(random);
    }
    cout << endl;
    cout << "out of queue" << " ";
    while(!q.empty())
    {
        cout << q.peak() << " ";
        q.dequeue();
    }
    cout << endl;
    return 0;
}