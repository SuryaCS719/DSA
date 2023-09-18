// 3 approaches: Temp kth size array ; Modulous Formula, Reversal Algorithm

// Method-1: Using Temp kth size array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int n = nums.size();
        vector <int> temp(k);

        for(int i=n-k, j=0; i<n; i++, j++){
            temp[j] = nums[i];
        }

        for(int i=n-1; i>=k; i--){
            nums[i] = nums[i-k];
        }

        for(int i=0; i<k; i++){
            nums[i] = temp[i];
        }
    }
};


// Method-2: Using Modulus
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);

        for(int index=0; index<n; index++){
            int newIndex = (index + k) % n;
            ans[newIndex] = nums[index];
        }
        nums = ans;
    }
};

// Method-3: Reversal ALgorithm
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        // 1. reverse [0, n-1]
        reverse(nums.begin(), nums.end());
        // 2. reverse [0, k-1]
        reverse(nums.begin(), nums.begin() + k);
        // 3. reverse [k, n-1]
        reverse(nums.begin() + k , nums.end());
    }
};
