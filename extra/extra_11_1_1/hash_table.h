#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>
#include "list.h"
#include <cmath>

class hash_table {
private:
    list *table;
    int size;
    int primes[100] = {
                    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
                    73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 
                    157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 
                    239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 
                    331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 
                    421, 431, 433, 439, 443, 449, 457, 461,463, 467, 479, 487, 491, 499, 503, 
                    509, 521, 523, 541
                    };
    int getClosest(int val1, int val2,int target);
    int find_prime(int x,int high,int low, int size = 100);
public:
    hash_table(int);
    void add(std::string, int);
    int hasher(std::string);
    int find(std::string);
    void print(std::string key) {
            std::cout << hasher(key) << std::endl;
    }

};
#endif