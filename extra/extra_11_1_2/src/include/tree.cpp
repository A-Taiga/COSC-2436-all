#include "tree.h"
#include <iostream>
using namespace std;

void tree::postordertraversal(node *cu) 
{
    if(cu != nullptr) {
        postordertraversal(cu->left);
        postordertraversal(cu->right);
        cout << cu->val << " ";
    }
}
void tree::inordertraversal(node *cu) 
{
    if(cu != nullptr) {
        
        inordertraversal(cu->left);
        cout << cu->val << " ";
        inordertraversal(cu->right);
    }
}
void tree::preordertraversal(node *cu) 
{
    if(cu != nullptr) {
        cout << cu->val << " ";
        preordertraversal(cu->left);
        preordertraversal(cu->right);
    }
}
node* tree::insert(node* root, int val) 
{
    if(root == nullptr)
        this->root = new node(val);
    if(!root) {
        return new node(val);
    } else {
        if(val > root->val)
            root->right = insert(root->right,val);
        else if(val < root->val)
            root->left = insert(root->left,val);
        
        return root;
    }
}

node* tree::get_root()
{
    return root;
}
void tree::set_root(node* node)
{
    root = node;
}

