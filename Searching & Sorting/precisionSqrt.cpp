// To produce precision upto n decimal points. Sqrt.
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
