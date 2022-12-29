#include "list.h"
list::list() 
{
    this->head = nullptr;
    this->size = 0;
}
Node* list::create_node(int _id, std::string _username, int _score, char _grade) 
{
    Node *temp = new Node;
    temp->id = _id;
    temp->username = _username;
    temp->score = _score;
    temp->grade = _grade;
    temp->next = nullptr;
    return temp;
}
Node* list::create_node(int _id, std::string _username, int _score, char _grade, Node* _next) 
{
    Node *temp = new Node;
    temp->id = _id;
    temp->username = _username;
    temp->score = _score;
    temp->grade = _grade;
    temp->next = _next;
    return temp;
}
void list::push(int _id, std::string _username, int _score, char _grade)
{
    if(this->head == nullptr) {
        this->head = create_node(_id,_username,_score,_grade);
        this->size += 1;
    } else {
        Node *current = this->head;
        while(current->next != nullptr) {
            if(current->next->id == _id) {
                std::cout << "DUPLICATE FOUND REPLACING{" << current->next->username << "}" << "WITH" << "{" << _username << "}" << std::endl;
                current->next->username = _username;
                current->next->score    = _score;
                current->next->grade    = _grade;
                return;
            } else if (current->next->username == _username) {
                std::cout << "DUPLICATE FOUND {" << _username << "}" << std::endl;
                return;
            }
            current = current->next;
        }
        current = this->head; //// maybe remove this
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = create_node(_id,_username,_score,_grade);
        this->size+=1;
    }
}
void list::add(int _index, int _id, std::string _username, int _score, char _grade) 
{ 

    Node *current = this->head;
    if (_index > this->size || _index < 0) {return;}
    else if (_index == 0) 
    {
        if(this->head == nullptr) 
        {
            this->head = create_node(_id,_username,_score,_grade);
        }
        else 
        {
            if(this->find_duplicate(_id,_username,_score,_grade)) {return;}
            this->head->next = create_node(_id,_username,_score,_grade,this->head->next);
        }
    } 
    else if (_index == this->size) 
    {
        if(this->find_duplicate(_id,_username,_score,_grade)) {return;}
        current = this->head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = create_node(_id,_username,_score,_grade);
    } 
    else
    {
        if(this->find_duplicate(_id,_username,_score,_grade)) {return;}
        current = this->head;
        int i = 0;
        while(current->next != nullptr) {
            if(i == _index-1) {
                break;
            }
            current = current->next;
            i++;
        }
        current->next = create_node(_id,_username,_score,_grade,current->next);
    }
    this->size++;
}
void list::remove_username(std::string _username) 
{
    Node* prev = new Node;
    Node* current = this->head;
    while(current != nullptr) {
        if(current->username == _username) {
            std::cout << "REMOVED BY USERNAME {" << current->username << "}" << std::endl;
            prev->next = current->next;
            delete current;
            this->size-=1;
        }
        prev = current;
        current = current->next;
    }
}
void list::remove_id(int _id) 
{
    Node* prev = new Node;
    Node* current = this->head;
    while(current != nullptr) {
        if(current->id == _id) {
            std::cout << "REMOVED BY ID {" << current->username << "}" << std::endl;
            prev->next = current->next;
            delete current;
            this->size-=1;
        }
        prev = current;
        current = current->next;
    }
}
void list::remove_score(int _score) 
{
    Node* prev = new Node;
    Node* current = this->head;
    while(current != nullptr) {
        if(current->score == _score) {
            std::cout << "REMOVED BY SCORE {" << current->username << "}" << std::endl;
            prev->next = current->next;
            delete current;
            this->size-=1;
        }
        prev = current;
        current = current->next;
    }
    
}
void list::remove_grade(char _grade) 
{
    Node* prev = new Node;
    Node* current = this->head;
    while(current != nullptr) {
        if(current->grade == _grade) {
            std::cout << "REMOVED BY GRADE {" << current->username << "}" << std::endl;
            prev->next = current->next;
            delete current;
            this->size -= 1;
        }
        prev = current;
        current = current->next;
    }
    
}
void list::sort_id(Node *node_i, Node *node_j) 
{
    if(node_i == nullptr) {
        return;
    } else if (node_j == nullptr) {
        return sort_id(node_i->next,this->head);
    } else {
        int temp_id;
        std::string temp_username;
        int temp_score;
        char temp_grade;
        if(node_i->id < node_j->id) {
            temp_id         = node_j->id;
            temp_username   = node_j->username;
            temp_score      = node_j->score;
            temp_grade      = node_j->grade;

            node_j->id       = node_i->id;
            node_j->username = node_i->username;
            node_j->score    = node_i->score;
            node_j->grade    = node_i->grade;

            node_i->id       = temp_id;
            node_i->username = temp_username;
            node_i->score    = temp_score;
            node_i->grade    = temp_grade;
        }
        return sort_id(node_i,node_j->next);
    }
}
void list::sort_username(Node *node_i, Node *node_j)
{
    if(node_i == nullptr) {
        return;
    } else if (node_j == nullptr) {
        return sort_username(node_i->next,this->head);
    } else {
        int temp_id;
        std::string temp_username;
        int temp_score;
        char temp_grade;
        if(node_i->username < node_j->username) {
            temp_id         = node_j->id;
            temp_username   = node_j->username;
            temp_score      = node_j->score;
            temp_grade      = node_j->grade;

            node_j->id       = node_i->id;
            node_j->username = node_i->username;
            node_j->score    = node_i->score;
            node_j->grade    = node_i->grade;

            node_i->id       = temp_id;
            node_i->username = temp_username;
            node_i->score    = temp_score;
            node_i->grade    = temp_grade;
        }
        return sort_username(node_i,node_j->next);
    }
}
void list::sort_score(Node *node_i,Node *node_j)
{
    if(node_i == nullptr) {
        return;
    } else if (node_j == nullptr) {
        return sort_score(node_i->next,this->head);
    } else {
        int temp_id;
        std::string temp_username;
        int temp_score;
        char temp_grade;
        if(node_i->score > node_j->score) {
            temp_id         = node_j->id;
            temp_username   = node_j->username;
            temp_score      = node_j->score;
            temp_grade      = node_j->grade;

            node_j->id       = node_i->id;
            node_j->username = node_i->username;
            node_j->score    = node_i->score;
            node_j->grade    = node_i->grade;

            node_i->id       = temp_id;
            node_i->username = temp_username;
            node_i->score    = temp_score;
            node_i->grade    = temp_grade;
        }
        return sort_score(node_i,node_j->next);
    }
}
void list::sort_grade(Node *node_i,Node *node_j) 
{
    if(node_i == nullptr) {
        return;
    } else if (node_j == nullptr) {
        return sort_grade(node_i->next,this->head);
    } else {
        int temp_id;
        std::string temp_username;
        int temp_score;
        char temp_grade;
        if(node_i->grade < node_j->grade) {
            temp_id         = node_j->id;
            temp_username   = node_j->username;
            temp_score      = node_j->score;
            temp_grade      = node_j->grade;

            node_j->id       = node_i->id;
            node_j->username = node_i->username;
            node_j->score    = node_i->score;
            node_j->grade    = node_i->grade;

            node_i->id       = temp_id;
            node_i->username = temp_username;
            node_i->score    = temp_score;
            node_i->grade    = temp_grade;
        }
        return sort_score(node_i,node_j->next);
    }
}
bool list::find_duplicate(int _id,std::string _username, int _score, char _grade) 
{
    if(this->head->id == _id) {
            std::cout << "DUPLICATE FOUND REPLACING{" << this->head->username << "}" << "WITH" << "{" << _username << "}" << std::endl;
            this->head->username = _username;
            this->head->score    = _score;
            this->head->grade    = _grade;
            return true;
        } else if (this->head->username == _username) {
            std::cout << "DUPLICATE FOUND {" << _username << "}" << std::endl;
            return true;
        }
        Node *current = this->head;
        while(current->next != nullptr) {
        if(current->next->id == _id) {
            std::cout << "DUPLICATE FOUND REPLACING{" << current->next->username << "}" << "WITH" << "{" << _username << "}" << std::endl;
            current->next->username = _username;
            current->next->score    = _score;
            current->next->grade    = _grade;
            return true;
        } else if (current->next->username == _username) {
            std::cout << "DUPLICATE FOUND {" << _username << "}" << std::endl;
            return true;
        }
        current = current->next;
    }
    return false;
}
void list::print(std::ostream& out) 
{
    Node *current = this->head;
    while(current != nullptr) {
        out << "[id:"<<current->id<<";"
            << "username:"<<current->username<<";" 
            << "score:"<< current->score<<";" 
            << "grade:"<<current->grade<<"]"<<std::endl;
        current = current->next;
    }
}
void list::debug_print()
{ 
    Node *current = this->head;
    while(current != nullptr) {
        std::cout << "[id:"<<current->id<<";"
            << "username:"<<current->username<<";" 
            << "score:"<< current->score<<";" 
            << "grade:"<<current->grade<<"]"<<std::endl;
        current = current->next;
    }
    std::cout << "SIZE " << this->size << std::endl;
}
Node* list::get_head() {
    return this->head;
}
list::~list() 
{
    std::cout << "DESTRUCTOR" << std::endl;
    Node *current = this->head;
    while(current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}