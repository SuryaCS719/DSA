// Correct solution but will get TLE as this is supposed to be solved using DP.
// Pattern: Exploring all possible ways
// TC: O(3^n) ; as we have 3 recursive calls
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        if(n == 0)
            return 0;
        if(n < 0)
            return INT_MIN;
        
        int ans1 = 1 + maximizeTheCuts(n-x, x, y, z);
        int ans2 = 1 + maximizeTheCuts(n-y, x, y, z);
        int ans3 = 1 + maximizeTheCuts(n-z, x, y, z);
        return max(ans1, max(ans2, ans3));
    }
};
