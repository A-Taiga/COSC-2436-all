// ADJACENCY LIST 

#include <iostream>
#include "graph.h"
using namespace std;
int main() {
    cout << "ADJACENCY LIST " << endl;
    cout << endl;
    graph g(5);

    g.add(0, 1, 1);
    g.add(0, 4, 1);
    g.add(1, 2, 1);
    g.add(1, 3, 1);
    g.add(1, 4, 1);
    g.add(2, 3, 1);
    g.add(3, 4, 1);

    g.print();

    
    return 0;
}