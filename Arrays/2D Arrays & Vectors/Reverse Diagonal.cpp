// Variation 1: Expected Output: 11 6 15 

// Method 1
void reverseDiagPrint(int arr[][4], int row, int col){
    for(int i=0;i<row;i++){
        cout << arr[i][col - 1 - i] << " ";
    }
}

// Method 2
void reverseDiagPrint(int arr[][4], int row, int col){
    for(int i=0, j=col-1 ; i < row && j >= 0 ; i++, j--){
        cout << arr[i][j] << " ";
    }
}

int main(){
    int arr[3][4]={
        {10, 20, 5, 11},
        {2, 4, 6, 12},
        {10, 15, 18, 13}
    };
    int row = 3, col=4;
    reverseDiagPrint(arr, row, col);
}

// Variation 2: Expected Output: 30 4 5

// Using for loop
void reverseDiagPrintV2(int (*arr)[4], int row, int col){  // same as int arr[][4]
    for(int i = row-1, j = 0 ; i >=0 ; i--, j++){
        cout << arr[i][j] << " ";
    }
}

// Using while loop
void reverseDiagPrintV2(int (*arr)[4], int row, int col){
    int i = row - 1;
    int j = 0;
    while(i>=0){
        cout<< arr[i][j] << " ";
        i--;
        j++;
    }
}

int main(){
    int arr[3][4]={
        {10, 20, 5, 11},
        {2, 4, 6, 12},
        {30, 15, 18, 13}
    };
    int row = 3, col=4;
    reverseDiagPrintV2(arr, row, col);
}
