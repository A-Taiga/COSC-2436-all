#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <iostream>
#include <algorithm>
using namespace std;

int get_priority(string line)
{
    string split = line.substr(line.find('('));
    split.erase(remove(split.begin(),split.end(),'('),split.end());
    split.erase(remove(split.begin(),split.end(),')'),split.end());
    return stoi(split);

}
string replace(string code, string info) {
    char first = info[0];
    char second = info[2];
    string result = "";
    for(int i = 0; i < code.length(); i++) {
        if(code[i] == first)
            result+=second;
        else
            result+=code[i];
    }
    return result;
}
string add(string code, string info) {
    string result = "";
    for(int i = 0; i < code.length(); i++) {
        if(code[i] == info[0]) {
            result += code[i];
            result += info[2];
        } else {
            result+=code[i];
        }
    }
    return result;
}
string remove(string code, string info) {
    code.erase(remove(code.begin(),code.end(),info[0]),code.end());
    return code;
}
string swap(string code, string info) {
    string result = "";
    for(int i = 0; i < code.length(); i++) {
        if(code[i] == info[0]) {
            result += info[2];
        } else if(code[i] == info[2]) {
            result += info[0];
        } else {
            result += code[i];
        }
    }
    return result;
}
#endif