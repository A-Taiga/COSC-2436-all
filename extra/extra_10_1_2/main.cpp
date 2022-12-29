//extra_10_1_2
// templates with stack as array reverse the alphabet 
#include <iostream>
#include "arrStack.cpp"
using namespace std;

int main()
{
    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    arr_stack<char> stack(a.length());
    for(int i = 0; i < a.length(); i++)
    {
        stack.push(a[i]);
    }
    while(!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }
    return 0;
}
