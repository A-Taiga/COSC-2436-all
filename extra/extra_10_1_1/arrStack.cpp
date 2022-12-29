#include "arrStack.h"

bool arr_stack::pop()
{
    if(empty())
    {
        return false;
    } else {
        mark--;
        return true;
    }
}
bool arr_stack::push(int _value)
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
int  arr_stack::top()
{
    return arr[mark];
}
bool arr_stack::empty()
{
    return mark == -1 ? true : false;
}