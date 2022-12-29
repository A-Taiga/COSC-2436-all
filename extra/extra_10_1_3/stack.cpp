#include "stack.h"
using namespace myStack;
void stack::push(int _val)
{
    Node *new_node = new Node(_val);
    if(head == nullptr)
    {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    size++;
}
bool stack::pop()
{
    if(!this->empty())
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        size--;
        return true;
    }
    return false;
}
int stack::top()
{
    return head->val;
}
int stack::get_size()
{
    return size;
}
bool stack::empty()
{
    if(head == nullptr)
    {
        return true;
    } else {
        return false;
    }
}