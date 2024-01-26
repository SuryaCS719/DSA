class Solution {
public:

    bool isPossibleSolution(vector<int> &stalls, int k, int mid){
        // to place k cows with >= mid value b/w them 
        int count = 1; // no. of cows
        int pos = stalls[0]; // placing 1st cow in 1st pos
        
        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i] - pos >= mid){
                count++;
                pos = stalls[i]; // one more cow has been placed
            }
            if(count == k) return true; // if all the cows have been placed
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int start = 0;
        int end = stalls[stalls.size() - 1] - stalls[0];
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(isPossibleSolution(stalls, k, mid)){
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};
