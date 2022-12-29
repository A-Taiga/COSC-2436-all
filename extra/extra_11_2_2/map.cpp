#include "map.h"
template<class T>
Node<T>* map<T>::add(Node<T>* root,Node<T>* temp)
{
    if(root == nullptr)
        return temp;
    else {
        if(temp->key == root->key) {
            root->frequency += 1;
            delete temp;
            return root;
        } else if(temp->key < root->key)
        {
            root->left = add(root->left,temp);
            if(balance_factor(root) > 1) {
                if(temp->key < root->left->key)
                    root = single_right(root);
                else
                    root = double_right(root);
            }
        }
        else if(temp->key > root->key) 
        {
            root->right = add(root->right,temp);
            if(balance_factor(root) < -1) {
                if(temp->key > root->right->key) 
                    root = single_left(root);
                else
                    root = double_left(root);
            }
        }
        root->height = std::max(height(root->left),height(root->right)) + 1;
        return root;
    }
}
template<class T>
Node<T>* map<T>::single_right(Node<T>* n)
{
    Node<T>* temp = n->left;
    n->left = temp->right;
    temp->right = n;
    n->height = std::max(height(n->left),height(n->right)) + 1;
    temp->height = std::max(height(temp->left),height(temp->right)) + 1;
    return temp;
}
template<class T>
Node<T>* map<T>::single_left(Node<T>* n)
{
    Node<T>* temp = n->right;
    n->right = temp->left;
    temp->left = n;
    n->height = std::max(height(n->left),height(n->right)) + 1;
    temp->height = std::max(height(temp->left),height(temp->right)) + 1;
    return temp;
}
template<class T>
Node<T>* map<T>::double_right(Node<T>* n)
{ 
    n->left = single_left(n->left);
    return single_right(n);
}
template<class T>
Node<T>* map<T>::double_left(Node<T>* n)
{
    n->right = single_right(n->right);
    return single_left(n);
}
template<class T>
int map<T>::balance_factor(Node<T>* n)
{
    return height(n->left) - height(n->right);
}
template<class T>
int map<T>::height(Node<T>* n)
{
    if(n == nullptr)
        return -1;
    else
        return n->height;
}
template<class T>
void map<T>::print_inorder(Node<T>* cu)
{
    if(cu != nullptr)
    {
        print_inorder(cu->left);
        std::cout << cu->key << " : " << cu->frequency << std::endl;
        print_inorder(cu->right);
    }
}
template<class T>
int map<T>::get_node_count(Node<T>* cu)
{
    if(cu == nullptr)
        return 0;
    else {
        int freq_count = cu->frequency;
        return freq_count + get_node_count(cu->left) + get_node_count(cu->right);

    }
}
template<class T>
void map<T>::insert(T key)
{
    root = add(root, new Node<T>(key));
}
template<class T>
void map<T>::print()
{   
    print_inorder(root);
}
template<class T>
void map<T>::level_order()
{
    std::queue<Node<T>*> q;
    q.push(root);
    while(!q.empty()) {
        int level_size = q.size();
        for(int i = 0; i < level_size; i++){ 
            Node<T>* cu = q.front();
            q.pop();
            std::cout << "[" << cu->key << " F:(" << cu->frequency << ") H:(" << cu->height << ")" << "] ";
            if(cu->left != nullptr)
                q.push(cu->left);
            if(cu->right != nullptr)
                q.push(cu->right);
        }
        std::cout << std::endl;
    }
}
template<class T>
int map<T>::get_size()
{
    return size;
}
template<class T>
int map<T>::get_height()
{
    return root->height;
}
template<class T>
int map<T>::element_count()
{
    return get_node_count(root);
}


