//Rotate 2D array by 90 Degree
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


// same code as above but with visuals
class Solution {
public:

    void reverse2DMatrix(vector<int>& mat) {
        int size = mat.size();
        int i = 0;
        int j = size - 1;
        while(i < j) {
            swap(mat[i], mat[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        // step 1. Transpose the matrix
        // step 2. reverse the matrix
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            int m = matrix[i].size();
            for(int j = i; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // the matrix would look like this:
        // given:              transposed:
        // 1   2   3           1   4   7
        // 4   5   6           2   5   8
        // 7   8   9           3   6   9

        // now reverse the transposed matrix row-wise
        for(int row = 0; row < n; row++){
            // reverse(matrix[row].begin(), matrix[row].end());
            reverse2DMatrix(matrix[row]);
        }
        // transposed:         reversed:
        // 1   4   7           7    4   1
        // 2   5   8           8    5   2
        // 3   6   9           9    6   3
    }
};
