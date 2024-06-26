#include <iostream>
#include <vector>
using namespace std;

//WavePrint Col Wise: for even col -> Top-Bottom ; odd col -> Bottom-Up
void wavePrintMatrix(vector<vector<int> > arr){
    int row = arr.size();
    int col = arr[0].size();

    for(int startCol=0; startCol < col; startCol++){
        // even cols
        if((startCol & 1) == 0){
            for(int i=0; i < row; i++){
                cout << arr[i][startCol] << " ";
            }
        }
        else{
            for(int i = row - 1; i >=0 ; i--){
                cout << arr[i][startCol] << " ";
            }
        }
    }  
}

//WavePrint Row Wise: for even col -> firstCol - lastCol ; odd row: lastCol - firstCol
void wavePrintMatrixV2(vector<vector<int> > arr){
  int row = arr.size();
  int col = arr[0].size();
  for(int startRow=0; startRow < row; startRow++){
    // Even rows
    if((startRow & 1) == 0){
      for(int i=0; i < col; i++){
        cout << arr[startRow][i] << " ";
      }
    }
    else{
      for(int i = col - 1 ; i >= 0 ; i--){
        cout << arr[startRow][i] << " ";
      }
    }
  }
}

int main(){
    vector<vector<int> > arr {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    cout << "WavePrint Col Wise" << endl;
    wavePrintMatrix(arr);
    cout << endl;
    cout << "WavePrint Row Wise" << endl;
    wavePrintMatrixV2(arr);
    // return 0;
}

// Output:
WavePrint Col Wise
1 5 9 10 6 2 3 7 11 12 8 4 
WavePrint Row Wise
1 2 3 4 8 7 6 5 9 10 11 12 







// dynamic col size allocation instead of:  int col = arr[0].size();   // in case of jagged 2d vector

#include <iostream>
#include <vector>
using namespace std;

void wavePrintMatrix(vector<vector<int>> arr) {
    int row = arr.size();
    if (row == 0) return; // Handle empty matrix case

    int maxCol = 0;
    // Find the maximum number of columns in any row using a traditional for loop
    for (int i = 0; i < row; i++) {
        if (arr[i].size() > maxCol) {
            maxCol = arr[i].size();
        }
    }

    for (int startCol = 0; startCol < maxCol; startCol++) {
        // even cols
        if ((startCol & 1) == 0) {
            for (int i = 0; i < row; i++) {
                if (startCol < arr[i].size()) {
                    cout << arr[i][startCol] << " ";
                }
            }
        } else {
            for (int i = row - 1; i >= 0; i--) {
                if (startCol < arr[i].size()) {
                    cout << arr[i][startCol] << " ";
                }
            }
        }
    }  
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9},
        {10}
    };

    wavePrintMatrix(arr);

    return 0;
}

