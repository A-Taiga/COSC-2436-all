#include "tree.h"

template<class T1, class T2>
Node<T1,T2>* tree<T1,T2>::add(Node<T1,T2>* root,Node<T1,T2>* temp)
{
    if(root == nullptr)
        return temp;
    else 
    {
        if(temp->key == root->key)
        {
            std::cout << "CANNOT HAVE DUPLICATE KEYS" << std::endl;
            return temp;
        }
        else if(temp->key < root->key)
        {
            root->left = add(root->left,temp);
            if(Bf(root) > 1)
            {
                if(temp->key < root->left->key)
                    root = single_right(root);
                else
                    root = double_right(root);
            }
        }
        else if(temp->key > root->key)
        {
            root->right = add(root->right,temp);
            if(Bf(root) < -1)
            {
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
template<class T1, class T2>
Node<T1,T2>* tree<T1,T2>::deletion(Node<T1,T2>* root, T1 key)
{
    if(root == nullptr)
        return root;
    else if(key < root->key)
        root->left = deletion(root->left,key);
    else if(key > root->key)
        root->right = deletion(root->right,key);
    else
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if(root->left == nullptr)
        {
            Node<T1,T2> *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr)
        {
            Node<T1,T2> *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node<T1,T2> *temp = find_min(root->right);
            root->key = temp->key;
            root->val = temp->val;
            root->right = deletion(root->right, temp->key);
        }
    }
    if(root == nullptr)
        return root;

    root->height = std::max(height(root->right),height(root->left)) + 1;

    if(Bf(root) > 1)
    {
        if(key < root->left->key)
            root = single_right(root);
        else
            root = double_right(root);
    } 
    else if(Bf(root) < -1)
    {
        if(key > root->right->key)
            root = single_left(root);
        else
            root = double_left(root);
    }
    return root;
}
template<class T1, class T2>
Node<T1,T2>* tree<T1,T2>::single_right(Node<T1,T2>* n)
{
    Node<T1,T2> *temp = n->left;
    n->left = temp->right;
    temp->right = n;
    n->height = std::max(height(n->left),height(n->right)) + 1;
    temp->height = std::max(height(temp->left),height(temp->right)) + 1;
    return temp;
}
template<class T1, class T2>
Node<T1,T2>* tree<T1,T2>::single_left(Node<T1,T2>* n)
{
    Node<T1,T2> *temp = n->right;
    n->right = temp->left;
    temp->left = n;
    n->height = std::max(height(n->left),height(n->right)) + 1;
    temp->height = std::max(height(temp->left),height(temp->right)) + 1;
    return temp;
}
template<class T1, class T2>
Node<T1,T2>* tree<T1,T2>::double_right(Node<T1,T2>* n)
{
    n->left = single_left(n->left);
    return single_right(n);

}
template<class T1, class T2>
Node<T1,T2>* tree<T1,T2>::double_left(Node<T1,T2>* n)
{
    n->right = single_right(n->right);
    return single_left(n);
}
template<class T1, class T2>
Node<T1,T2>* tree<T1,T2>::find(Node<T1,T2>* cu, T1 key)
{
    if(cu == nullptr)
        return cu;
    if(cu->key == key)
        return cu;
    else if(key < cu->key)
        return find(cu->left, key);
    else if(key > cu->key)
        return find(cu->right, key);
    return cu;
}
template<class T1, class T2>
Node<T1,T2>* tree<T1,T2>::find_min(Node<T1,T2>* cu)
{
    if(cu->left == nullptr)
        return cu;
    else
        return find_min(cu->left);
}

template<class T1, class T2>
int tree<T1,T2>::height(Node<T1,T2>* n)
{
    if(n == nullptr)
        return -1;
    else
        return n->height;

}
template<class T1, class T2>
int tree<T1,T2>::Bf(Node<T1,T2>* n)
{
    return height(n->left) - height(n->right);
}
template<class T1, class T2>
void tree<T1,T2>::preorder_print(Node<T1,T2>* cu)
{
    if(cu != nullptr)
    {
        std::cout << cu->val << " ";
        preorder_print(cu->left);
        preorder_print(cu->right);
    }
}
template<class T1, class T2>
void tree<T1,T2>::inorder_print(Node<T1,T2>* cu)
{
    if(cu != nullptr)
    {
        inorder_print(cu->left);
        std::cout << cu->val << " ";
        inorder_print(cu->right);
    }
}
template<class T1, class T2>
void tree<T1,T2>::postorder_print(Node<T1,T2>* cu)
{
    if(cu != nullptr)
    {
        postorder_print(cu->left);
        postorder_print(cu->right);
        std::cout << cu->val << " ";
    }
}
template<class T1, class T2>
void tree<T1,T2>::insert(T1 key,T2 val)
{
    root = add(root,new Node<T1,T2>(key,val));
}
template<class T1, class T2>
T2 tree<T1,T2>::search(T1 key)
{
    // Node<T1,T2> *temp = root;
    Node<T1,T2> *check = find(root,key);

    return check == nullptr ? 0 : check->val;
}
template<class T1, class T2>
void tree<T1,T2>::remove(T1 key)
{
    root = deletion(root,key);
}
template<class T1, class T2>
void tree<T1,T2>::level_order()
{
    std::queue<Node<T1,T2>*> q;
    q.push(root);
    while(!q.empty())
    {
        int level_size = q.size();
        for(int i = 0; i < level_size; i++)
        {
            Node<T1,T2> *cu = q.front();
            q.pop();
            std::cout << cu->val << " ";
            if(cu->left != nullptr)
                q.push(cu->left);
            if(cu->right != nullptr)
                q.push(cu->right);
        }
        std::cout << std::endl;
    }
}
template<class T1, class T2>
void tree<T1,T2>::preorder()
{
    preorder_print(root);
    std::cout << std::endl;
}
template<class T1, class T2>
void tree<T1,T2>::inorder()
{
    inorder_print(root);
    std::cout << std::endl;
}
template<class T1, class T2>
void tree<T1,T2>::postorder()
{
    postorder_print(root);
    std::cout << std::endl;
}