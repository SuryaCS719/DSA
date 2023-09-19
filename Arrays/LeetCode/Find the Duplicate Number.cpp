// Method 1: using sort() ; TC O(nlogn) ; SC O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // iterating till n - 1 only because at last i index there will be no i + 1 (out of bounds)
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1])
                return nums[i];
        }
        return -1;
    }
};

// Method 2: Negative Marking Method ; TC O(n) ; SC O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Negative Marking Method // Modifies array
        // visited solution
        int index = - 1;
        for(int i=0; i < nums.size(); i++){
            int index = abs(nums[i]);
            // Checking if the index is already visited
            if(nums[index] < 0)
                return index;
            // Marking indices visited
            nums[index] *= -1;
        }
        return index;
    }
};

// Method 3: Positioning Method ; TC O(n) ; SC O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Positioning Method // Modifies array
        // TC: O(n) SC: O(1)
        while(nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};
