// 2 pointer TC: O(N) ; SC: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0, i = 1;
        while(i < nums.size()){
            if(nums[j] == nums[i]) i++;
            else nums[++j] = nums[i++]; // j++ -> nums[j] = nums[i] -> i++
        }
        return j+1; // 0 based to 1 based indexing
    }
};
