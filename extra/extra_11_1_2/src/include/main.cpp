#include <iostream>
#include "tree.h"
using namespace std;
int main() {

    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);



    tree b;
    node* root = nullptr;
    root = b.insert(root, 50);
    root = b.insert(root, 30);
    root = b.insert(root, 20);
    root = b.insert(root, 40);
    root = b.insert(root, 70);
    root = b.insert(root, 60);
    root = b.insert(root, 80);

    
    cout << "in order: ";
    b.inordertraversal(root);
    cout << endl;
    cout << "post order: ";
    b.postordertraversal(root);
    cout << endl;
    cout << "pre order: ";
    b.preordertraversal(root);
    cout << endl;



    

    root = b.remove(root,80);
    if(b.search(root,80)) {
        cout << "FOUND" << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }




    return 0;
}