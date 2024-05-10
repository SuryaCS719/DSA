#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int sumMinMaxOfAllWindowSizeK(vector<int>& nums, int k) {
    int ans = 0;
    deque<int> dq;
    deque<int> dq2;

    // Step 1: process first window
    for(int i = 0; i < k; i++) {
        // for max ele
        while(!dq.empty() && nums[i] > nums[dq.back()])
            dq.pop_back();
        
        //for min ele
        while(!dq2.empty() && nums[i] < nums[dq2.back()])
            dq2.pop_back();

        dq.push_back(i);
        dq2.push_back(i);
    }
    // store first window's ans
    ans += nums[dq.front()] + nums[dq2.front()];

    // Step 2: process remaining windows
    for(int i = k; i < nums.size(); i++) {
        // removal
        // 1. check for out of bound
        if(!dq.empty() && i - dq.front() >= k)
            dq.pop_front(); 

        if(!dq2.empty() && i - dq2.front() >= k)
            dq2.pop_front(); 
          
        // 2. pop the smaller ele
        while(!dq.empty() && nums[i] > nums[dq.back()])
            dq.pop_back();

        while(!dq2.empty() && nums[i] < nums[dq2.back()])
            dq2.pop_back();

        // addition
        dq.push_back(i);
        dq2.push_back(i);
        
        // store currrent Window's ans.
        ans += nums[dq.front()] + nums[dq2.front()];
    }
    return ans;
}

int main() {
    vector<int> v{2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << sumMinMaxOfAllWindowSizeK(v, k) << endl;
    return 0;
}


// o/p: 18 for k = 4
// o/p: 14 for k = 2
