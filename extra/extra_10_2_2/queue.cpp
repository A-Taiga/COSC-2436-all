#include "queue.h"

template<class T>
queue<T>::queue(int _size)
{
    size = _size;
    arr = new T[size];
    rear = -1;
    front = 0;
}
template<class T>
void queue<T>::enqueue(T _val)
{
    try {
        throw q_exception(rear,size);
    } catch(q_exception e) {
        e.size_error();
    }
    front = 0;
    rear++;
    arr[rear] = _val;
}
template<class T>
void queue<T>::dequeue()
{
    try {
        throw q_exception(rear);

    } catch(q_exception e) {
        e.empty_error();
    }
    shift();
    rear--;

}
template<class T>
bool queue<T>::empty()
{
    if(rear == -1)
        return true;
    else 
        return false;
}
template<class T>
T queue<T>::peak()
{
    try {
        throw q_exception(front);
    } catch(q_exception e) {
        e.empty_error();
    }
    return arr[front];
}
template<class T>
T queue<T>::back()
{
    try {
        throw q_exception(back);
    } catch(q_exception e) {
        e.empty_error();
    }
    return arr[rear];
}
template<class T>
void queue<T>::shift()
{
    for(int i = 1; i <= rear; i++)
    {
        arr[i-1] = arr[i];
    }
}