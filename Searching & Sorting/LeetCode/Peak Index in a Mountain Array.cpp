// Note: in method 1: incase of s < e  ; putting s <= e gives infinite loop.
// Method 1:

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;

        while(s < e){
            int mid = s + (e-s)/2;

            if(arr[mid] < arr[mid+1])
                s = mid+1;

            else{
                e = mid;
            }
        }
        return s;
    }
};


// Method 2: 
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int ans = -1;
        int start = 0;
        int end = a.size() - 1;

        while(start <= end){
            int mid = (start + end) / 2;
            if(a[mid + 1] > a[mid]){
                start = mid + 1;
            }
            else if(a[mid - 1] > a[mid]){
                end = mid - 1;
            }
            else {
                // It must be Peak
                ans = mid;
                break;
            }
        }
        return ans;
    }
};
