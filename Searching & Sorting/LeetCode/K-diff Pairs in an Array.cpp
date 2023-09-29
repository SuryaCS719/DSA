// Method 3: Binary Search : O(n logN)

class Solution {
public:
    
    int binarySearch(vector<int>& nums, int start, int x){
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == x){
                return mid;
            }
            else if(x > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;

        for(int i = 0; i < nums.size(); i++){

            // a[i]
            // search -> a[i] + k in the right subarray

            if(binarySearch(nums, i+1, nums[i] + k) != -1)
                ans.insert({nums[i], nums[i] + k});
        }
        return ans.size();
    }
};


// Method 2: Two pointer 
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int i = 0;
//         int j = 1;
//         set <pair<int, int>> ans;

//         while(j < nums.size()){
//             int diff = nums[j] - nums[i];
//             if(diff == k /*&& i != j*/){
//                 ans.insert({nums[i], nums[j]});
//                 i++, j++;
//             }
//             else if(diff > k)
//                 i++;
//             // else if(diff < k)
//             else
//                 j++;
//             // instead of && above:
//             // if(i == j) 
//             //     j++;
//         }
//         return ans.size();
//     }
// };


// Method 1: BruteForce
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         set<pair<int, int>> count;
//         for(int i = 0; i < nums.size(); i++){
//             for(int j = i+1; j < nums.size(); j++){
//                 if(abs(nums[i] - nums[j]) == k){
//                     count.insert({nums[i], nums[j]});
//                 }
//             }
//         }
//         return count.size();
//     }
// };
