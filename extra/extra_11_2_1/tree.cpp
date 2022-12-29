#include "tree.h"

Node* tree::add(Node* root,Node* temp)
{
    if(root == nullptr)
        return temp;
    else {
        if(temp->val == root->val)
        {
            std::cout << "NO DUPLICATES ALLOWED" << std::endl;
            delete temp;
            return root;
        }
        else if(temp->val < root->val) 
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
Node* tree::single_right(Node* n)
{
    Node *temp = n->left;
    n->left = temp->right;
    temp->right = n;
    n->height = std::max(height(n->left),height(n->right)) + 1;
    temp->height = std::max(height(temp->left),height(temp->right)) + 1;
    return temp;
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
Node* tree::double_right(Node* n)
{
    n->left = single_left(n->left);
    return single_right(n);
}
Node* tree::double_left(Node* n)
{
    n->right = single_right(n->right);
    return single_left(n);
}
int tree::height(Node* n)
{
    if(n == nullptr)
        return -1;
    else
        return n->height;
}
int tree::balance_factor(Node* n)
{
    return height(n->left) - height(n->right);
}
void tree::print_preorder(Node* cu)
{
    if(cu != nullptr)
    {
        std::cout << cu->val << " ";
        print_preorder(cu->left);
        print_preorder(cu->right);
    }
}
void tree::print_inorder(Node* cu)
{
    if(cu != nullptr)
    {
        print_inorder(cu->left);
        std::cout << cu->val << " ";
        print_inorder(cu->right);
    }
}
void tree::print_postorder(Node* cu)
{
    if(cu != nullptr)
    {
        print_postorder(cu->left);
        print_postorder(cu->right);
        std::cout << cu->val << " ";
    }
}
Node* tree::remove_node(Node* root,int val)
{
    if(root == nullptr)
    {
        return root;
    } 
    else if(val < root->val) 
    {
        root->left = remove_node(root->left,val);
    }
    else if(val > root->val)
    {
        root->right = remove_node(root->right,val);
    }
    else 
    {

        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if(root->left == nullptr)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else {
            Node *temp = find_min(root->right);
            root->val = temp->val;
            root->right = remove_node(root->right, temp->val);
        }
    }
    if(root == nullptr)
        return root;

    root->height = std::max(height(root->left),height(root->right)) + 1;

    if(balance_factor(root) > 1)
    {
        if(val < root->left->val)
            root = single_right(root);
        else
            root = double_right(root);
    } 
    else if(balance_factor(root) < -1)
    {
        if(val > root->right->val)
            root = single_left(root);
        else
            root = double_left(root);
    }

    return root;
}
Node* tree::find_min(Node* cu)
{
    if(cu->left == nullptr)
        return cu;
    else
        return find_min(cu->left);
}

void tree::insert(int val)
{
    root = add(root,new Node(val));
}
void tree::preorder()
{
    print_preorder(root);
    std::cout << std::endl;
}
void tree::inorder()
{
    print_inorder(root);
    std::cout << std::endl;
}
void tree::postorder()
{
    print_postorder(root);
    std::cout << std::endl;
}
void tree::level_order()
{
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()) 
    {
        int level_size = q.size();
        for(int i = 0; i < level_size; i++) {
            Node* cu = q.front();
            q.pop();
            // std::cout << cu->val << " H:(" << cu->height << ") ";
            std::cout << cu->val << " ";

            if(cu->left != nullptr)
                q.push(cu->left);
            if(cu->right != nullptr)
                q.push(cu->right);
        }
        std::cout << std::endl;
    }
}
int tree::tree_height()
{
    return root->height;
}
void tree::remove(int val)
{
    root = remove_node(root,val);
}

