// correct logic ; but throws TLE

class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) // n = 0 ; 1 way to reach by jumping in the same position
            return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// given -> 1<= n <= 45 ; neednt include base case where n = 0
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};


// iterative approach - same as fibonacci logic:
class Solution {
public:
    int climbStairs(int n) {
        int term1 = 0;
        int term2 = 1;
        int term3;
        for(int i=0; i<n; i++){
            term3 = term1 + term2;
            term1 = term2;
            term2 = term3;
        }
        return term3;
    }
};
