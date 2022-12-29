#ifndef ARRSTACK_H
#define ARRSTACK_H
#include <iostream>
class arr_stack
{
private:
    int mark;
    int *arr;
    int size;
public:
    arr_stack(int _size = 10)
    {
        mark = -1;
        size = _size;
        arr = new int[_size];
    }
    bool pop();
    bool push(int);
    int top();
    bool empty();

};
#endif