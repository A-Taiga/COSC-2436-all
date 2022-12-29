#include "tree.h"
packet* tree::insert(packet* root, packet* temp) 
{
    if(root == nullptr) {
        return temp;
    } else {
        if(temp->size == root->size)
            root->str = temp->str;
        else if(temp->size > root->size)
            root->right = insert(root->right,temp);
        else if(temp->size < root->size)
            root->left = insert(root->left,temp);
        return root;
    }
}
void tree::preorder(std::ostream& out, packet* cu)
{
    if(cu != nullptr) {
        // std::cout << cu->str << std::endl;
        out << cu->str << std::endl;
        preorder(out,cu->left);
        preorder(out,cu->right);
    }

}
void tree::inorder(std::ostream& out, packet* cu)
{
    if(cu != nullptr) {
        inorder(out,cu->left);
        // std::cout << cu->str << std::endl;
        out << cu->str << std::endl;
        inorder(out,cu->right);
    }
}
void tree::postorder(std::ostream& out, packet* cu)
{
    if(cu != nullptr) {
        postorder(out,cu->left);
        postorder(out,cu->right);
        // std::cout << cu->str << std::endl;
        out << cu->str << std::endl;

    }
}
packet* tree::get_root()
{
    return root;
}