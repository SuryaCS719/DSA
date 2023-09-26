class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};


// To write Find and Erase functions by ourselves instead of using inbuilt functions
// What all algorithsm exist along with their time/space complexity to find a pattern in a string instead of inbuilt once like .find()
// implement erase 
