// Method 1: Brute Force 
class Solution {
public:

    int bruteForce(vector<int>& nums){

        int n = nums.size();

        for(int i=0; i<n; i++){
            int sumL = 0;
            int sumR = 0;

            // to find left sum excl currIndex
            for(int j=0; j<i; j++)
                sumL += nums[j];
            
            // to find right sum excl currIndex
            for(int j=i+1; j<n; j++)
                sumR += nums[j];
            
            // cout << "for index "<<i<<" sumL: "<<sumL<< " sumR: "<<sumR << endl;

            if(sumL == sumR) 
                return i;
        }
        return -1;
    }

    int pivotIndex(vector<int>& nums) {
        return bruteForce(nums);
    }
};

// Method 2: Prefix Sum Approach
class Solution {
public:

    int prefixSumApproach(vector<int>& nums){
        int n = nums.size();
        vector<int> sumL(n, 0);
        vector<int> sumR(n, 0);
        
        // calc left sum array
        for(int i=1; i<n; i++)
            sumL[i] = sumL[i-1] + nums[i-1];

        // calc right sum array
        for(int i=n-2; i>=0; i--)
            sumR[i] = sumR[i+1] + nums[i+1];
        
        // check for pivot index
        for(int i=0; i<n; i++)
            if(sumL[i] == sumR[i]) 
                return i;
                
        return -1;
    }

    int pivotIndex(vector<int>& nums) {
        return prefixSumApproach(nums);
    }
};
