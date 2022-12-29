#include "list.h"

list::list()
{
    head = nullptr;
    tail = nullptr;
}
void  list::add(int _num)
{
    Node *temp = new Node;
    temp->next = nullptr;
    temp->num = _num;
    if(head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        Node *curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
        tail = temp;
    }
    
}
void list::sort(Node *node_i, Node *node_j)
{
    if(node_i == nullptr) {
        return;
    } else if (node_j == nullptr) {
        return sort(node_i->next,head);
    }else {
        int temp;
        if(node_i->num < node_j->num) {
            temp = node_j->num;
            node_j->num = node_i->num;
            node_i->num = temp;
        }
        return sort(node_i,node_j->next);
    }
}
Node* list::middle(Node* start, Node* last) 
    {
        Node *slow = start;
        Node *fast = start->next;
        while(fast != last) {
            fast = fast->next;
            if(fast != last) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }
    bool list::search(int x) {
        Node *start = head;
        Node *end = tail;
        while(start != end) {
            Node *mid = middle(start,end);
            if(x == start->num) { // best case
                return true;
            }
            if(x == end->num) { // best case
                return true;
            }
            if(x == mid->num) {
                return true;
            } else if (x > mid->num) {
                start = mid->next;
            } else {
                end = mid;
            }
        }
        return false;
    }
    bool list::recursive_search(int x, Node *start, Node *end)
    {
        if(start->num == x) { // best case
            return true;
        } else if(end->num == x) { // best case
            return true;
        } else if(start == end) { // worst case
            return false;
        } else {
            Node *mid = middle(start,end);
            if(x > mid->num) {
                return recursive_search(x,mid->next,end);
            } else {
                return recursive_search(x,start,mid);
            }
        }
    }

void  list::print()
{
    Node *curr = head;
    while(curr->next != nullptr) {
        cout << curr->num << " -> ";
        curr = curr->next;
    }
    cout << curr->num << endl;
}