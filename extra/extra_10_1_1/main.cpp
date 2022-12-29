//extra_10_1_1
// stack as an array

#include <iostream>
#include "arrStack.h"
using namespace std;

int main()
{
    arr_stack stack(100);
    for(int i = 0; i < 20; i++)
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
