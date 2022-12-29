#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <ostream>
#include <algorithm>



//id, username, score, and grade.


struct Node {
    int id;
    std::string username;
    int score;
    char grade;
    Node *next;
};

class list {

private: 
    Node *head;
    int size;
    bool find_duplicate(int,std::string,int,char);

public:
    list();
    Node* create_node(int,std::string,int,char);
    Node* create_node(int,std::string,int,char,Node*);
    void push(int,std::string,int,char); 
    void add(int,int,std::string,int,char);

    void remove_username(std::string _username);
    void remove_id(int _id);
    void remove_score(int _score);
    void remove_grade(char _grade);

//     Sort (attribute)
// ▪ Sort the linked list base on the given attribute (placed inside parenthesis).
// ▪ Sort ascending for id.
// ▪ Sort alphabetically for username and grade.
// ▪ Sort descending for score.
// ▪ When sorting if two values are similar, don’t swap their position.
    void sort_id(Node*,Node*);
    void sort_username(Node*,Node*);
    void sort_score(Node*,Node*);
    void sort_grade(Node*,Node*);
    Node* search(Node* _node);
    void print(std::ostream&);
    void debug_print();
    Node* get_head();
    ~list();
};

#endif 