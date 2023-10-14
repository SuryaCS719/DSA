// getting TLE as this is supposed to be solved via DP
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0)
            return 0;
        if(amount < 0)
            return -1;
        
        int ans = INT_MAX;

        for(int i=0; i < coins.size(); i++){
            int subproblem = coinChange(coins, amount - coins[i]);
            // if(subproblem == -1) continue;
            if(subproblem != -1)
                ans = min(ans, 1 + subproblem);
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
