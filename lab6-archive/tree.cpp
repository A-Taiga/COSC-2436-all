#include "tree.h"

Node* tree::add(Node* root, Node* temp)
{
    if(root == nullptr)
    {
        return temp;
    }
    else 
    {
        if(temp->val < root->val)
        {
            root->left = add(root->left,temp);
            if(balance_factor(root) > 1)
            {
                if(temp->val < root->left->val)
                    root = single_right(root);
                else
                    root = double_right(root);
            }
        }
        else if(temp->val > root->val)
        {
            root->right = add(root->right,temp);
            if(balance_factor(root) < -1)
            {
                if(temp->val > root->right->val)
                    root = single_left(root);
                else
                    root = double_left(root);
            }
        }
        root->height = std::max(height(root->left),height(root->right)) + 1;
        return root;
    }
}
Node* tree::single_left(Node* n)
{
    Node* temp = n->right;
    n->right = temp->left;
    temp->left = n;
    n->height = std::max(height(n->left),height(n->right)) + 1;
    temp->height = std::max(height(temp->left),height(temp->right)) + 1;
    return temp;

}
Node* tree::single_right(Node* n)
{
    Node *temp = n->left;
    n->left = temp->right;
    temp->right = n;
    n->height = std::max(height(n->left),height(n->right)) + 1;
    temp->height = std::max(height(temp->left),height(temp->right)) + 1;
    return temp;
}
Node* tree::double_left(Node* n)
{   
    n->right = single_right(n->right);
    return single_left(n);
}
Node* tree::double_right(Node* n)
{
    n->left = single_left(n->left);
    return single_right(n);
}
int tree::balance_factor(Node* n)
{
    return height(n->left) - height(n->right);
}
int tree::height(Node* n)
{
    if(n == nullptr)
        return -1;
    else
        return n->height;
}
void tree::insert(int val)
{
    root = add(root,new Node(val));
}
std::string tree::level_order()
{
    std::string list = "";
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int level_size = q.size();
        for(int i = 0; i < level_size; i++) 
        {
            Node *cu = q.front();
            q.pop();
            list += std::to_string(cu->val) + " ";
            if(cu->left != nullptr)
                q.push(cu->left);
            if(cu->right != nullptr)
                q.push(cu->right);
        }
    }
    return list;
}