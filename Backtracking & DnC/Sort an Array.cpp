/* Merge Sort
Approaches (3): 1. Heap memory alloc & dealloc; 2. Using a temp array to copy elements 3. In-place merge sort
*/

// This is second approach - using a temp array. 

class Solution {
public:

    void merge(vector<int>& nums, vector<int>& temp, int start, int end, int mid) {
        int i = start, j = mid + 1;
        int k = start;
        while(i <= mid && j <= end) {
            if(nums[i] < nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while(i <= mid)
            temp[k++] = nums[i++];
        while(j <= end)
            temp[k++] = nums[j++];

        while(start <= end) {
            nums[start] = temp[start];
            start++;
        }
    }

    void mergeSort(vector<int>& nums, vector<int>& temp, int start, int end) {
        if(start >= end) return;
        int mid = start + (end - start) / 2;
        mergeSort(nums, temp, start, mid);
        mergeSort(nums, temp, mid + 1, end);
        merge(nums, temp, start, end, mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        mergeSort(nums, temp, 0, nums.size() - 1);
        return nums;
    }
};



// This is third approach - In-place merge sort



