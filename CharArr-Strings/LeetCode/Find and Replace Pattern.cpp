class Solution {
public:
    //create mapping
    void createMapping(string& str){
        char start = 'a';
        char mapping[300] = {0};
        for(auto ch: str){
            if(mapping[ch] == 0){
                mapping[ch] = start;
                start++;
            }
        }
        // update the string using for loop
        // for(int i=0; i < str.length(); i++){
        //     // char ch = str[i];
        //     // str[i] = mapping[ch];
        //     str[i] = mapping[str[i]];
        // }

        // update the string using for each loop and passing it as reference
        for (char &i : str) {
            i = mapping[i];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        // Normalizing the pattern
        createMapping(pattern);

        // Normalizing the words
        for(string s: words){
           // createMapping(s); // cant do this because original i/p of s is being modified and the output is also normalized which we dont want.
           
           string tempStr = s;
           createMapping(tempStr);
           

            if(tempStr == pattern)
                ans.push_back(s);
        }
        return ans;
    }
};
