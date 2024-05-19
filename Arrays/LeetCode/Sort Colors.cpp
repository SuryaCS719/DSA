// Method 3
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        int low = 0;
        int high = n-1;
        int index = 0;

        while(index <= high){
            if(nums[index] == 0){
                swap(nums[index], nums[low]);
                low++;
                index++;
            }
            else if(nums[index] == 2){
                swap(nums[index], nums[high]);
                high--;
            }
            else{
                index++;
            }
        }
    }
};

// Method 2: Counting approach -> uses: inplace (shuffling) -> TC: O(n) SC: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroC, oneC, twoC;
        zeroC = oneC = twoC = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                zeroC++;
            else if(nums[i] == 1)
                oneC++;
            else
                twoC++;
        }

        int i = 0;
        while(zeroC){
            nums[i] = 0;
            i++;
            zeroC--;
        }
        while(oneC--){
            nums[i] = 1;
            i++;
        }
        while(twoC--){
            nums[i++] = 2;
        }
    }
};

// Method 1: to use sort function: TC: O(nlogN) SC: O(log n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
