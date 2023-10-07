/* Given two numbers L and R (inclusive) find the product of primes within this range. Print the product modulo 109+7. If there are no primes in that range you must print 1.
Example 1:
Input: L = 1, R = 10
Output: 210
Explaination: The prime numbers are 
2, 3, 5 and 7.

Example 2:
Input: L = 1, R = 20
Output: 9699690
Explaination: The primes are 2, 3, 
5, 7, 11, 13, 17 and 19.

Expected Time Complexity: O((R-L)*(logR))
Expected Auxiliary Space: O(sqrt(R))

Constraints:
1 ≤ L ≤ R ≤ 109
0 ≤ L - R ≤ 106  
*/

class Solution{
public:
    
    vector<bool> Sieve(int n){
        vector<bool> primes(n+1, true);
        primes[0] = primes[1] = false;
        for(int i=2; i*i<=n; i++){
            if(primes[i]){
                int j = i*i;
                while(j<=n){
                    primes[j] = false;
                    j += i;
                }
            }
        }
        return primes;
    }

    long long primeProduct(long long L, long long R){
        vector<bool> sieve = Sieve(sqrt(R));
        vector<int> basePrimes;
        for(int i=0; i<sieve.size(); i++){
            if(sieve[i])
                basePrimes.push_back(i);
        }
        
        vector<bool> segmentedSieve(R-L+1, true);
        if(L == 0 || L == 1)
            segmentedSieve[L] = false;
    
        for(auto prime: basePrimes){
            int firstMultiple = (L / prime) * prime;
            if(firstMultiple < L)
                firstMultiple += prime;
            int j = max(firstMultiple, prime*prime);
            while(j <= R){
                segmentedSieve[j - L] = false;
                j += prime;
            }
        }
        
        vector<int> ans;
        for(int i=0; i<segmentedSieve.size();i++){
            if(segmentedSieve[i])
                ans.push_back(i + L);
        }   
        
        for(auto i: ans)
            cout << i << " ";
        cout << endl;

        long long prod = accumulate(ans.begin(), ans.end(), 1, multiplies<long long>());
        return prod;
    }
};

