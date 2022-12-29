#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    myStack::stack stack;
    for(int i = 0; i < 10; i++)
    {
        stack.push(i);
    }
    while(!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }
    return 0;
}