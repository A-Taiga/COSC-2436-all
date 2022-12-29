#include "ArgumentManager.h"
#include "list.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

string decode(string line) {
  string reverse;
  stack<string> _stack;
  queue<string> _queue;

  for (int i = 0; i < line.length(); i++) {
    if (line[i] == '(')
      _stack.push("(");
    else if (line[i] == ')') {
      while (_stack.top() != "(") {
        _queue.push(_stack.top());
        _stack.pop();
      }
      _stack.pop();
      if (_stack.size() > 0) {
        while (_queue.size() > 0) {
          _stack.push(_queue.front());
          _queue.pop();
        }
      } else {
        while (_queue.size() > 0 && _queue.front() != "(") {
          reverse += _queue.front();
          _queue.pop();
        }
      }
    } else if (_stack.size() > 0)
      _stack.push(string(1, line[i]));
    else
      reverse += line[i];
  }

  while (_queue.size() > 0 && _queue.front() != "(") {
    reverse += _queue.front();
    _queue.pop();
  }
  return reverse;
}

int main(int argc, char *argv[]) {

  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));

  //ifstream input("input11.txt");
  //ofstream output("output.txt");

  string line;
  list l, guilty;
  set<string> set;

  bool add1;
  while (getline(input, line)) {
    line.erase(remove(line.begin(), line.end(), '\r'), line.end());
    line.erase(remove(line.begin(), line.end(), '\n'), line.end());
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    if (line.length() == 0 || line == "Bar1" || line == "Bar2") 
      continue;
    // cout << line << endl;
    string decoded = decode(line);
    if (set.size() > 0 && set.find(decoded) != set.end()) {
      guilty.add(guilty.getHead(), decoded);
      l.remove(l.getHead(), decoded);
      // cout << "Remove" << endl;
      continue;
    }
    set.insert(decoded);
    l.add(l.getHead(), decoded);
    // cout << "Add" << decoded << " to the list" << endl;
    // cout << decode(line) << endl;
  }

  guilty.sort(guilty.getHead());
  l.sort(l.getHead());

  string ans;
  if (guilty.getSize() > 0) {
     output << "Guilty:\n";
    cout << "Guilty:\n";
     guilty.print(output, guilty.getHead());
   }
   if (l.getSize() > 0) {
     output << "Innocent:\n";
     cout << "Innocent:\n";
     l.print(output, l.getHead());
   }
	
  input.close();
  output.close();

  return 0;
}