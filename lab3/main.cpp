#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <cctype>
#include <string>
#include <iomanip>
#include "ArgumentManager.h"
using namespace std;

double operation(double a, double b, char op)
{
    switch(op)
    {
        case '*': return a *b;
        case '/': return a/b;
        case '+': return a+b;
        case '-': return a-b;
        default:  return 0;
    }
}
int compare(char c) {
    switch(c)
    {
        case '*':
        case '/':return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}
char opposite(char c)
{
    switch(c)
    {
        case '*': return '/';
        case '/': return '*';
        case '+': return '-';
        case '-': return '+';
        default: return 0;
    }
}

string infix_to_post(string str)
{
    std::stack<char> operation_stack;
    string postfixed = "";
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
        {
            operation_stack.push('(');
        } 
        else if (str[i] == ')')
        {
            while(!operation_stack.empty() && operation_stack.top() != '(')
            {
                postfixed += operation_stack.top();
                operation_stack.pop();
            }
            operation_stack.pop();
        }
        else if(isalnum(str[i]))
        {
            postfixed += str[i];
        }
        else
        {
            while(!operation_stack.empty() && compare(operation_stack.top()) >= compare(str[i]))
            {
                postfixed += operation_stack.top();
                operation_stack.pop();
            }
            operation_stack.push(str[i]);
        }
    }
    while(!operation_stack.empty())
    {
        postfixed += operation_stack.top();
        operation_stack.pop();
    }
    cout << postfixed << endl;
    return postfixed;
}
int main(int argc, char* argv[])
{
    ArgumentManager am(argc,argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));
    // ifstream input("test.txt");
    string equation = "";
    char c;
    while(input >> c){
        equation+=c;
    }
    double right_side = stod(equation.substr(equation.find('=')+1));
    string postfixed = infix_to_post(equation.substr(0,equation.find('=')));
    string x_save = "";
    std::stack<string> num_stack;
    string operand2;
    string operand1;
    for(int i = 0; i < postfixed.length(); i++)
    {
        if(isalnum(postfixed[i]))
        {
            num_stack.push(string(1,postfixed[i]));
        } else {
            if(num_stack.size() >= 2)
            {
                operand2 = num_stack.top();
                num_stack.pop();
                operand1 = num_stack.top();
                num_stack.pop();

                if(operand2 == "x")
                {
                    if(postfixed[i] == '/')
                    {
                        x_save = operand1 + " " + "x" + " " + postfixed[i];
                        num_stack.push("x");
                    } else {
                        right_side = operation(right_side,stod(operand1),opposite(postfixed[i]));
                        num_stack.push("x");
                    }
                } else if(operand1 == "x") {
                    right_side = operation(right_side,stod(operand2),opposite(postfixed[i]));
                    num_stack.push("x");
                } else {
                    num_stack.push(to_string(operation(stod(operand1),stod(operand2),postfixed[i])));
                }
            }
        }
    }
    if(!x_save.empty())
    {
        istringstream ss(x_save);
        string op;
        ss >> operand1;
        right_side = operation(1/right_side,stod(operand1),'*');
    }
    output << setprecision(2) << fixed;
    output << right_side << endl;
    // cout << setprecision(2) << fixed;
    // cout << right_side << endl;
    return 0;
}