#include <iostream>
using namespace std;

void merge(int* arr, int s, int e){
    
    int mid = s + (e-s)/2;
    int lenLeft = mid - s + 1;
    int lenRight = e - mid;

    int* leftArr = new int[lenLeft];
    int* rightArr = new int[lenRight]; 

    // copy elements from original arr's left part to leftArr
    int k = s;
    for(int i = 0; i < lenLeft; i++){
        leftArr[i] = arr[k];
        k++;
    }

    // copy elements from original arr's right part to rightArr
    k = mid + 1;
    for(int i = 0; i < lenRight; i++){
        rightArr[i] = arr[k];
        k++;
    }

    int leftArrIndex = 0;
    int rightArrIndex = 0;
    int mainArrIndex = s;

    while(leftArrIndex < lenLeft && rightArrIndex < lenRight){
        if(leftArr[leftArrIndex] < rightArr[rightArrIndex]){
            arr[mainArrIndex] = leftArr[leftArrIndex];
            mainArrIndex++;
            leftArrIndex++;
        }
        else{
            arr[mainArrIndex] = rightArr[rightArrIndex];
            mainArrIndex++;
            rightArrIndex++;
        }
    }

    while(leftArrIndex < lenLeft){
        arr[mainArrIndex] = leftArr[leftArrIndex];
        mainArrIndex++;
        leftArrIndex++;
    }

    while(rightArrIndex < lenRight){
        arr[mainArrIndex] = rightArr[rightArrIndex];
        mainArrIndex++;
        rightArrIndex++;
    }

    // de-allocate the heap memory ; best practice
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int* arr, int s, int e){
    if(s > e)
        return;
    if(s == e)
        return; 
    int mid = s + (e-s)/2;
    mergeSort(arr, s, mid); // left call
    mergeSort(arr, mid+1, e); // right call 
    merge(arr, s, e);     // merge 2 sorted arr.
}

int main(){
    int arr[] = {2,1,6,9,4,5};
    int size = sizeof(arr)/sizeof(int);
    cout << "Before Merge sort: " << endl;
    for(auto i: arr)
        cout << i << " ";

    mergeSort(arr, 0, size-1);

    cout << endl << "After Merge sort: " << endl;
    for(auto i: arr)
        cout << i << " ";
}

/*
Before Merge sort: 
2 1 6 9 4 5 
After Merge sort: 
1 2 4 5 6 9 
*/
