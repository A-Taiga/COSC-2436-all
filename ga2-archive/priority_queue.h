#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include <iostream>
struct Node {
    std::string expression;
    double value;
    Node *next;
    Node(std::string _exp, double _value):expression(_exp),value(_value),next(nullptr){}
};
class priority_queue {
private:
    Node *head;
    int size;
public:
    priority_queue():head(nullptr),size(0){}
    bool empty() {
        if(head == nullptr)
            return true;
        else 
            return false;
    }
    void dequeue() {
        if(head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        size--;
    }
    Node* front() {
        return head;
    }
    void enqueue(std::string exp, double value) {
        Node* temp = new Node(exp,value);
        if(head == nullptr)
            head = temp;
        else {
            if(head->value > temp->value) {
                temp->next = head;
                head = temp;
            } else {
                Node *cu = head;
                Node *prev = nullptr;
                while(cu != nullptr && cu->value <= temp->value) {
                    prev = cu;
                    cu = cu->next;
                }
                prev->next = temp;
                temp->next = cu;
            }
        }
        size++;
    }
    int get_size() {
        return size;
    }
};
#endif