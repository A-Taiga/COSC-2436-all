#include "list.h"
list::list()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
void list::add(int _id, string _username, int _score, char _grade)
{
    Node *temp = new Node;
    temp->id = _id;
    temp->username = _username;
    temp->score = _score;
    temp->grade = _grade;
    temp->prev = nullptr;
    temp->next = nullptr;
    if(find_dupe(_id,_username,_score,_grade))
    {
        return;
    }
    if(head == nullptr)
    {
        head = temp;
    } else {
        Node *cu = head;
        while(cu->next != nullptr)
        {
            cu = cu->next;
        }
            cu->next = temp;
            temp->prev = cu;
            tail = temp;
    }
    cout << "ADDED: ";
    cout <<"[id:"<<_id<<";username:"<<_username<<";score:"<<_score<<";grade:"<<_grade<<"]"<< endl;
    size++;
}
void list::add(int index, int _id, string _username, int _score, char _grade)
{
    if(index > size) {
        
        cout << "INDEX TOO LARGE" << endl;
        return;
    }
    if(find_dupe(_id,_username,_score,_grade)){return;}
    Node *cu = head;
    Node *temp = new Node;
    temp->id = _id;
    temp->username = _username;
    temp->score = _score;
    temp->grade = _grade;
    temp->prev = nullptr;
    temp->next = nullptr;
    if(index == 0)
    {
        if(head == nullptr)
        {
            head = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
            // temp->prev = head;
            // temp->next = head->next;
            // head->next->prev = temp;
            // head->next = temp;
        }
        size++;
    } else if (index == size)
    {
        while(cu->next != nullptr)
        {
            cu = cu->next;
        }
        cu->next = temp;
        tail = temp;
        size++;
    } else {
        int i = 0;
        while(cu->next != nullptr)
        {
            if(i == index-1)
            {
                break;
            }
            cu = cu->next;
            i++;
        }
        temp->prev = cu;
        temp->next = cu->next;
        cu->next->prev = temp;
        cu->next = temp;
        size++;
    }
}
void list::remove_id(int _id)
{

    Node *temp = nullptr;
    Node *cu = head;
    while(cu != nullptr)
    {
        if(cu->id == _id)
        {
            if(cu == head)
            {
                if(cu->next == nullptr)
                {
                    delete head;
                    head = nullptr;
                    size--;
                    return;
                } else {
                    temp = cu->next;
                    temp->prev = nullptr;
                    head = temp;
                    delete cu;
                    cu = temp;
                }   
            } else if (cu == tail)
            {
                temp = cu->prev;
                temp->next = nullptr;
                tail = temp;
                delete cu;
                cu = nullptr;
                size--;
                return;
            } else {
                temp = cu->next;
                cu->prev->next = temp;
                temp->prev = cu->prev;
                delete cu;
                cu = nullptr;
                cu = temp;
            }
            size--;
        } else {
            cu = cu->next;
        }
    }
    // Node *temp = nullptr;
    // Node *cu = head;
    // while(cu != nullptr)
    // {
    //     if(cu->id == _id)
    //     {
    //         cout << "REMOVING BY ID: ";
    //         cout << "[id:" << cu->id << ";" <<
    //             "username:" << cu->username << ";" << 
    //             "score:" << cu->score << ";" << 
    //             "grade:" << cu->grade << "]" << endl;   
    //         if(cu == head)
    //         {
    //             if(head->next == nullptr)
    //             {
    //                 delete head;
    //                 head = nullptr;
    //                 size --;
    //                 return;
    //             } else {
    //                 head = cu->next;
    //                 head->prev = nullptr;
    //                 delete cu;
    //                 cu = head;
    //             }
    //         } else {
    //             temp = cu->next;
    //             temp->prev = cu->prev;
    //             cu->prev->next = temp;
    //             delete cu;
    //             cu = temp;
    //         }   
    //         size--;
    //     } else {
    //         cu = cu->next;
    //     }
    // }
}
void list::remove_username(string _username)
{
Node *temp = nullptr;
    Node *cu = head;
    while(cu != nullptr)
    {
        if(cu->username == _username)
        {
            cout << "REMOVING BY USERNAME: ";
            cout << "[id:" << cu->id << ";" <<
                "username:" << cu->username << ";" << 
                "score:" << cu->score << ";" << 
                "grade:" << cu->grade << "]" << endl;   
            if(cu == head)
            {
                head = cu->next;
                head->prev = nullptr;
                delete cu;
                cu = head;
            } else if (cu == tail) {
                tail = cu->prev;
                tail->next = nullptr;
                delete cu;
                cu = nullptr;
            } else {
                temp = cu->next;
                temp->prev = cu->prev;
                cu->prev->next = temp;
                delete cu;
                cu = temp;
            }
            size--;
        } else {
            cu = cu->next;
        }
    }
}
void list::remove_score(int _score)
{
Node *temp = nullptr;
    Node *cu = head;
    while(cu != nullptr)
    {
        if(cu->score == _score)
        {
            cout << "REMOVING BY SCORE: ";
            cout << "[id:" << cu->id << ";" <<
                "username:" << cu->username << ";" << 
                "score:" << cu->score << ";" << 
                "grade:" << cu->grade << "]" << endl;   
            if(cu == head)
            {
                head = cu->next;
                head->prev = nullptr;
                delete cu;
                cu = head;
            } else if (cu == tail) {
                tail = cu->prev;
                tail->next = nullptr;
                delete cu;
                cu = nullptr;
            } else {
                temp = cu->next;
                temp->prev = cu->prev;
                cu->prev->next = temp;
                delete cu;
                cu = temp;
            }
            size--;
        } else {
            cu = cu->next;
        }
    }

}
void list::remove_grade(char _grade)
{
Node *temp = nullptr;
    Node *cu = head;
    while(cu != nullptr)
    {
        if(cu->grade == _grade)
        {
            cout << "REMOVING BY GRADE: ";
            cout << "[id:" << cu->id << ";" <<
                "username:" << cu->username << ";" << 
                "score:" << cu->score << ";" << 
                "grade:" << cu->grade << "]" << endl;   
            if(cu == head)
            {
                head = cu->next;
                head->prev = nullptr;
                delete cu;
                cu = head;
            } else if (cu == tail) {
                tail = cu->prev;
                tail->next = nullptr;
                delete cu;
                cu = nullptr;
            } else {
                temp = cu->next;
                temp->prev = cu->prev;
                cu->prev->next = temp;
                delete cu;
                cu = temp;
            }
            size--;
        } else {
            cu = cu->next;
        }
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
    if(node_i == nullptr)
    {
        return;
    } else if(node_j == nullptr) 
    {
        return sort_grade(node_i->next,head);
    } 
    else if (node_j->grade == node_i->grade)
    {
        cout << "SAME GRADE" << endl;
        return sort_grade(node_i,node_j->next);
    } 
    else if(node_i == node_j) 
    {
        return sort_grade(node_i,node_j->next);
    } 
    else 
    {
        if(node_i->grade < node_j->grade)
        {
            int temp_id          = node_i->id;
            string temp_username = node_i->username;
            int temp_score       = node_i->score;
            char temp_grade      = node_i->grade;

            node_i->id       = node_j->id;
            node_i->username = node_j->username;
            node_i->score    = node_j->score;
            node_i->grade    = node_j->grade;

            node_j->id       = temp_id;
            node_j->username = temp_username;
            node_j->score    = temp_score;
            node_j->grade    = temp_grade;
        }
        return sort_grade(node_i,node_j->next);
    }
}
bool list::find_dupe(int _id, string _username, int _score, char _grade)
{
    Node *cu = head;
    while(cu != nullptr)
    {
        if(cu->id != _id && cu->username ==_username)
        {
            cout << "FOUND SAME USERNAME: " << _username << endl;
            return true;
        }
        if(cu->id == _id)
        {   
            cout << "FOUND DUPE OF: " << _id << endl;
            cu->username = _username;
            cu->score = _score;
            cu->grade = _grade;
            return true;
        }
        cu = cu->next;
    }
    return false;
}
void list::print(ostream& out)
{
    Node *cu = head;
    while(cu != nullptr)
    {
        out << "[id:" << cu->id << ";" <<
                "username:" << cu->username << ";" << 
                "score:" << cu->score << ";" << 
                "grade:" << cu->grade << "]" << endl;
        cu = cu->next;
    }
}
void list::print_rev()
{
   
    Node *cu = tail;
    while(cu != nullptr)
    {
    cout << "[id:" << cu->id << ";" <<
            "username:" << cu->username << ";" << 
            "score:" << cu->score << ";" << 
            "grade:" << cu->grade << "]" << endl;
        cu = cu->prev;
    }
}
int list::get_size()
{
    return this->size;
}
Node* list::get_head()
{
    return this->head;
}
void list::debug_print()
{
    Node *cu = head;
    while(cu != nullptr)
    {
        cout <<"[id:"<<cu->id<<";username:"<<cu->username<<";score:"<<cu->score<<";grade:"<<cu->grade<<"]"<< endl;
        cu = cu->next;
    }
}
list::~list()
{
    Node *cu = head;
    Node *temp = nullptr;
    while(cu != nullptr)
    {  
        temp = cu->next;
        delete cu;
        cu = temp;
    }
    delete temp;
    delete cu;
}
