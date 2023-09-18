// Question: Key Pair -> GFG

class Solution{
public:	
	// Method 1: Brute force approach
	bool twoSum(int arr[], int n, int x){
	    for(int i=0; i<n; i++){
	        for(int j=i+1; j<n; j++){
	            if(arr[i]+arr[j] == x)
	                return true;
	        }
	    }
	    return false;
	}
	
  // Method 2: 2 pointer 
	bool twoSum(int arr[], int n, int x){
	    int low = 0;
	    int high = n - 1;
	    while(low < high){
	        int currSum = arr[low] + arr[high];
	        
	        if(currSum == x)
	            return true;
	       else if(currSum > x)
	            high--;
	       else if(currSum < x)
	            low++;
	    }
	    return false;
	}

	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    sort(arr, arr + n);
	    bool ans = twoSum(arr, n, x);
	    return ans;
	}
};

// Note: Even after using 2 pointer, TC: O(nlogN) + O(N) = O(nlogN) ; SC: O(N) due to the sort function.

// Question: Two Sum

// Method 1: TC: O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        // vector<int> ans;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]+nums[j] == target){
                    return {i, j};
                    // ans.push_back(i);
                    // ans.push_back(j);
                }
            }
        }
        return {};
        // return ans;
    }
};

// Method 2: Need an approach to solve it in less than O(n^2)





// And by the way: 
/* This wont work because when you sort the array the indices change.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sortedArr = nums;
        vector<int> ans;
        sort(sortedArr.begin(), sortedArr.end());

        int n = sortedArr.size();
        int l = 0;
        int h = n - 1;

        while(l < h){
            int currSum = sortedArr[l] + sortedArr[h];
            if(currSum == target){
                ans.push_back(l);
                ans.push_back(h);
                return ans;
            }
            else if(currSum > target) h--;
            else if(currSum < target) l++;
        }
        return ans;
    }
};
*/
