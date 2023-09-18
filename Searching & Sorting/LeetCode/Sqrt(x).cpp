class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        int ans = -1;
        
        while(s<=e){
            // int mid = s + (e-s)/2;
            long long mid = s + (e - s)/2;

            if (mid*mid == x)
                return mid;
            
            else if(mid*mid < x){
                ans = mid;
                s = mid+1;
            }
            else
                e = mid-1;
        }
        return ans;
    }
};


// Another Method to produce precision upto n decimal points.
