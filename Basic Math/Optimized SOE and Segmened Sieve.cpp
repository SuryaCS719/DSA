// -----------------------------      Question 1 -------------------------------------------------------
// Optimized Sieve of Eratosthenes -> TC: O(n*log(logn)) still same in the worst case or upper bound
#include <iostream>
#include <vector>
using namespace std;

vector<bool> Sieve(int n){
  vector<bool> sieve(n+1, true);
  sieve[0] = sieve[1] = false;
  for(int i = 2; i*i <= n; i++){ // Optimization 2 on outer loop ; same as i <= sqrt(n)
    if(sieve[i]){
      int j = i * i; // Optimization 1 on inner loop 
      while(j <= n){
        sieve[j] = false;
        j += i;
      }
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

/* Output

2 3 5 7 11 13 17 19 23 

*/

// -----------------------------      Question 2 -------------------------------------------------------
// Segmented Sieve: 

#include <iostream>
#include <vector>
#include <cmath>
// #include <math.h>
using namespace std;


// Question: To count prime numbers->[0, n]

// Optimized Sieve of Eratosthenes -> TC: O(n*log(logn)) still same in the worst case or upper bound
vector<bool> Sieve(int n){
  vector<bool> sieve(n+1, true);
  sieve[0] = sieve[1] = false;
  for(int i = 2; i*i <= n; i++){ // Optimization 2 on outer loop ; same as i <= sqrt(n)
    if(sieve[i]){
      int j = i * i; // Optimization 1 on inner loop 
      while(j <= n){
        sieve[j] = false;
        j += i;
      }
    }
  }
  return sieve;
}

// Segmented Sieve ; TC: O((R-L)*(logR)); SC: O(sqrt(R))
vector<bool> segmentedSieve(int L, int R){
  // get a prime array so that we can use it to mark the segmented sieve
  vector<bool> sieve = Sieve(sqrt(R));
  vector<int> basePrimes; // this vector consists of prime nos that are used for marking.
  for(int i=0; i<sieve.size(); i++){
    if(sieve[i])
      basePrimes.push_back(i);
  }
  vector<bool> segSieve(R-L+1, true);
  if(L == 0 || L == 1) // base condition since 0 and 1 are not prime nos
    segSieve[L] = false;
  
  for(auto prime: basePrimes){
    int first_mul = (L / prime) * prime;
    if(first_mul < L)
      first_mul += prime;
    int j = max(first_mul, prime*prime);
    while(j <= R){
      segSieve[j - L] = false; // ex: j = 111 in reality its 1 so j - l = 111 - 1 = 1.
      j += prime;
    }
  }
  return segSieve;
}


int main() {
  int L = 110;
  int R = 130;
  vector<bool> ans = segmentedSieve(L, R);
  for(int i=0; i < ans.size(); i++){
    if(ans[i])
      cout << i + L << " ";
  }
  return 0;
}

/* Output

113 127

*/
