// Lower and upper bound concept B.S. 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int startIndex = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int endIndex = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        int lastIndex = endIndex - 1;
        // also optional part: printing total occurences of the target
        int totalOccurence = lastIndex - startIndex + 1;
        cout << "total: " << totalOccurence << endl;
        
        if(startIndex < n && lastIndex < n 
            && nums[startIndex] == target && nums[lastIndex] == target)
            return {startIndex, lastIndex};
        
        return {-1, -1};
    }   
};
