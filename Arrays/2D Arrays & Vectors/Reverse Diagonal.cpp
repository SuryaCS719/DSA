// Variation 1: Expected Output: 11 6 15 

void reverseDiagPrint(int arr[][4], int row, int col){
    for(int i=0;i<row;i++){
        cout << arr[i][col - 1 - i] << " ";
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

// Variation 2: Expected Output: 10 4 5


