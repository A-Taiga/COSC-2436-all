//extra_9_3_1
//Delete every other character
///Print how many rounds it took to delete every other character in the sentence 

#include <iostream>


using namespace std;


struct Node {
    char c;
    Node *next;
};
class list {
private:
    Node *head;
    int size;
public:
    list() {
        this->head = nullptr;
        this->size = 0;
    }
    void add(string str) {
        Node *link = nullptr;
        this->size = str.length();
        for(int i = 0; i < str.length(); i++) {
            Node *temp = new Node;
            temp->c = str[i];
            temp->next = nullptr;
            if(this->head == nullptr) {
                this->head = temp;
            } else {
                Node *curr = this->head;
                while(curr->next != nullptr) {
                    curr = curr->next;
                }
                curr->next = temp;
                link = temp;
            }
        }
        link->next = this->head;
    }
    int delete_every_other() {
        Node *curr = this->head;
        Node *temp = nullptr;
        int temp_size = this->size;
        for(int i = 0; i < this->size; i++) {
            if(curr == nullptr) {return temp_size;}
            if(i%2 == 0) {
                temp = curr->next;
                delete curr;
                this->head = temp;
                temp_size--;

            }
            curr = curr->next;
        }
        return temp_size;
    }
    void print() {
        Node *curr = this->head;
        for(int i = 0; i < this->size; i++) {
            cout << curr->c;
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    string str;
    getline(cin,str);
    list li;

    li.add(str);
    li.print();
    cout << "Loops: " << li.delete_every_other() << endl;
    return 0;
}