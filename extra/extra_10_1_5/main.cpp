#include <iostream>
#include <math.h>
#include <sstream>
#include <ctype.h>
#include <stack>
using namespace std;


int pemdas(char c)
{
    switch(c)
    {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default:  return 0;
    }
}
double operation(double a, double b, char op)
{
    switch(op)
    {
        case '^': return pow(a,b);
        case '*': return a * b;
        case '/': return a / b;
        case '+': return a + b;
        case '-': return a - b;
        default:  return 0;
    }
}
bool isNegative(string input)
{
    return input[0] == '-';
}
string infix_to_postfix(string infix)
{
    stack<char> operators;
    string postfixed = "";
    string str;
    istringstream ss(infix);
    while(ss >> str)
    {
        if(str == "(")
        {
            operators.push('(');
        }
        else if (str == ")")
        {
            while(operators.top() != '(')
            {
                postfixed += string(1,operators.top()) + ' ';
                operators.pop();
            }
            operators.pop();
        } 
        else if(str[0] == '-' && isdigit(str[1]))
        {
            postfixed += str + ' ';
        }   
        else if(isdigit(str[0]))
        {
            postfixed += str + ' ';
        }
        else
        {
            while(!operators.empty() && pemdas(operators.top()) >= pemdas(str[0]))
            {
                postfixed += string(1,operators.top()) + ' ';
                operators.pop();
            }
            operators.push(str[0]);
        }
    }
    while(!operators.empty())
    {
        postfixed += string(1,operators.top()) + ' ';
        operators.pop();
    }
    cout << "postfixed: " << postfixed << endl;
    return postfixed;
}
int main()
{
    string equation = "( 16 / 2 ^ -3 + 3 * ( -6 + 20 ) )";
    cout << "infix: " << equation << endl;
    stack<double> operands;
    string var;
    istringstream ss(infix_to_postfix(equation));
    while(ss >> var)
    {
        if(isdigit(var[0]) || (var[0] == '-' && isdigit(var[1])))
        {
            operands.push(stod(var));
        }
        else
        {
            double opr2 = operands.top();
            operands.pop();
            double opr1 = operands.top();
            operands.pop();

            operands.push(operation(opr1,opr2,var[0]));
        }
    }
    cout << "solved: " << operands.top() << endl;
    return 0;
}