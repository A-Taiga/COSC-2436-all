#include "graph.h"


graph::graph(int _size)
{
    this->size = _size;
    matrix = new int*[this->size];

    for(int i = 0; i < this->size; i++)
        matrix[i] = new int[this->size];
    
    for(int i = 0; i < this->size; i++)
        for(int j = 0; j < this->size; j++)
            matrix[i][j] = 0;
    
    

}
void graph::add(int src, int dest, int weight)
{
    matrix[src][dest] = weight;
    matrix[dest][src] = weight;
}
void graph::print()
{
    std::cout << "    ";
    for(int i = 0; i < size; i++)
        std::cout << i << " ";
    
    std::cout << std::endl;

    for(int i = 0; i < size; i++)
    {
        std::cout <<  i << " : ";
        for(int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

}