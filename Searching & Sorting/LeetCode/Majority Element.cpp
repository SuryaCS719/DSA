// Method 4: Moore's Voting Algorithm - Best Approach ; O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ansIndex = 0;
        int count = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[ansIndex])
                count++;
            else
                count--;
                
            if(count == 0){
                ansIndex = i;
                count++;
            }
        }
        return nums[ansIndex];
    }
};

// Method 3: Binary search ; O(nlogn) cuz even if we use BS O(logn) we still need to sort the array
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // calculat first, last occurence of elements and then compare the counts if the count is > n/2 then return that ith element.    
    }
};

// Method 2: Using Sort ; O(nlogN)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // return nums[(0 + nums.size() - 1) / 2]; // mid ele
        // return nums[(nums.size() - 1) / 2];
        return nums[nums.size() / 2];
    }
};

// Method 1: Using BruteForce ; O(n^2) ; TLE
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int temp = n / 2;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=i; j<n; j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
            if(count > temp)
                return nums[i];
        }
        return -1;
    }
};
