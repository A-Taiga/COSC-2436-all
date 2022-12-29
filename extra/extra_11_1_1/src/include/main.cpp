//extra_11_1_6 open chaining 
#include <iostream>
#include "hash_table.h"
using namespace std;

int main() {


    string keys[] = {
                "Christiana Unger","Rayne Carman","Annalee Keck",
                "Areli Stoddard","Melia Hollingsworth","ecirtaeB","Shelby Corral",
                "Melany Franz","Keith Story","Jaret Mejia","Yahaira Dobbs","Beatrice"
                };
    int ids[] = {1234,3456,8678,4345,9678,2238,2045,3904,8489,9999,6842,9012};
    int size = sizeof(keys)/sizeof(keys[0]);
    hash_table table(50);
    for(int i = 0; i < size; i++) { // add to table
        table.add(keys[i],ids[i]);
    }
    for(int i = 0 ;i < size; i++) {
        table.print(keys[i]);
    }
    // for(int i = 0; i < size; i++) { // print from table
    //     cout << table.find(keys[i]) << endl;
    // }
    return 0;
}