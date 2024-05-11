// LeetCode (Medium) : https://leetcode.com/problems/reverse-integer/description/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        bool isNegative = false;

        // x < int_min return 0 as given in the question
        // but we also return 0 if x == INT_MIN.
        // since val of int_min is: -2147483648
        // when we convert -ve x to +ve x it turns becomes +2147483648
        // which croses the int_max val i.e. 2147483647
        // thus we check for <=.
        if(x <= INT_MIN) return 0;
        // change -ve val of x to +ve
        if(x < 0) {
            isNegative = true;
            x = -(x);
        }
        while(x > 0) {
            // int_max val: 2147483647
            // int_max / 10 val: 214748364
            // if ans > 214748364 then return 0
            // ex: lets say ans = 214748365
            // ans = 2147483645 * 10 = 2147483650 i.e > INT_MAX
            if(ans > INT_MAX / 10)
                return 0;
            // reverse algorithm
            int digit = x % 10; // 1. extract last digit
            x = x / 10; // 2. shrinking the number by removing its last digit.
            ans = ans * 10 + digit; 
        }
        return isNegative ? -ans : ans;
    }
};
