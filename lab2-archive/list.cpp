#include "list.h"
#include <string>
#include <algorithm>
using namespace std;

template<typename T>
list<T>::list() {
    this->head = nullptr;
}
template<typename T>	
void list<T>::push_back(T _data) {
    Node<T> *temp = new Node<T>;
    temp->data = _data;
    temp->next = nullptr;
    if(this->head == nullptr) {
        this->head = temp;
    } else {
        Node<T> *current = this->head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }
}
template<typename T>	
void list<T>::push_front(T _data) {
    Node<T> *temp = new Node<T>;
    temp->data = _data;
    temp->next = nullptr;
    if(this->head == nullptr) {
        this->head = temp;
    } else {
        temp->next = head;
        this->head = temp;
    }

}
template<typename T>	
void list<T>::remove_head() {
    if(this->head == nullptr) {
        return;
    } else if(this->head->next == nullptr) {
        this->head = nullptr;
    } else {
        Node<T> *temp = this->head->next;
        delete this->head;
        this->head = nullptr;
        this->head = temp;

    }
}
template<typename T>	
void list<T>::remove_tail() {
    
    Node<T> *prev = new Node<T>;
    Node<T> *current = this->head;
    if(current == nullptr) {
        return;
    } else if(current->next == nullptr) {
        this->head = nullptr;
    } else {
        while(current->next != nullptr) {
            prev = current;
            current = current->next;
        }
        prev->next = nullptr;
        delete current;
    }

}
template<typename T>	
void list<T>::print(std::ostream& out) {

    
    Node<T> *current = this->head;
    while(current != nullptr) {
        out << current->data << " ";
        current = current->next;
    }
    out << endl;
}

template<typename T>
list<T>::~list() {
    Node<T> *current = this->head;
    if(current != nullptr) {
        Node<T> *temp = current;
        current = current->next;
        delete temp;
    }
}