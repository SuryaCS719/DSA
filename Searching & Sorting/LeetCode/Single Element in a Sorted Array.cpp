// Same question as find the odd occuring element.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;

        while(s <= e){
            int mid = s + (e-s)/2;

            // if(s == e)
            //     return nums[s];

            //check for mid at odd index
            if(mid & 1){
                if(mid - 1 >= 0 && nums[mid] == nums[mid-1])
                    s = mid + 1;
                else
                    e = mid - 1;
            } 

            else{
                if(mid + 1 < nums.size() && nums[mid] == nums[mid+1])
                    s = mid + 2;
                else if(mid - 1 >= 0 && nums[mid] == nums[mid-1])
                    e = mid - 2;
                else{
                    ans = nums[mid];
                    break;
                }
            }
        }
        return ans;
    }
};
