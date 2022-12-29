#include "queue.h"
queue::queue(int _size)
{
    size = _size;
    arr = new int[size];
    rear = -1;
    front = 0;
}
void queue::enqueue(int _val)
{
    try {
        throw q_exception(rear, size);
    } catch(q_exception e) {
        e.full_error();
    }
    front = 0;
    rear++;
    arr[rear] = _val;
}
void queue::dequeue()
{
    try {
        throw q_exception(front);
    } catch(q_exception e) {
        e.empty_error();
    }
    shift();
    rear--;
}
bool queue::empty()
{
    if(rear == -1)
        return true;
    else
        return false;
}
int  queue::peak()
{
    try{
        throw q_exception(front);
    } catch (q_exception e) {
        e.empty_error();
    }
    return arr[front];
}
int  queue::back()
{
    try {
        throw q_exception(front);
    } catch(q_exception e) {
        e.empty_error();
    }
    return arr[rear];
}
void queue::shift()
{
    for(int i = 1; i <= rear; i++)
    {
        arr[i-1] = arr[i];
    }
}