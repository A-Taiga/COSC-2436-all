#include "hash_table.h"

hash_table::hash_table(int n)
{
    size = find_prime(n,0,99);
    table = new list[size];
}
int hash_table::hasher(std::string key) 
{
    long total = 0;
    for(int i = 0; i < key.length(); i++) {
        int power = pow(32,i-key.length());
        int character = key[i] - 0;
        total += character*power;
    }
    return total % size;
}
void hash_table::add(std::string key,int val)
{
    int index = hasher(key);
    table[index].push(key,val);
}
int hash_table::find(std::string key)
{
    int index = hasher(key);
    Node *cu = table[index].front();
    while(cu->key != key) {
        cu = cu->next;
    }
    return cu->val;
}
int hash_table::find_prime(int x, int low, int high, int size) 
{   
        if(x > size)
            return primes[size-1];
        if(low > high) {
            return getClosest(primes[low-1],primes[low+1],x);
        }
        int mid = (low+high)/2;
        if(primes[mid] == x) {
            return x;
        }
        else if(x > primes[mid])
            return find_prime(x,mid+1,high);
        else if(x < primes[mid])
            return find_prime(x,low,mid-1);
    
    return 0;
}
int hash_table::getClosest(int val1, int val2,int target)
{
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}