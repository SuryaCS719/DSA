// Method 3: Binary Search
class Solution {
public:

    int lowerBound(vector<int>& arr, int x){
        int start = 0;
        int end = arr.size()-1;
        // incase if x is greater than all the elements in the array
        // then we will never hit the condition arr[mid] >= x, so we assume the last element in the sorted array to be the closest.
        int ans = end; 
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] >= x){
                ans = mid;
                end = mid - 1;
            }
            else // else if (arr[mid] < x)
                start = mid + 1;
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int high = lowerBound(arr, x);
        int low = high - 1;
        while(k--){
            if(low < 0)
                high++;
            else if(high >= arr.size())
                low--;
            else if(x - arr[low] > arr[high] - x){
                high++;
            }
            else{
                low--;
            }
        }
        return vector<int>(arr.begin() + low + 1, arr.begin() + high);
    }
};


// Method 2: Two Pointer
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size()-1;
        while(high - low >= k){
            if(abs(x - arr[low]) > abs(x - arr[high]))
                low++;
            else  // else if x - arr[high] >= x - arr[low]
                high--;
        }

        // vector<int> ans;
        // for(int i = low; i <= high; i++){
        //     ans.push_back(arr[i]);
        // }        
        // return ans;

        // using stl
        return vector<int>(arr.begin() + low, arr.begin() + high + 1);
    }
};


// Method 1: Using sort()
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> diffWithIndex;
        for(int i=0; i < arr.size(); i++){
            int diff = abs(arr[i] - x);
            diffWithIndex.push_back({diff, arr[i]});
        }
        sort(diffWithIndex.begin(), diffWithIndex.end());
        vector<int> ans;
        for(int i=0; i < k; i++){
            ans.push_back(diffWithIndex[i].second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
