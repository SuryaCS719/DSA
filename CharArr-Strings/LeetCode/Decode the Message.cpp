class Solution {
public:
    string decodeMessage(string key, string message) {

        // create mapping
        
        char start = 'a';
        char mapping[300] = {0};

        // Using for each loop

        for(auto ch: key){
            if(ch != ' ' && mapping[ch] == 0){
                mapping[ch] = start;
                start++;
            }
        }

        // Same can be done with for loop:

        // for(int i=0; i<key.length();i++){
        //     char ch = key[i];

        //     if(ch != ' ' && mapping[ch] == 0){
        //         mapping[ch] = start;
        //         start++;
        //     }
        // } 

        // Use mappping

        string ans;
        
        for(auto ch: message){
        // for(int i=0; i<message.length();i++){
            // char ch = message[i];

            if(ch == ' ')
                ans.push_back(' ');
            else{
                char decodedChar = mapping[ch];
                ans.push_back(decodedChar);
            }
        }
        return ans;
    }
};
