// method 1:
// Time complexity: O(sqrt(x));
class Solution {
public:
    int mySqrt(int x) {

        if (x == 0 || x == 1)
            return x;
        long long i = 0;
        while(i * i <= x){
            i += 1;
        }
        return int(i) - 1;
    }
};
//---------------------

class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        int ans = -1;
        
        while(s<=e){
            // int mid = s + (e-s)/2;
            //using long long because mid * mid gives a large value in few cases.
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


// H/W: Another Method to produce precision upto n decimal points. Custom:
#include <iostream>
using namespace std;

int sqrt(int n){
    int s = 0;
    int e = n;
    int ans = 0;
    while(s <= e){
        int mid = s + (e-s)/2;

        if(mid*mid <= n){
            ans = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    return ans;
}

double preciseSqrt(int n, int precision){
    double integerAns = sqrt(n);
    double step = 0.1;

    for(int i=0; i < precision; i++){
        double j = integerAns;
        while(j * j <= n){
            integerAns = j;
            j += step;
        }
        step /= 10;
    }
    return integerAns;
}

int main(){
    int n = 51;
    int precision = 10;
    double ans = preciseSqrt(n, precision);
    // cout << ans << endl;
    printf("%0.10f", ans);
    return 0;
}
