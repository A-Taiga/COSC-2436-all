//extra_11_1_4 quadratic probing
#include <iostream>
#include <cmath>
using namespace std;



struct packet 
{
    string key;
    int val;
    packet(string _key = "", int _val = 0):key(_key),val(_val){}
};



int find(packet *table, string key,int table_size)
{
    long total = 0;
    for(int i = 0; i < key.length(); i++) {
        int power = pow(32, i-key.length());
        total += power * int(key[i]);
    }
    int index = total % table_size;
    int i = 1;
    while(table[index].key != key) {
        index += pow(i,i);
        i++;
    }
    return table[index].val;
}


void hasher(packet *table,string key, int val, int table_size)
{
    long total = 0;
    for(int i = 0; i < key.length(); i++) {
        int power = pow(32, i-key.length());
        total += power * int(key[i]);
    }
    int index = total % table_size;
    int collisions = 1;
    while(!table[index].key.empty()) {
        index += pow(collisions,collisions);
        collisions++;
    }
    table[index].key = key;
    table[index].val = val;
}

int main() {

    string names[] = {
                    "Courtney","Samir","Shyanne","Tyrese","Jaelynn",
                    "Treyton","Jacques","River","Ainsley","Wade",
                    "Dezmond","Rodolfo","Marlena","Meagan","Colt",
                    "Julien","Bobbie","Tatiyana","Tyrell","Dustyn",
                    "Nnyleaj"
                    };
    int ids[] = {
                1995, 2233, 2264, 2363, 2623, 
                2749, 3380, 3623, 3878, 4422, 
                4524, 6891, 6972, 7147, 7218, 
                7365, 7953, 8017, 9104, 9470,2954
                };
    int size = sizeof(names)/sizeof(names[0]);



    int table_size = 367;
    packet *table = new packet[table_size];

    for(int i = 0; i < size; i++) {
        hasher(table,names[i],ids[i],table_size);
    }

    for(int i = 0; i < size; i++) {
        cout << names[i] << " " <<  find(table,names[i],table_size) << endl;
    }

    return 0;
}