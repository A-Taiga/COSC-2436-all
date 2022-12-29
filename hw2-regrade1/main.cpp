#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "ArgumentManager.h"
#include "list.h"
using namespace std;



bool read_input(string line, int& _id, string& _username, int& _score, char& _grade)
{
    line.erase(remove(line.begin(),line.end(),'\r'),line.end());
    line.erase(remove(line.begin(),line.end(),'\n'),line.end());
    line.erase(remove(line.begin(),line.end(),'['),line.end());
    line.erase(remove(line.begin(),line.end(),']'),line.end());
    int id_index = line.find("id:");
    int username_index = line.find("username:");
    int score_index = line.find("score:");
    int grade_index = line.find("grade:");
    if(id_index == -1 || username_index == -1 || score_index == -1 || grade_index == -1)
    {
        return false;
    }
    if(id_index > username_index || username_index > score_index || score_index > grade_index) {
        return false;
    }
    stringstream ss(line);
    string token;
    int start;
    
    getline(ss,token,';');
    start = token.find(':')+1;
    _id = stoi(token.substr(start));

    getline(ss,token,';');
    start = token.find(':')+1;
    _username = token.substr(start);

    getline(ss,token,';');
    start = token.find(':')+1;
    _score = stoi(token.substr(start));

    getline(ss,token,';');
    start = token.find(':')+1;
    _grade = token.substr(start)[0];

    return true;

}
void read_command(ifstream& command, list& li)
{
    string line;



    int id;
    string username;
    int score;
    char grade;

    while(getline(command,line))
    {
        line.erase(remove(line.begin(),line.end(),'\n'),line.end());
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        line.erase(remove(line.begin(),line.end(),' '),line.end());
        int start = line.find('(')+1;
        int end = line.find(')');
        if(line.find("Add") != line.npos)
        {
            
            int index = stoi(line.substr(start,end-start));
            if(read_input(line.substr(line.find('[')),id,username,score,grade))
            {
                li.add(index,id,username,score,grade);

            }
        } else if (line.find("Remove") != line.npos)
        {
            if(li.get_size() == 0)
            {
                continue;
            }
            start = line.find('(')+1;
            end = line.find(')');
            string attribute = line.substr(start,end-start);
            if(attribute.find("id:") != attribute.npos)
            {
                start = attribute.find(':')+1;
                attribute = attribute.substr(start,end-start);
                li.remove_id(stoi(attribute));
                
            } else if(attribute.find("username:") != attribute.npos)
            {
                start = attribute.find(':')+1;
                attribute = attribute.substr(start,end-start);
                li.remove_username(attribute);

            } else if(attribute.find("score:") != attribute.npos)
            {
                start = attribute.find(':')+1;
                attribute = attribute.substr(start,end-start);
                li.remove_score(stoi(attribute));

            } else if(attribute.find("grade:") != attribute.npos)
            {
                start = attribute.find(':')+1;
                attribute = attribute.substr(start,end-start);
                li.remove_grade(attribute[0]);
            }

        } else if (line.find("Sort") != line.npos)
        {
            if(li.get_size() == 0)
            {
                return;
            }
            if(line.find("id") != line.npos)
            {
                cout << "SORTING BY ID" << endl;
                li.sort_id(li.get_head(),li.get_head());
            } 
            else if (line.find("username") != line.npos)
            {
                cout << "SORTING BY USERNAME" << endl;
                li.sort_username(li.get_head(),li.get_head());
            } 
            else if (line.find("score") != line.npos)
            {
                cout << "SORTING BY SCORE" << endl;
                li.sort_score(li.get_head(),li.get_head());
            } 
            else if (line.find("grade") != line.npos)
            {
                cout << "SORTING BY GRADE" << endl;
                //li.sort_grade(li.get_head(),li.get_head());
            	li.sortGrade();
	    }
        }
    }
}

int main(int argc, char* argv[]) {


    ArgumentManager am(argc,argv);
    ifstream input(am.get("input"));
    ifstream command(am.get("command"));
    ofstream output(am.get("output"));

    // ifstream input("input7.txt");
    // ifstream command("command7.txt");
    // ofstream output("output7.txt");
    list li;

    if(input.peek() == EOF)
    {
        input.close();
        read_command(command,li);
        li.print(output);
        command.close();
        output.close();
        return 0;
    }
    
    string line;
    while(getline(input,line))
    {
        int id;
        string username;
        int score;
        char grade;

        if(read_input(line,id,username,score,grade))
        {
            li.add(id,username,score,grade);
        }
    }
    read_command(command,li);
    
    li.print(output);
    cout << li.get_size() << endl;
    command.close();
    input.close();
    output.close();

    return 0;
}
