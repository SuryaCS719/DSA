// 3 approaches: Temp kth size array ; Modulous Formula, Reversal Algorithm ; Single rotate K times

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
        // if n = 5 and k = 6 then it then the o/p will be equal to that of k = 1. if n and k have same values that is no of rotations = length of array then the original array is the answer i.e k = 0.
        k = k % nums.size();
        // 1. reverse [0, n-1]
        reverse(nums.begin(), nums.end());
        // 2. reverse [0, k-1]
        reverse(nums.begin(), nums.begin() + k);
        // 3. reverse [k, n-1]
        reverse(nums.begin() + k , nums.end());
    }
};

// Method 3: Reverse Algorithm using our own reverse function
class Solution {
public:
    void reverseVector(vector<int>& nums, int start, int end){
      while(start <= end){
        swap(nums[start], nums[end]);
        start++; 
        end--;
      }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % nums.size();
        // cannot pass nums.begin() in reverse()
        reverseVector(nums, 0, n - 1);
        reverseVector(nums, 0, k - 1);
        reverseVector(nums, k, n - 1);
    }
};
