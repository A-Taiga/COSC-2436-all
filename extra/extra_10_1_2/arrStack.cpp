#include "arrStack.h"

template<class T>
bool arr_stack<T>::pop()
{
    if(empty())
    {
        return false;
    } else {
        mark--;
        return true;
    }
}
template<class T>
bool arr_stack<T>::push(T _value)
{
    if(mark < size)
    {
        mark++;
        arr[mark] = _value;
        return true;
    } else {
        std::cout << "stack full" << std::endl;
        return false;
    }
}
template<class T>
T  arr_stack<T>::top()
{
    return arr[mark];
}
template<class T>
bool arr_stack<T>::empty()
{
    return mark == -1 ? true : false;
}