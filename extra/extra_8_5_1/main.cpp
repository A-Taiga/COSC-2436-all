#include <iostream>
using namespace std;
void pp(int n) {
    if(n == 0) {
        return;
    } else {
        pp(n-1);
        cout << n << endl;
    }
}
int main() {
    pp(10);
    return 0;
}

