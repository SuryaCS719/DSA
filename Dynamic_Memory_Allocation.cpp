// // /* Dynamic memory allocaiton on the following:
// // 1. Integer : allocate heap
// // 2. Array : allocate heap
// // 3. 2D Array : allocate heap
// // 4. All of the above w/out using new keyword */

#include<iostream>
using namespace std;

void print(int **v, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // integer allocation
    int *intPtr = new int(5); 
    int *intPtrMalloc = (int*)malloc(4); // using malloc
    *intPtrMalloc = 5;

    cout << *intPtr << " " << *intPtrMalloc << endl;

    delete[] intPtr;
    free(intPtrMalloc);
    
    // 1D allocation
    int *arr = new int[5]; 
    int *arrMalloc = (int*)malloc(5 * sizeof(int)); 

    for(int i = 0; i < 5; i++) {
        int d;
        cin >> d;
        arr[i] = arrMalloc[i] = d;
    }

    for(int i = 0; i < 5; i++)
        cout << arr[i] << " " << arrMalloc[i] << endl;
    
    delete[] arr;
    free(arrMalloc);

    // 2D Heap allocation:
    int rows = 5;
    int cols = 5;
    int **arr2D = new int*[rows]; 

    for(int i = 0; i < rows; i++)
        arr2D[i] = new int[cols];

    int **arr2DMalloc = (int**)malloc(rows * sizeof(int*)); 

    for(int i = 0; i < rows; i++)
        arr2DMalloc[i] = (int*)malloc(cols * sizeof(int));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr2D[i][j] = 7;
            arr2DMalloc[i][j] = 8;
        }
    }


    print(arr2D, rows, cols);
    print(arr2DMalloc, rows, cols);


    for(int i = 0; i < rows; i++)
        delete[] arr2D[i];
    delete[] arr2D;


    for(int i = 0; i < rows; i++) 
        free(arr2DMalloc[i]);
    free(arr2DMalloc);

    return 0;
}





