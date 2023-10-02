// Method 2: W/out using erase 
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(1){
            int found = s.find(part);
            if(found == string::npos)
                break;
            
            string leftPart = s.substr(0, found);
            string rightPart = s.substr(found + part.length(), s.length()); 
            // can use size instead of length
            s = leftPart + rightPart;
        }
        return s;
    }
};

// Method 1: Using erase 
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
