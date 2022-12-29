#include <iostream>
#include <fstream>
#include <algorithm>
#include "priority_queue.h"
#include "ArgumentManager.h"
using namespace std;
int main(int argc,char* argv[])
{
    ArgumentManager am(argc,argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));
    // ifstream input("input1.txt");

    priority_queue pq;
    string line;
    while(getline(input,line)) {
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        line.erase(remove(line.begin(),line.end(),'\n'),line.end());
        int split = line.find_last_of(' ');
        pq.enqueue(line.substr(0,split),stod(line.substr(split)));
    }
    while(!pq.empty()) {
        //cout << pq.peek()->job << " " << pq.peek()->time << endl;
        output << pq.peek()->job << endl;
        
        pq.dequeue();
    }
    
    return 0;
}