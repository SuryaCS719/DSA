#include <iostream>
#include <cmath>
using namespace std;

int BinaryToDecimal(int n) {
  int decimal = 0;
  int i = 0;
  while(n > 0) {
    int lastDigit = n % 10;
    decimal = lastDigit * pow(2, i) + decimal;
    n = n / 10;
    i++;
  }
  return decimal;
}


int main() {
  int n = 1010;
  int decimal = BinaryToDecimal(n);
  cout << decimal;
  return 0;
}


/* Note: Using bitwise is not possible in binary to decimal.

instead of int lastDigit = n % 10, we can do n & 1 and it will work BUT

n = n / 10 won't be possible using bitwise.

*/
