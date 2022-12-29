#include <iostream>
#include <fstream>
#include <algorithm>
#include "ArgumentManager.h"
#include "tree.h"
using namespace std;

int main(int argc, char *argv[]) {


    ArgumentManager am(argc,argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    tree t;
    int line_count;

    if(input.peek() == EOF)
    {
        input.close();
        output.close();
        return 0;
    }
    input >> line_count;
    for(int i = 0; i < line_count; i++) 
    {
        int line;
        input >> line;
        t.insert(line);
    }
    string list = t.level_order();
    int i = list.find_last_of(' ');
    list.erase(i);
    output << list;
    input.close();
    output.close();
    return 0;
}