#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include "tree.h"
#include "ArgumentManager.h"


using namespace std;

int main(int argc, char *argv[]) {

    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ifstream command(am.get("command"));
    ofstream output(am.get("output"));
    // ifstream input("input2.txt");
    // ifstream command("command2.txt");
    // ofstream output("output.txt");





    int degree = 0;
    vector<int> levels;
    string line;
    while(getline(command,line)) {
        if(line.find("Degree=") != line.npos)
        {
            for(int i = 0 ; i < line.length(); i++)
                if(isdigit(line[i]))
                {   
                    degree = stoi(line.substr(i));
                    break;
                }
        }
        else if(line.find("Level") != line.npos) {
            for(int i = 0 ; i < line.length(); i++)
                if(isdigit(line[i]))
                {   
                    levels.push_back(stoi(line.substr(i)));
                    break;
                }
        }
    }
    tree t(degree);
    string val;
    map<int,int> m;
    while(input >> val)
    {
        val.erase(remove(val.begin(),val.end(),'\r'),val.end());
        val.erase(remove(val.begin(),val.end(),'\n'),val.end());
        if(!m.count(stoi(val))) 
        {
            t.insert(stoi(val));
            m[stoi(val)] = 1;
        }
    }

    int height = t.height();
    output << "Height=" << height << endl;
    for(int i = 0; i < levels.size(); i++)
    {
        if(levels[i] > height)
            output << "Empty" << endl;
        else
        {
            t.print_level(levels[i],output);
            output << endl;
        }
    }

    input.close();
    output.close();
    command.close();
    return 0;
}