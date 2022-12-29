#include "queue.h"

void queue::enqueue(int _val)
{
    Node *temp = new Node(_val);
    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}
bool queue::dequeue()
{
    if(head == nullptr)
    {
        std::cout << "queue empty" << std::endl;
        return false;
    } else {
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        return true;
    }
}
int queue::front()
{
    return head->val;
}
int queue::back()
{
    return tail->val;
}
bool queue::empty()
{
    if(head == nullptr)
    {
        return true;
    } else {
        return false;
    }
}