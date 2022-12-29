#ifndef ARRSTACK_H
#define ARRSTACK_H
#include <iostream>
template<class T>
class arr_stack
{
private:
    int mark;
    T *arr;
    int size;
public:
    arr_stack(int _size = 10)
    {
        mark = -1;
        size = _size;
        arr = new T[_size];
    }
    bool pop();
    bool push(T);
    T top();
    bool empty();

};
#endif