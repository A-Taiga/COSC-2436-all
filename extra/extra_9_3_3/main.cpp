/// merge and sort two sorted list into a new sorted list
//workshop 9/13/22

#include <iostream>
#include "list.h"
using namespace std;


Node* merge_and_sort(Node *head_1, Node *head_2) {
    Node *temp = new Node;
    Node *curr = temp;
    while(head_1 != nullptr && head_2 != nullptr) {
        if(head_1->value < head_2->value) {
            curr->next = head_1;
            head_1 = head_1->next;
        } else {
            curr->next = head_2;
            head_2 = head_2->next;
        }
        curr = curr->next;
    }

    if(head_1 != nullptr) { 
        curr->next = head_1;
        head_1 = head_1->next;
    }
    if(head_2 != nullptr) {
        curr->next = head_2;
        head_2 = head_2->next;
        cout << "TESTING HEAD 2  ";
    }
    return temp->next;
}
int main() {

    list li1;
    list li2;
    
    for(int i = 0; i < 20; i++) {
        li1.add(rand()%100);
    }
    
    for(int i = 0; i < 2; i++) {
        li2.add(rand()%100);
    }
    li1.sort(li1.get_head(),li1.get_head());
    li2.sort(li2.get_head(),li2.get_head());
    cout << "li1: ";
    li1.print();
    cout << "li2: ";
    li2.print();
    Node *temp = merge_and_sort(li1.get_head(),li2.get_head());
    
    cout << "Sorted list: ";
    while(temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}