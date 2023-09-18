// 1.1 Row Wise Sum

void rowWiseSum(int arr[][4], int row, int col){
    for(int i=0;i<row;i++){
        int sum = 0;
        for(int j=0;j<col;j++){
            sum += arr[i][j];
        }
        cout << i << "th row's sum: " << sum << endl;
    }
}

int main(){
    int arr[3][4]={
        {10, 20, 5, 7},
        {2, 4, 6, 8},
        {10, 15, 18, 19}
    };
    int row = 3, col=4;
    rowWiseSum(arr, row, col);
}

// 1.2 Col Wise Sum

void colWiseSum(int arr[][4], int row, int col){
    for(int i=0;i<col;i++){
        int sum = 0;
        for(int j=0;j<row;j++){
            sum += arr[j][i];
        }
        cout << i << "th col's sum: " << sum << endl;
    }
}

int main(){
    int arr[3][4]={
        {10, 20, 5, 7},
        {2, 4, 6, 8},
        {10, 15, 18, 19}
    };
    int row = 3, col=4;
    colWiseSum(arr, row, col);
}
