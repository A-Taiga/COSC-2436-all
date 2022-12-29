#ifndef LIST_H
#define LIST_H
#include <string>

struct Node {
    std::string key;
    std::string abv;
    int val;
    Node *next;
    Node(std::string _key = "", std::string _abv = "",int _val = -1):key(_key),abv(_abv),val(_val),next(nullptr){}
};

class list {
private:
    Node *head;
    Node *tail;
    int size;
public:
    list():head(nullptr),tail(nullptr),size(0){}
    void insert(std::string key,int val, std::string abv)
    {
        Node *temp = new Node(key,abv,val);
        if (head == nullptr)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    Node *get_head()
    {
        return head;
    }
};

#endif