// extra_11_1_5 double hashing
#include <iostream>
#include <cmath>
using namespace std;

struct packet 
{
    string key;
    int val;
    packet(string _key = "", int _val = 0):key(_key),val(_val){}
};

int find(packet *table, string key, int table_size) {
    long h1 = 0;
    int index;
    int prime = 11;
    for(int i = 0; i < key.length(); i++) {
        long power = pow(32,i-key.length());
        h1 += int(key[i]) * power;
    }
    int i = 1;
    if(table[h1%table_size].key != key) {
        int h2 = prime - ((h1%table_size) % prime);
        index = (h1 + i * h2) % table_size;
        i++;
        while(table[index].key != key) {
            index = (h1 + i * h2) % table_size;
            i++;
        }
    } else {
        index = h1 % table_size;
    }
    return table[index].val;

}

void hasher(packet *table, string key, int val, int table_size) {
    long h1 = 0;
    int prime = 11;
    int index;
    int collisions = 1;
    int h2;
    for(int i = 0 ; i < key.length(); i++) {
        long power = pow(32,i-key.length());
        h1 += int(key[i]) * power;
    }
    if(!table[h1%table_size].key.empty()) {

        h2 = prime - ((h1%table_size) % prime);
        index = (h1 + collisions * h2) % table_size;
        collisions++;
        while(!table[index].key.empty()) {
            index = (h1 + collisions * h2) % table_size;
            collisions++;
        }
    } else {

        index = h1 % table_size;
    }
    table[index].key = key;
    table[index].val = val;
}


int main() {
    string names[] = {
                    "Clark","Citlali","Karissa","Markel","Jericho",
                    "Zavier","Tatiana","Savana","Tristin","Geneva",
                    "Cielo","Mackenzie","Unique","Uriel","Amia",
                    "Khalid","Aya","Aislinn","Kevon","Donte"
                    };
    int ids[] = {
                1995, 2233, 2264, 2363, 2623, 
                2749, 3380, 3623, 3878, 4422, 
                4524, 6891, 6972, 7147, 7218, 
                7365, 7953, 8017, 9104, 9470,
                };
    int size = sizeof(names)/sizeof(names[0]);
    int table_size = 367;   
    packet *table = new packet[table_size];

    for(int i = 0; i < size; i++) {
        hasher(table,names[i],ids[i],table_size);
    }


    for(int i = 0 ; i < size; i++) {
        cout << names[i] << " " << find(table,names[i],table_size) << endl;
    }
    return 0;
}