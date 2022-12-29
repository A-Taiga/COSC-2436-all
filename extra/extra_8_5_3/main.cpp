#include <iostream>
using namespace std;


struct pearl {
    int color;
    pearl *hole;

};

class necklace {

private:
    pearl* head;
    pearl* tail;
public:
    necklace() {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void addpearl(int c) {
        pearl *p = new pearl;
        p->color = c;
        p->hole = nullptr;
        if(this->head == nullptr) {
            this->head = p;
            this->tail = p;
        } else {
            this->tail->hole = p;
            this->tail = p;
        }
    }
    void print() {
        pearl *temp = this->head;
        while(temp != nullptr) {
            cout << temp->color << endl;
            temp = temp->hole;
        }
    }
};
int main() {

    necklace mine;
    mine.addpearl(1);
    mine.addpearl(2);
    mine.addpearl(3);
    mine.addpearl(4);
    mine.addpearl(5);
    mine.print();
    return 0;
}