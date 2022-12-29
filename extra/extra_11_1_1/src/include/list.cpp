#include "list.h"

void list::push(std::string _key, int _val)
{
    Node *temp = new Node(_key,_val);
    if(empty()) {
        head = tail = temp;
    } else {
        tail->next = temp;
    }
}
bool list::pop()
{
    if(empty())
        return false;
    else {
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }
}
Node* list::front()
{   
    if(empty())
        return 0;
    else
        return head;
}
bool list::empty()
{
    if(head == nullptr) 
        return true;
    else
        return false;
}