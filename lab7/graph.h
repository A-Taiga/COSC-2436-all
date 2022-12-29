#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <queue>

class graph {
private:
    int size;
    int **matrix;
public:
    graph(int);
    void insert(int, int);
    bool BFS(int,int);
    void print();
    ~graph();
};
#endif