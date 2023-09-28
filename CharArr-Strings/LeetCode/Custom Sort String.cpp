class Solution {
public:
    
    static string temp;

    // Custom Comparator
    static bool compare(char char1, char char2){
        return (temp.find(char1) < temp.find(char2));
        // if true is returned then char1 will be placed before
        // char2 in the output string.
    }


    string customSortString(string order, string s) {
        temp = order;
        sort(s.begin(), s.end(), compare);
        return s;
    }
};
string Solution::temp;
