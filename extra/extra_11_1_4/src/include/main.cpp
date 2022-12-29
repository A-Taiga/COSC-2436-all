//extra_11_1_3 linear probing
#include<iostream>
#include<math.h>
#include <string>
using namespace std;

struct packet {
    string key;
    int data;
    packet():key(""),data(-1){}
};

int find(packet table[],string key, int table_size) {
    long total = 0;
    for(long i = 0; i < key.length(); i++) {

        int power = pow(32,i-key.length());
        int character = key[i] - 0;
        total += character*power;
    }
    total = total % table_size;
    int j = 0;
    int c = 2; // constant to prevent clustering 
    while(table[total].key != key) { // linear probe search 
        total = (total + j * c) % table_size;
        j++;
    }
    return total % table_size;
}

int hasher(packet table[],string key,int table_size) {
    long total = 0;
    for(long i = 0; i < key.length(); i++) {

        int power = pow(32,i-key.length());
        int character = key[i] - 0;
        total += character*power;
    }
    total = total % table_size;
    int j = 0;
    int c = 2;
    while(table[total].data != -1) { //linear probing 
        total = (total + j * c) % table_size;
        j++;
    }
    return total % table_size;
}
int main() {

    string names[] = {"abcdefghijklmnopqrstuvwxyz","Beatrice","Leland","Yoyo","Jaida","Rosalie","Jaylon","Vicente","Tierra","Virginia","ecirtaeB"};
    int id[] = {1234,4123,5511,7567,1245,4562,8425,2953,3046,9945,9999};

    int size = sizeof(names)/sizeof(names[0]);

    int hash_size = 167;
    packet hash_table[hash_size];


    for(int i = 0; i < size; i++) {
        int index = hasher(hash_table,names[i],hash_size);
        hash_table[index].key = names[i];
        hash_table[index].data = id[i];
    }

    for(int i = 0; i < size; i++) {
        int index = find(hash_table,names[i],hash_size);
        cout << names[i] << " " << hash_table[index].data << endl;
    }
    return 0;
}