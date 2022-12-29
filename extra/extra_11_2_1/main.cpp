// extra_11_2_1
// AVL tree
#include <iostream>
#include "tree.h"
using namespace std;
int main() {

    tree t;
    
    t.insert(5);
    t.insert(3);
    t.insert(15);
    t.insert(11);
    t.insert(20);
    t.insert(39);
    t.insert(50);
    t.insert(29);
    t.insert(1);
    t.insert(2);
    t.insert(45);
    t.insert(44);

    cout << "TREE HEIGHT: " << t.tree_height() << endl;
    cout << endl;

    cout << "PRE ORDER" << endl;
    t.preorder();
    cout << endl;
    cout << "INORDER" << endl;
    t.inorder();
    cout << endl;
    cout << "POST ORDER" << endl;
    t.postorder();
    cout << endl;
    cout << "LEVEL ORDER" << endl;
    t.level_order();


    cout << endl;
    cout << endl;
    cout << "========================================" << endl;

    cout << "REMOVING" << " [20, 39, 50, 29]" << endl;
    t.remove(20);
    t.remove(39);
    t.remove(50);
    t.remove(29);
    cout << endl;
    cout << endl;


    cout << "TREE HEIGHT: " << t.tree_height() << endl;
    cout << endl;

    cout << "PRE ORDER" << endl;
    t.preorder();
    cout << endl;
    cout << "INORDER" << endl;
    t.inorder();
    cout << endl;
    cout << "POST ORDER" << endl;
    t.postorder();
    cout << endl;
    cout << "LEVEL ORDER" << endl;
    t.level_order();

    return 0;
}
