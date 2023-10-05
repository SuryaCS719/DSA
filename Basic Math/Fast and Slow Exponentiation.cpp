#include <iostream>
using namespace std;

// Fast Exponentiation ; TC: O(logb)
int fastExpo(int a, int b){
  int ans = 1;
  while(b > 0){
    if(b & 1) // if b is odd
      ans = ans * a;
    a = a * a;
    b = b >> 1; // right shft ; b dividing by 2
    // b >>= 1;
  }
  return ans;
}

// Slow Exponentiation ; TC: O(b)
int slowExpo(int a, int b){
  int ans = 1;
  for(int i=0; i < b; i++)
    ans *= a;
  return ans;
}

int main() {
  cout << fastExpo(5, 4) << endl;
  cout << slowExpo(5, 4) << endl;
  return 0;
}
