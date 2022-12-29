#include "list.h"

list::list() 
{
    this->head = nullptr;
}
void list::add(int _value) 
{
    Node *temp = new Node;
    temp->value = _value;
    temp->next = nullptr;
    if(this->head == nullptr) {
        this->head = temp;
    } else {
        Node *curr = this->head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
void list::print() 
{
    Node *curr = this->head;
    while(curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}
void list::sort(Node* node_i, Node *node_j) 
{
    if(node_i == nullptr) {
        return;
    } else if (node_j == nullptr) {
        return sort(node_i->next,this->head);
    } else {
        int temp_value;
        if(node_i->value < node_j->value) {
            temp_value     = node_j->value;
            node_j->value  = node_i->value;
            node_i->value  = temp_value;
        }
        return sort(node_i,node_j->next);
    }
}

Node* list::get_head() 
{
    return this->head;
}