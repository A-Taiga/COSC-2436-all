#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
class queue 
{
private:
    int *arr;
    int size;
    int front;
    int rear;
    void shift();
public:
    queue(int _size = 10);
    void enqueue(int _val);
    void dequeue();
    bool empty();
    int peak();
    int back();
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
    q_exception(int _index, int _size = 0):index(_index), size(_size){}
    void empty_error()
    {
        if(index == -1)
        {
            std::cout << "EXCEPTION: empty_error" << std::endl;
            exit(0);
        }
        return;
    }
    void full_error()
    {
        if(index == size-1) {
            std::cout << "EXCEPTION: full_error" << std::endl;
            exit(0);
        }
        return;
    }
};


#endif