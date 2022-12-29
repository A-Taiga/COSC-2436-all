#include "priority_queue.h"
void priority_queue::enqueue(std::string _job, double _time)
{
    Node *temp = new Node;
    temp->job = _job;
    temp->time = _time;
    temp->next = nullptr;

    if(front == nullptr)
        front = temp;
    else {
        Node *cu = front;
        Node *prev = nullptr;
        if(temp->time < front->time) {
            temp->next = front;
            front = temp;
        } else {
            while(cu != nullptr && temp->time >= cu->time) 
            {
                prev = cu;
                cu = cu->next;
            }
            prev->next = temp;
            temp->next = cu;
        }
    }
    
}
bool priority_queue::dequeue()
{
    if(empty())
        return false;
    else {
        Node *temp = front;
        front = front->next;
        delete temp;
        return true;
    }
}
Node* priority_queue::peek() {
    return front;
}
bool priority_queue::empty()
{
    if(front == nullptr)
        return true;
    else
        return false;
}