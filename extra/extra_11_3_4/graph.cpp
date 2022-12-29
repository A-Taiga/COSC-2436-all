#include "graph.h"



graph::graph(int _size)
{

    int primes[] = {
    2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,
    73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,
    157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,
    239,241,251,257,263,269,271,277,281,283,293,307,311,313,317
    };

    size = _size;
    int prime_size = sizeof(primes)/sizeof(primes[0]);
    map_size = primes[find_prime(primes,prime_size,0,(1.3 * _size))];
    last_i = 0;
    keys = new std::string[_size];
    map = new vertex*[map_size];

    
    for(int i = 0; i < map_size; i++)
        map[i] = nullptr;


}
int graph::find(std::string key)
{
    long total = 0;
    for(long i = 0; i < key.length(); i++)
    {
        int power = std::pow(32, i-key.length());
        int character = key[i] - 0;
        total += character*power;
    }
    total = total % map_size;
    int j = 0;
    int c = 2;
    while(map[total]->key != key) {
        total = (total + j * c) % map_size;
        j++;
    }
    return total;
}

int graph::hasher(std::string key) {
    long total = 0;
    for(long i = 0; i < key.length(); i++) {

        int power = pow(32,i-key.length());
        int character = key[i] - 0;
        total += character*power;
    }
    total = total % map_size;
    int j = 0;
    int c = 2;
    while(map[total] != nullptr) { //linear probing 
        total = (total + j * c) % map_size;
        j++;
    }
    return total;
}
int graph::find_prime(int arr[], int high, int low,int val) {
    int mid = low + (high-low) / 2;
    if(low <= high)
    {
        if(arr[mid] == val)
            return mid;
        else if(arr[mid] < val)
            return find_prime(arr,high,mid+1,val);
        else if(arr[mid] > val)
            return find_prime(arr,mid-1,low,val);
    } else {
        return low;
    }
    return -1;
}
void graph::add(std::string str,std::string abv)
{
    keys[last_i] = str;
    map[hasher(str)] = new vertex(str,abv,last_i);
    last_i++;



}
void graph::link(std::string src, std::string dest, int weight)
{

    vertex *src_temp = map[find(src)];
    vertex *dest_temp = map[find(dest)];

    if(src_temp->l == nullptr)
        map[find(src)]->l = new list;
    if(dest_temp->l == nullptr)
        map[find(dest)]->l = new list;




    map[find(src)]->l->insert(dest,weight,dest_temp->abv);
    map[find(dest)]->l->insert(src,weight,src_temp->abv);
    


}