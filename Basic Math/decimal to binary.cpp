#include <iostream>
#include <cmath>
using namespace std;

int decimalToBinaryUsingDivison(int n) {
  int binaryNumber = 0;
  int i = 0; // to increase powers
  while(n > 0) {
    int remainder = n % 2;
    binaryNumber = remainder * pow(10, i) + binaryNumber;
    n = n / 2;
    i++;
  }
  return binaryNumber;
}


int decimalToBinaryUsingBitwise(int n) {
  int binaryNumber = 0;
  int i = 0;
  while(n > 0) {
    int remainder = n & 1;
    binaryNumber = remainder * pow(10, i) + binaryNumber;
    n = n >> 1;
    i++;
  }
  return binaryNumber;
}

int main() {
  int n = 10;
  // int binary = decimalToBinaryUsingDivison(n);
  int binary = decimalToBinaryUsingBitwise(n);
  cout << binary;
  return 0;
}
