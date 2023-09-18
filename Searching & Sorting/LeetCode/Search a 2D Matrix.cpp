//TC: O(log m*n) -> Binary search on 2D array
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row * col; // Total no.of cells in a matrix

        int s = 0;
        int e = n - 1;

        while(s <= e){
            int mid = s + (e - s)/2;
            
            int rowIndex = mid / col;
            int colIndex = mid % col;
            int currNumber = matrix[rowIndex][colIndex];

            if(currNumber == target)
                return true;
            else if(target > currNumber)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }
};

/*
Conversion Formulas:
2D to 1D: c * i + j 
1D to 2D: i = currIndex / c ; j = currIndex % c
where c = total no.of cols, i = rowIndex, j = colIndex.
*/
