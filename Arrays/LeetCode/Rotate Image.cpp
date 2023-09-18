// Approach: Transpose the matrix and then reverse the elements:
class Solution {
public:
    // Reverse function
    void reverseVector(vector<int>& arr){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<matrix[i].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // transpose done, now reverse all the elements in each row
        for(int i=0; i<n; i++){
            // Reverse function can be used instead of writing our own function to reverse.
            // reverse(matrix[i].begin(), matrix[i].end());
            reverseVector(matrix[i]);
        }
    }
};
