#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <ostream>
struct packet {
    std::string str;
    int size;
    packet *left;
    packet *right;
    packet(std::string _str, int _size):str(_str),size(_size),left(nullptr),right(nullptr){}
};

class tree {

private:
    packet *root;
public:
    tree():root(nullptr){}
    packet* insert(packet*, packet*);
    void preorder(std::ostream&, packet*);
    void inorder(std::ostream&, packet*);
    void postorder(std::ostream&, packet*);
    packet* get_root();
};

#endif