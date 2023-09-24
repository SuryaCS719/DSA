class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans;
        ans.push_back(1);
        int carry = 0;
        for(int i = 2 ; i <= N ; i++){
            // int carry = 0;
            for(int j = 0 ; j < ans.size() ; j++){
                int x = ans[j] * i + carry;
                ans[j] = x % 10;
                carry = x / 10;
            }
            // if(carry) //--> Only works for small carry values
            //     ans.push_back(carry);
            
            // if carry is big 2 or more digits
            while(carry){
                ans.push_back(carry % 10);
                carry /= 10;
            }
                
        }
        // reverse the vector
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
