//extra_10_1_3 templated stack using linked list

#include <iostream>
#include "stack.cpp"
using namespace std;
int main()
{
    stack<char> stack;

    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(size_t i = 0; i < a.length(); i++)
    {
        stack.push(a[i]);
    }
    while(!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }
    cout << endl;
    return 0;
};
