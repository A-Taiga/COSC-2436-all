#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "ArgumentManager.h"
#include <cctype>

using namespace std;


int main(int argc, char *argv[]) {

    ArgumentManager am(argc,argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    // ifstream input("input1.txt");
    // ofstream output("output.txt");
    map<string,int> map;
    
    string line;
    while(getline(input,line)) {
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        line.erase(remove(line.begin(),line.end(),'\n'),line.end());
        if(line.empty())
            continue;
        for(int i = 0 ; i < line.length(); i++) {
            line[i] = tolower(line[i]);
        }

        istringstream ss(line);
        string c = "";
        while(ss >> c) {
        string result = "";

            for(int i = 0; i < c.length(); i++) {
                if(ispunct(c[i])) {
                    if(c[i] == '\'')
                        result+=c[i];
                    else 
                        continue;
                } else {
                    result+=c[i];
                }
            }
            if(map.find(result) == map.end()) {
                map.insert(make_pair(result,1));
            } else {
                map[result]+=1;
            }
        }
    }
    for(auto& t : map) {
            // cout << t.first << " : " << t.second << endl;
            output << t.first << " : " << t.second << endl;
    }
    input.close();
    output.close();
    return 0;
}