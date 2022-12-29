/*
Program that reverses a number
*/

#include <iostream>
using namespace std;

void reverse_int(long n,long p, long r) {
    if(n==0) {
        cout << r << endl;
        return;
    } // base case
    p = n%10;
    r = r*10+p;
    n /= 10;
    reverse_int(n,p,r);
}
int main(int argc, char* argv[]) {
    
    reverse_int(stol(argv[1]),0,0);
    return 0;
}
