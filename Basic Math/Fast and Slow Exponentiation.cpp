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


// GFG: Modular Exponentiation for large numbers
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    long long int ans = 1;
		    while(n > 0){
		        if(n & 1) // if n is odd
		            ans = (ans * x) % M;
		        x = (x * x) % M;
		        n >>= 1;
		    }
		    return ans; // no need to return ans % M as ans is being % by M at each iteration
		}
};
