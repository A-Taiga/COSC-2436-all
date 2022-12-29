#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <ostream>
using namespace std;


struct Node {
    int id;
    string username;
    int score;
    char grade;
    Node *next;
    Node *prev;
};
class list {
private:
    Node *head;
    Node *tail;
    int size;
public:
    list();
    void add(int _id, string _username, int _score, char _grade);
    void add(int index, int _id, string _username, int _score, char _grade);
    void remove_id(int _id);
    void remove_username(string _username);
    void remove_score(int _score);
    void remove_grade(char _grade);
    void sort_id(Node *n1, Node* n2);
    void sort_username(Node *n1, Node* n2);
    void sort_score(Node *n1, Node* n2);
    void sort_grade(Node *n1, Node* n2);
    bool find_dupe(int _id, string _username, int _score, char _grade);
    void print(ostream&);
    void print_rev();
    int get_size();
    Node* get_head();
    void debug_print();
    ~list();
    void sortGrade(){
  Node* cur = head;
  int tempId =0;
  string tempUser;
  int tempScore = 0;
  char tempGrade;
      if(head == nullptr || head->next == nullptr){
        return;
      }
      else{
        bool isSorted = false;
        Node *cur;
        Node *temp = nullptr;
        while(!isSorted){
          isSorted = true;
          cur = head;
          temp = cur->next;
          while(cur->next != nullptr){
            if(cur->grade > cur->next->grade){

          tempId = cur -> id;
          cur -> id = temp -> id;
          temp -> id = tempId;

          tempUser = cur -> username;
          cur -> username = temp -> username;
          temp -> username = tempUser;

          tempScore = cur -> score;
          cur -> score = temp -> score;
          temp -> score = tempScore;

          tempGrade = cur -> grade;
          cur -> grade = temp -> grade;
          temp -> grade = tempGrade;
              isSorted = false;
            }
            cur = cur->next;
            temp = cur->next;
          }
      }
    }
  }
};

#endif
