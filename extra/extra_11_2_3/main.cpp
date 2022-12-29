//extra_11_2_3 read keys and values into an AVL tree
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "tree.cpp"

using namespace std;

int main() {
    srand(time(NULL));
    ifstream input("input.txt");
    tree<string,int> t;
    string line;
    while(getline(input,line))
    {
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        line.erase(remove(line.begin(),line.end(),'\n'),line.end());
        if(line.empty())
            continue;
        istringstream ss(line);
        string name;
        string id;
        getline(ss,name,',');
        getline(ss,id,',');
        t.insert(name,stoi(id));
    }


    cout << "READ KEYS AND VALUES INTO A BST TREE" << endl;
    cout << "INLCUDES SEARCH AND REMOVE FUNCTIONS" << endl;

    t.level_order();
    cout << endl;
    t.preorder();
    cout << endl;
    t.inorder();
    cout << endl;
    t.postorder();











    



    return 0;
}