#include "graph.h"

graph::graph(int _size)
{
    this->size = _size;
    matrix = new int*[this->size];
    for(int i = 0; i < this->size; i++)
        matrix[i] = new int[size];

    for(int i = 0; i < this->size; i++)
        for(int j = 0; j < this->size; j++)
            matrix[i][j] = 0;
}
void graph::insert(int i, int j)
{
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}
bool graph::BFS(int source, int destinatiion)
{
    std::queue<int> q;
    bool *visited = new bool[size];
    for(int i = 0; i < size; i++)
        visited[i] = false;
    q.push(source);
    int v;
    while(!q.empty()) {
        v = q.front();
        q.pop();
        if(!visited[v]) {
            if(v == destinatiion)
                return true;
            visited[v] = true;
        }
        for(int i = 0; i < size; i++) {
            if(matrix[v][i] != 0 && !visited[i]) {
                q.push(i);
            }
        }
    }
    delete[] visited;
    return false;
}
void graph::print()
{
    std::cout << "  ";
    for(int i = 0; i < size; i++)
        std::cout << i << " ";
    std::cout << std::endl;
    for(int i = 0; i < size; i++) {
        std::cout << i << "|";
        for(int j = 0; j < size; j++) {
            if(matrix[i][j] == 1)
                std::cout << matrix[i][j] << " ";
            else 
                std::cout << "_ ";
        }
        std::cout << std::endl;
    }
}
graph::~graph()
{
    for(int i = 0; i < size; i++)
            delete[] matrix[i];
    delete[] matrix;
}