// LeetCode: 204- Count Primes


/* Method 4: Segmented Sieve ; Variation of Sieve of Eratosthenes.
difference is that in the latter, the range = [0,n) or [0,n-1] whereAs
in the former, the range = [lowerBound, Upperbound] ; A subset of the latter.
slighty enhanced version of the latter, useful if low or high constraints given.
*/

// Method 3: Sieve of Eratosthenes ; TC: O(n * log(log n))
class Solution {
public:

    int countPrimes(int n) {

        if(n == 0) return 0;
        int count = 0;
        vector<bool> sieve(n, true);
        sieve[0] = sieve[1] = false; // 0, 1 -> non prime
        for(int i = 2; i < n; i++){
            if(sieve[i]){ // executes only if sieve[i] is true.
                count++;
                int j = 2 * i;
                while(j < n){
                    sieve[j] = false;
                    j += i;
                } 
            }
        }
        return count;
    }
};


// Method 1: Naive Approach ; O(n * n) -> O(n^2) ; TLE 
// Method 2 : Square Root Approach ; O(sqrt(n) * n) -> O(n * sqrt(n)) ; TLE 
class Solution {
public:

    bool isPrime(int n){
        if(n <= 1) return false;

        //for(int i = 2; i < n; i++){ // Method 1
        for(int i = 2; i <= sqrt(n); i++){ // Method 2
            if(n % i == 0)
                return false;
        }
        return true;
    }

    int countPrimes(int n) {
        int count = 0;
        for(int i = 0; i < n; i++){
            if(isPrime(i))
                count++;
        }
        return count;
    }
};
