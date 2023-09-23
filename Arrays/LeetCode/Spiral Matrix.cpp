class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int totalElements = m * n;

        int startRow = 0;
        int endCol = n - 1;
        int endRow = m - 1;
        int startCol = 0;
        
        int count = 0;
        while(count < totalElements){
            
            // startRow
            for(int i = startCol; i <= endCol && count < totalElements; i++){
                ans.push_back(matrix[startRow][i]);
                count++;
                // if(count >= totalElements)
                //     break;
            }

            startRow++;

            // endCol
            for(int i = startRow; i <= endRow && count < totalElements; i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }

            endCol--;

            // endRow
            for(int i = endCol; i >= startCol && count < totalElements; i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            
            endRow--;

            // startCol
            for(int i = endRow; i >= startRow && count < totalElements; i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }

            startCol++;
        }
        return ans;
    }
};
