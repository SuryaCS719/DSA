// Will get TLE as this is supposed to be solved using DP
class Solution {
public:

    int solve(vector<int>& nums, int size, int i){
        if(i >= size)
            return 0;
        int ans1 = nums[i] + solve(nums, size, i+2);
        int ans2 = 0 + solve(nums, size, i+1);
        return max(ans1, ans2);
    }

    int rob(vector<int>& nums) {
        // int ans = solve(nums, nums.size(), 0);
        // return ans;
        return solve(nums, nums.size(), 0);
    }
};
