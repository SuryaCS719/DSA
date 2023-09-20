// 10.1 Dividing of 2 numbers using Binary Search

int getQuotient(int divisor, int dividend){
    int start = 0;
    int end = dividend;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(mid * divisor == dividend)
            return mid;
        else if(mid * divisor < dividend){
            ans = mid;
            start = mid + 1;
        }
        // else if(mid * divisor > divident)
        else
            end = mid - 1;
    }
    return ans;
}

int main(){
    int divisor = 7;
    int dividend = 29; // taking dividend as zero gives the answer as 0 so it works.
    int ans = getQuotient(abs(divisor), abs(dividend));

    // special case where if the divisor = 0
    if(!divisor){
        cout << "undefined" << endl;
        return 0;
    }

    if((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0))
        cout << 0 - ans;
    // else if((divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0))
    else
        cout << ans;
}

// 10.2 Dividing of 2 numbers Float O/P variation ; Custom.
