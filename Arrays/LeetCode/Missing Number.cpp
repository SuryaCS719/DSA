// Method 3 XOR ; TC: O(n) SC: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int i=0; i<n; i++){
            ans ^= nums[i];
        }

        for(int i=0; i<=n; i++){
            ans ^= i;
        }
        return ans;
    }
};

// Method 2 Arithmetic Progression AP formula: 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        int totalSum = (n*(1+n))/2;
        int ans = totalSum - sum;
        return ans;
    }
};

// Method 1 Sort ; TC: O(nlogn) SC: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i == nums[i])
                continue;
            else
                return i;
        }
        return n;
    }
};
