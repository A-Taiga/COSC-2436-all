#ifndef TREE_H
#define TREE_H
#include <iostream>
struct node {
    node *left;
    int val;
    node *right;
    node(int _val):left(nullptr),val(_val),right(nullptr){}
};
class tree {
private:
    node *root;
public:
    tree():root(nullptr){}
    node* insert(node*,int);
    node* remove(node* root, int v)
    {
        if(root == nullptr)
            return root;
        if(root->val > v) {
            root->left = remove(root->left,v);
            return root;
        } else if(root->val < v) {
            root->right = remove(root->right,v);
            return root;
        } else {
            if(root->left == nullptr) {
                node *temp = root->right;
                delete root;
                return temp;
            } else if(root->right == nullptr) {
                node *temp = root->left;
                delete root;
                return temp;
            } else {
                node *succ_parent = root;
                node *succ = root->right;
                while(succ->left != nullptr) {
                    succ_parent = succ;
                    succ = succ->left;
                }
                if(succ_parent != root)
                    succ_parent->left = succ->right;
                else
                    succ_parent->right = succ->right;
                root->val = succ->val;
                delete succ;
                return root;
            }
        }
    }
    bool search(node* cu,int v)
    {
        if(cu == nullptr)
            return false;
        if(cu->val == v)
            return true;
        else if(v < cu->val)
            return search(cu->left,v);
        else if(v > cu->val)
            return search(cu->right,v);
    }
    void inordertraversal(node*);
    void preordertraversal(node *);
    void postordertraversal(node*);
    node* get_root();
    void set_root(node*);
};
#endif