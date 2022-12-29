#include <iostream>
#include "list.h"
using namespace std;

int main() {

    list li;

    li.add(10);
    li.add(2);
    li.add(4);
    li.add(32);
    li.add(55);
    li.add(52);
    li.add(421);
    li.add(123);


    li.sort(li.get_head(),li.get_head());
    li.print();
    cout << li.search(421) << endl;
    cout << li.recursive_search(123,li.get_head(),li.get_tail()) << endl;
    


    return 0;
}