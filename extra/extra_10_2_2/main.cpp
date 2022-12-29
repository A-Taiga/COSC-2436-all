//extra_10_2_2 template queue array
#include <iostream>
#include "queue.cpp"
using namespace std;
int main() 
{
    queue<char> q(26);
    cout << "into queue: ";
    for(int i = 'A'; i <= 'Z'; i++)
    {
        cout << (char)i << " ";
        q.enqueue((char)i);
    }
    cout << endl;
    cout << "out of queue: ";
    while(!q.empty())
    {  
        cout << q.peak() << " ";
        q.dequeue();
    }
    cout << endl;
    /////////////////////////////////////
    cout << "into queue: ";
    for(int i = '0'; i <= 'A'; i++)
    {
        cout << (char)i << " ";
        q.enqueue((char)i);
    }
    cout << endl;
    cout << "out of queue: ";
    while(!q.empty())
    {  

        cout << q.peak() << " ";
        q.dequeue();
    }
    cout << endl;

    return 0;
}
