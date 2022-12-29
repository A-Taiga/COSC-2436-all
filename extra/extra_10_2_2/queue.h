#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
template<class T>
class queue
{
private:
    int size;
    T *arr;
    int front;
    int rear;
    void shift();
public:
    queue(int _size = 10);
    void enqueue(T _val);
    void dequeue();
    bool empty();
    T peak();
    T back();
     void debug()
    {
        std::cout << "F: " <<  front << " " << "R: " << rear << std::endl;
    }
};
class q_exception
{
private:
    int index;
    int size;
public:
    q_exception(int _index, int _size = 0):index(_index),size(_size){}
    void empty_error()
    {
        if(index == -1)
        {
            std::cout << "EXCEPTION: empty_error" << std::endl;
            exit(0);
        }
        return;
    }
    void size_error()
    {
        if(index == size-1)
        {
            std::cout << "EXCEPTION: size_error" << std::endl;
            exit(0);
        }
        return;
    }
};
#endif