#include "priority_queue.h"
using namespace myQ;
void  priority_queue::enqueue(Node *node)
{
    // Node *node = new Node(com,info,priority);
    if(empty())
        head = tail = node;
    else {
        if(node->priority < head->priority) {
            node->next = head;
            head->prev = node;
            head = node;
        } else {
            Node *cu = head;
            while(cu != nullptr && node->priority >= cu->priority) {
                cu = cu->next;
            }
            if(cu == nullptr) {
                tail->next = node;
                node->prev = tail;
                tail = node;
            } else {
                cu->prev->next = node;
                node->prev = cu->prev;
                node->next = cu;
                cu->prev = node;
            }
        }
    }
}
bool  priority_queue::dequeue()
{
    if(empty())
        return false;
    else {
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        return true;
    }

}
Node* priority_queue::front()
{
    if(empty())
        return new Node("NULL","NULL",-1);
    else {
        return head;
    }
}
bool  priority_queue::empty()
{ 
    if(head == nullptr)
        return true;
    else
        return false;

}
Node* priority_queue::get_tail() 
{
    return tail;
}
void priority_queue::set_tail(Node* temp)
{
    tail = temp;
}