// Optimized Sieve of Eratosthenes -> TC: O(n*log(logn)) still same in the worst case or upper bound
#include <iostream>
#include <vector>
using namespace std;

vector<bool> Sieve(int n){
  vector<bool> sieve(n+1, true);
  int count = 0;
  sieve[0] = sieve[1] = false;
  for(int i = 2; i*i <= n; i++){ // Optimization 2 on outer loop ; same as i <= sqrt(n)
    count++;
    int j = i * i; // Optimization 1 on inner loop 
    while(j <= n){
      sieve[j] = false;
      j += i;
    }
  }
  return sieve;
}

int main() {
  vector<bool> ans = Sieve(25);
  for(int i=0; i < ans.size(); i++){
    if(ans[i])
      cout << i << " ";
  }
  return 0;
}

// Segmented Sieve: 
