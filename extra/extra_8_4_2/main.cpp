/*
Question from data structures workshop 
Write a function that takes two arrays with random inters and calculate
the euclidian distance between the arrays recursivly and return the results
*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


void distance(const int& size, const int x[], const int y[], int i, int j) {
    if(i==size) {
        return;
    } else if(j == size) {
        cout << endl;
        distance(size,x,y,i+1,0);
    } else {
        int dx = pow(x[j]-x[i],2);
        int dy = pow(y[j]-y[i],2);
        double d = sqrt(dx+dy);
        cout << setprecision(2) << fixed;
        cout << "Distance between p:" << i+1 << " & p:" << j+1 << " " << d << " || ";
        distance(size,x,y,i,j+1);
    }
}

int main() {
    const int SIZE = 3;
    int x[] = {1,6,8};
    int y[] = {5,2,7};
    
    distance(SIZE,x,y,0,0);
    
    return 0;
}