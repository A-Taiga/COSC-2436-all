#include "graph.h"

void list::add(int val, int weight)
{
    Node *temp = new Node(val,weight);
    if(head == nullptr)
        head = tail = temp;
    else {
        tail->next = temp;
        tail = temp;
    }
}
Node* list::get_head()
{
    return this->head;
}

graph::graph(int _size)
{
    this->size = _size;
    this->arr = new list*[this->size];

    for(int i = 0; i < this->size; i++)
        arr[i] = new list;

}
void graph::add(int src, int dest, int weight)
{
    arr[src]->add(dest,weight);
    arr[dest]->add(src,weight);
}
void graph::print()
{

    for(int i = 0; i < size; i++)
    {
        std::cout << i << " : ";
        Node *cu = arr[i]->get_head();
        while(cu != nullptr) {
            std::cout << cu->val << " | ";
            cu = cu->next;
        }
        std::cout << std::endl;

        std::cout.width(20); 
        std::cout << std::setfill('-') << "-";
        std::cout << std::endl;
    }
}

