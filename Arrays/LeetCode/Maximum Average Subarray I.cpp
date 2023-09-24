// Method 1: BruteForce -> O(n^2)
class Solution {
public:
    double bruteForce(vector<int>& nums, int& k){
        int maxSum = INT_MIN;
        int z = 0;
        int j = k - 1;
        while(j < nums.size()){
            int sum = 0;
            for(int i = z; i <= j; i++)
                sum += nums[i];
            maxSum = max(maxSum, sum);
            z++, j++;
        }
        double maxAvg = (double)maxSum / k;
        return maxAvg;
    }

    double findMaxAverage(vector<int>& nums, int k) {
        return bruteForce(nums, k);
    }
};

// Method 2: Sliding Window -> O(n)
class Solution {
public:
    double slidingWindow(vector<int>& nums, int k){
        // if there exist only 1 window
        int z = 0;
        int j = k - 1;
        int sum = 0;
        for(int i = z; i <= j; i++)
            sum += nums[i];
        int maxSum = sum;
        j++;
        // While loop only works if windows > 1
        while(j < nums.size()){
            sum -= nums[z++];
            // z++;
            sum += nums[j++];
            // j++;
            maxSum = max(maxSum, sum);
        }
        double maxAvg = (double)maxSum / k;
        return maxAvg;
    }

    double findMaxAverage(vector<int>& nums, int k) {
        return slidingWindow(nums, k);
    }
};
