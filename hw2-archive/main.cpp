#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <utility>
#include <cstring>
#include "list.h"

#include "ArgumentManager.h"

using namespace std;

void tokenize_credential(list* li, string line,string operation, int index = 0) {
    string tokens[4];
        istringstream ss(line);
        string token = "";
        char c;
        int i = 0;
        while(ss >> c) {
            if(c == '['){
                continue;
            } else if(c == ';' || c == ']') {
                token.erase(0,token.find(':')+1);
                tokens[i] = token;
                token = "";
                i++;
            } else {
                token+=c;
            }
        }
        stringstream id(tokens[0]);
        stringstream grade(tokens[2]);
        int g;
        int j;
        grade >> g;
        id >> j;
        if(operation == "push") {
            li->push(j,tokens[1],g,tokens[3][0]);
        } else if(operation == "add") {
            li->add(index,j,tokens[1],g,tokens[3][0]);
        }
}


int main(int argc, char* argv[]) {

    ArgumentManager am(argc,argv);
    string input = am.get("input");
    string output = am.get("output");
    string command = am.get("command");
    ifstream in(input.c_str());
    ifstream cmd(command.c_str());
    ofstream out(output.c_str());

    list *li = new list;
    // ifstream in("input1.txt");
    // ifstream cmd("command1.txt");
    // ofstream out("");
    string line;
    if(in.peek() != EOF) {
        while(getline(in,line)) {
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        line.erase(remove(line.begin(),line.end(),'\n'),line.end());

        int id_index = line.find("id:");
        int username_index = line.find("username:");
        int score_index = line.find("score:");
        int grade_index = line.find("grade:");

        if(id_index == -1 || username_index == -1 || score_index == -1 || grade_index == -1) {
            cout << "MISSING" << endl;
            continue;
        }
        if(id_index > username_index || username_index > score_index || score_index > grade_index){
            cout << "OUT OF ORDER" << " "<< line << endl;
            continue;
        }
            tokenize_credential(li,line,"push");
        }
    }
    while(getline(cmd,line)) {
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        line.erase(remove(line.begin(),line.end(),'\n'),line.end());
                



        if(line.find("Add") != line.npos) {

            int id_index = line.find("id:");
            int username_index = line.find("username:");
            int score_index = line.find("score:");
            int grade_index = line.find("grade:");

            if(id_index == -1 || username_index == -1 || score_index == -1 || grade_index == -1) {
                cout << "MISSING" << endl;
                continue;
            }
            if(id_index > username_index || username_index > score_index || score_index > grade_index){
                cout << "OUT OF ORDER" << " "<< line << endl;
                continue;
            }
            size_t start = line.find('(')+1;
            size_t end = line.find(')');
            size_t len = end-start;

            int index;
            stringstream ss(line.substr(start,len));
            ss >> index;
            tokenize_credential(li,line,"add",index);
            

        } else if (line.find("Remove") != line.npos) {
            size_t start = line.find('(')+1;
            size_t end = line.find(')');
            size_t len = end-start;
            string attribute = line.substr(start,len);
            string value = attribute.substr(attribute.find(':')+1,attribute.npos);
            if(attribute.find("id") != attribute.npos) {
                stringstream ss(value);
                int v;
                ss >> v;
                li->remove_id(v);
            } else if (attribute.find("username") != attribute.npos) {
                li->remove_username(value);
            } else if(attribute.find("score") != attribute.npos) {
                stringstream ss(value);
                int v;
                ss >> v;
                li->remove_score(v);
            } else if(attribute.find("grade") != attribute.npos) {
                li->remove_grade(value[0]);
            }
        } else if (line.find("Sort") != line.npos) {

            if(line.find("id") != line.npos) 
            {   
                cout << "SORTING BY ID" << endl;
                li->sort_id(li->get_head(),li->get_head());
                
            } else if (line.find("username") != line.npos) 
            {
                cout << "SORTING BY USERNAME" << endl;
                li->sort_username(li->get_head(),li->get_head());
            } else if (line.find("score")  != line.npos) 
            {
                cout << "SORTING BY SCORE" << endl;
                li->sort_score(li->get_head(),li->get_head());
            } else if (line.find("grade") != line.npos) 
            {
                cout << "SORTING BY GRADE" << endl;
                li->sort_grade(li->get_head(),li->get_head());
            }
        }
    }
    li->debug_print();
    li->print(out);
    delete li;
    return 0;
}