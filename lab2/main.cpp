#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <algorithm>
#include "ArgumentManager.h"
#include "list.h"
#include "list.cpp"


using namespace std;

template<typename T>
bool check_remove(list<T> *li, string line) {
    if(line.find("remove") != line.npos) {
        if(line.find("head") != line.npos) {
            li->remove_head();
            return true;
        } else if (line.find("tail") != line.npos) {
            li->remove_tail();
            return true;
        }
    }
    return false;
}
void read_int(ifstream& input, list<int> *li, string pos) {
    string line;
    while(getline(input,line)) {
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        if(check_remove(li,line)) {
            continue;
        } else {
            int num = 0;
            stringstream ss(line);
            ss >> num;
            if(pos == "head") {
                li->push_front(num);
            } else if (pos == "tail") {
                li->push_back(num);
            }
        }
    }
}
void read_string(ifstream& input, list<string> *li, string pos) {
    string line;
    while(getline(input,line)) {
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        if(check_remove(li,line)) {
            continue;
        } else {
            if(pos == "head") {
                li->push_front(line);
            } else if (pos == "tail") {
                li->push_back(line);
            }
        }
    }
}
void read_char(ifstream& input, list<char> *li, string pos) {
    string line;
    while(getline(input,line)) {
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        if(check_remove(li,line)) {
            continue;
        } else {
            char c;
            stringstream ss(line);
            ss >> c;
            if(pos == "head") {
                li->push_front(c);
            } else if (pos == "tail") {
                li->push_back(c);
            }
        }
    }
}
int main(int argc, char* argv[]) {

    ArgumentManager am(argc,argv);
    string input = am.get("input");
    string output = am.get("output");
    ifstream in(input.c_str());
    ofstream out(output.c_str());

    // ifstream in("input2.txt");
    // ofstream out("output1.txt");
    string type;
    string pos;
    in >> type;
    in >> pos;
    in.ignore();
    in.ignore();
    if(type == "int") {
        list<int> *li = new list<int>;
        read_int(in,li,pos);
        li->print(out);
    } else if(type == "string") {
        list<string> *li = new list<string>;
        read_string(in,li,pos);
        li->print(out);
    }else if(type == "char") {
        list<char> *li = new list<char>;
        read_char(in,li,pos);
        li->print(out);
    }
    return 0;
}
