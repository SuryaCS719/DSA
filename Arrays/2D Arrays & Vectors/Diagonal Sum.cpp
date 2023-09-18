// Method 1
void diagWiseSum(int arr[][4], int row, int col){
    int sum = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i == j){
                sum += arr[i][j];
            }
        }
    }
    cout << sum << endl;
}

// Method 2 - works only for equal rows and cols.
void diagWiseSum(int arr[][4], int row, int col){
    int sum = 0;
    for(int i=0;i<row;i++){
        sum += arr[i][i];
    }
    cout << sum << endl;
}

// Main
int main(){
    int arr[3][4]={
        {10, 20, 5, 7},
        {2, 4, 6, 8},
        {10, 15, 18, 19}
    };
    int row = 3, col=4;
    diagWiseSum(arr, row, col);
}
