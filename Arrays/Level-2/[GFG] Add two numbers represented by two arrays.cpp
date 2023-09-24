// Method: Using 2 Pointer
class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
    
    string ans;
    int i = n - 1;
    int j = m - 1;
    int carry = 0;
    
    while(i >= 0 && j >= 0){
        int x = a[i] + b[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        i--, j--;
    }
    
    while(i >= 0){
        int x = a[i] + 0 + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        i--;
    }
    
    while(j >= 0){
        int x = 0 + b[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        j--;
    }
    
    // Add final carry to the string
    if(carry)
        ans.push_back(carry + '0');
        
    // sp case: if 0's are present in the end of the string before reversing
    while(ans[ans.size() - 1] == '0')
        ans.pop_back();
    
    // reverse the string
    reverse(ans.begin(), ans.end());
    
    return ans;
    }
};
