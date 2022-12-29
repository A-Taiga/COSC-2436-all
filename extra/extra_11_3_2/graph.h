#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>


class graph {
private:
    int size;
    int **matrix;
public:
    graph(int _size);
    void add(int src, int dest, int weight);
    void print();
};



#endif