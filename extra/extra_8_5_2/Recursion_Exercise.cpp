#include <iostream>
using namespace std;

// Function To Convert Decimal Number into a Binary
// Your Code Begins Here
void DEC_TO_BIN(int bit, int num) {
  
  
  if (num == 0) {
    if(bit < 0) {
      cout << 0;
    } else {
      for(int i = 0; i < bit; i++) {
        cout << 0;
      }
    }
    return;
  } else {
    DEC_TO_BIN(bit-1, num/2);
    cout << num % 2;
  }
}
// Your Code Ends Here

int main() {
  // DON'T MAKE ANY CHANGES TO THIS SECTION

  cout << "Conversion of 12 to Binary with Padding 2: \n";
  DEC_TO_BIN(2, 12);
  cout << "\nConversion of 12 to Binary with Padding 4: \n";
  DEC_TO_BIN(4, 12);
  cout << "\nConversion of 12 to Binary with Padding 12: \n";
  DEC_TO_BIN(12, 12);
  cout << "\nConversion of 12 to Binary with Padding 32: \n";
  DEC_TO_BIN(32, 12);
  cout << "\nConversion of 45 to Binary with Padding 7: \n";
  DEC_TO_BIN(7, 45);
  cout << "\nConversion of 91 to Binary with Padding 3: \n";
  DEC_TO_BIN(3, 91);
  cout << "\nConversion of 11 to Binary with Padding 7: \n";
  DEC_TO_BIN(7, 11);

  return 0;
}