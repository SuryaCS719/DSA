/* 
Given a Rotated Sorted array.
Step 1: We find pivot element ; Pivot Element: Maximum value element in the array
Step 2: Segregate the array in two parts; part1 [0, pivotIndex] ; part 2 [pivotIndex + 1, n - 1]
Step 3: Handle the case of arr[mid] > arr[mid+1] and arr[mid-1] > arr[mid]
Step 4: Handle special case; Incase if array has single element only then start == end return start
Step 5: Apply Binary Search on both the parts.
*/
class Solution {
public:

    int findPivotIndex(vector<int>& nums){
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            //Special case
            if(s == e)
                return s;
            
            if(mid+1 < n && nums[mid] > nums[mid+1])
                return mid;

            else if(mid-1 >=0 && nums[mid-1] > nums[mid])
                return mid-1;
            
            // Part 2
            else if(nums[s] > nums[mid])
                e = mid - 1;
            // Part 1
            else
                s = mid + 1;
        }
        return -1;
    }

    int binarySearch(vector<int>& nums, int s, int e, int target){
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid])
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivotIndex(nums);

        int n = nums.size();
        int ans = -1;

        // Search in Part 1
        if(target >= nums[0] && target <= nums[pivotIndex]){
            ans = binarySearch(nums, 0, pivotIndex, target);
        }
        // else if(target >= nums[pivotIndex + 1] && target <= nums[n - 1])
        // we use else tho; common sense++
        else{
            ans = binarySearch(nums, pivotIndex + 1, n - 1, target);
        }

        return ans;
    }
};
