// Method 1: 2 Pointer
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int evenIndex = 0;
        int oddIndex = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0){
                ans[evenIndex] = nums[i];
                evenIndex += 2;
            }
            else{
                ans[oddIndex] = nums[i];
                oddIndex += 2;
            }
        }
        return ans;
    }
};

// Method 2: uses extra space
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }
        vector<int> ans;
        int i = 0;
        // since WKT-even length consisting of an equal number of positive and negative 
        while (i < pos.size()){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
        }
        return ans;
    }
};


// Note: 
// incase if array length is not even and does not have equal +ve and -ve no then:
/*
vector<int> ans;
        int i = 0;
        while (i < pos.size() && i < neg.size()) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
        }
        // Append remaining positive elements (if any)
        while (i < pos.size()) {
            ans.push_back(pos[i]);
            i++;
        }
        // Append remaining negative elements (if any)
        while (i < neg.size()) {
            ans.push_back(neg[i]);
            i++;
        }
*/

