#include "ArgumentManager.h"
#include "priority_queue.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stack>
#include <string>

using namespace std;

bool is_valid(string str) {
  if (str.empty())
    return false;

  stack<char> s;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
      s.push(str[i]);
    } else if (str[i] == ')') {
      if (s.empty() || s.top() != '(') {
        return false;
      }
      s.pop();
    } else if (str[i] == ']') {
      if (s.empty() || s.top() != '[') {
        return false;
      }
      s.pop();
    } else if (str[i] == '}') {
      if (s.empty() || s.top() != '{') {
        return false;
      }
      s.pop();
    }
  }
  if (!s.empty())
    return false;
  return true;
}
int pemdas(char c) {
  switch (c) {
  case '^':
    return 3;
  case '*':
  case '/':
    return 2;
  case '+':
  case '-':
    return 1;
  default:
    return -1;
  }
}
double operation(char c, int opr1, int opr2) {
  switch (c) {
  case '^':
    return pow(opr1, opr2);
  case '*':
    return opr1 * opr2;
  case '/':
    return opr1 / opr2;
  case '+':
    return opr1 + opr2;
  case '-':
    return opr1 - opr2;
  default:
    return 0;
  }
}
string postfix(string str) {
  stack<char> stack;
  string result = "";
  for (int i = 0; i < str.length(); i++) {
    if (isdigit(str[i])) {
      result += str[i];
    } else if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      stack.push(str[i]);
    } else {

      if (str[i] == ')') {
        while (stack.top() != '(') {
          result += stack.top();
          stack.pop();
        }
        stack.pop();
      } else if (str[i] == ']') {
        while (stack.top() != '[') {
          result += stack.top();
          stack.pop();
        }
        stack.pop();
      } else if (str[i] == '}') {
        while (stack.top() != '{') {
          result += stack.top();
          stack.pop();
        }
        stack.pop();
      } else {
        while (!stack.empty() && pemdas(str[i]) <= pemdas(stack.top())) {
          result += stack.top();
          stack.pop();
        }
        stack.push(str[i]);
      }
    }
  }
  while (!stack.empty()) {
    result += stack.top();
    stack.pop();
  }
  return result;
}
double solve(string exp) {
  stack<string> stack;
  for (int i = 0; i < exp.length(); i++) {
    if (isdigit(exp[i])) {
      stack.push(string(1, exp[i]));
    } else {
      double opr2 = stod(stack.top());
      stack.pop();
      double opr1 = stod(stack.top());
      stack.pop();
      stack.push(to_string(operation(exp[i], opr1, opr2)));
    }
  }
  return stod(stack.top());
}
bool is_redundant(string a) {
  stack<char> s;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == ')') {
      if (s.top() == '(') {
        return true;
      }
      while (s.top() != '(') {
        s.pop();
      }
      s.pop();
    } else if (a[i] == ']') {
      if (s.top() == '[') {
        return true;
      }
      while (s.top() != '[') {
        s.pop();
      }
      s.pop();
    } else if (a[i] == '}') {
      if (s.top() == '{') {
        return true;
      }
      while (s.top() != '{') {
        s.pop();
      }
      s.pop();
    } else {
      s.push(a[i]);
    }
  }
  return false;
}
int main(int argc, char *argv[]) {

  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));
  // ifstream input("input1.txt");
  // ofstream output("output1.txt");
  priority_queue pq;
  string line;
  while (getline(input, line)) {
    line.erase(remove(line.begin(), line.end(), '\r'), line.end());
    line.erase(remove(line.begin(), line.end(), '\n'), line.end());
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    // cout << line << endl;
    if (is_valid(line) && !is_redundant(line)) {
      pq.enqueue(line, solve(postfix(line)));
      cout << line << endl;
    }
  }
  if (pq.empty()) {
    cout << "No Valid Expression\n";
    output << "No Valid Expression\n";
  } else {
    while (!pq.empty()) {
      output << pq.front()->expression << endl;
      cout<< pq.front()->expression << endl;
      pq.dequeue();
    }
  }
  return 0;
}