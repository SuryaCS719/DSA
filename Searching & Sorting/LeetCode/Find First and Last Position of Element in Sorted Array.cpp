// Lower and upper bound concept B.S. 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int startIndex = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int endIndex = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if(startIndex < n && endIndex - 1 < n 
            && nums[startIndex] == target && nums[endIndex - 1] == target)
            return {startIndex, endIndex - 1};
        
        return {-1, -1};
    }   
};
