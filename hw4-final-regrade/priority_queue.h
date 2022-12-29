#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include <iostream>


struct Node {
    std::string command;
    std::string info;
    int priority;

    Node *next;
    Node *prev;
    Node(std::string _command = "", std::string _info = "", int _priority = 0):command(_command),info(_info),priority(_priority),next(nullptr),prev(nullptr){}

};

namespace myQ {

    class priority_queue {

    private:
        Node *head;
        Node *tail;
    public:
        priority_queue():head(nullptr),tail(nullptr){}
        void enqueue(Node*);
        bool dequeue();
        Node* front();
        bool empty();
        Node* get_tail();
        void set_tail(Node*);


    };
}



#endif