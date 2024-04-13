// Method 1; my method brute force

class Solution {
public:

    void permute(vector<int>& nums, vector<vector<int>>& perm, int start){
        if(start >= nums.size()){
            perm.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++){
            swap(nums[i], nums[start]);
            permute(nums, perm, start + 1);
            swap(nums[i], nums[start]);
        }
    }

    int countArrangement(int n) {
        int count = 0;
        vector<int> nums;
        vector<vector<int>> perm;

        for(int i = 1; i <= n; i++)
            nums.push_back(i);

        // find all permutations
        permute(nums, perm, 0);

        // extract beautiful arrangements
        for(auto v : perm){
            bool flag = true;
            for(int i = 1; i <= v.size(); i++){ // i = 0; i < v.size()
                if(!(v[i - 1] % i == 0) && !(i % v[i - 1] == 0)) { // v[i] % (i+1)
                    flag = false;
                    break;
                } 
            }
            if(flag)
                count++;
        }

        // for (auto v : perm) {
        //     bool beautiful = true;
        //     for (int i = 0; i < v.size(); i++) {
        //         if ((v[i] % (i + 1) != 0) && ((i + 1) % v[i] != 0)) {
        //             beautiful = false;
        //             break;
        //         }
        //     }
        //     if (beautiful)
        //         count++;
        // }
        
        return count;
    }
};


// Method 2: backtracking

class Solution {
public:

    void countArrangementHelper(vector<int>& v, int& n, int& ans, int currentNumber) {
        if(currentNumber == n + 1){
            ans++;
            return;
        }

        for(int i = 1; i <= n; i++){
            if(v[i] == 0 && (currentNumber % i == 0 || i % currentNumber == 0)){
                v[i] = currentNumber;
                countArrangementHelper(v, n, ans, currentNumber + 1);
                v[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> v(n + 1);
        int ans = 0;
        countArrangementHelper(v, n, ans, 1);
        return ans;
    }
};


