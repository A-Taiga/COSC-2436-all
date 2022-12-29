#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "ArgumentManager.h"
#include "graph.h"
using namespace std;

int main(int argc, char *argv[]) {

    ArgumentManager am(argc,argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));
    // ifstream input("input1.txt");

    int size;
    input >> size;
    string path;
    input.ignore();
    input.ignore();
    getline(input,path);

    graph g(size);

    string line;
    while(getline(input,line))
    {
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        line.erase(remove(line.begin(),line.end(),'\n'),line.end());

        int i,j;
        istringstream ss(line);
        ss >> i;
        ss >> j;
        g.insert(i,j);

    }

    // g.print();
    istringstream ss(path);
    int start;
    int end;
    ss >> start;
    ss >> end;
    if(g.BFS(start,end))
        output << "true";
    else
        output << "false";

    input.close();
    output.close();
    return 0;
}