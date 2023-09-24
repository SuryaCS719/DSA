#include <iostream>
#include <vector>
using namespace std;

// Print vector function
void printArr(vector<int>& arr){
    for(int i=0;i<arr.size(); i++)
        cout<< arr[i] << " ";
}

// 1. Bubble Sort -> TC: O(n^2) ; SC: O(1)
void bubbleSort(vector<int>& arr, int n){
  // int k = n - 1;
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < n - i - 1; j++){ // can use k 
      if(arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);
    }
    // k--;
  }
}

// 2. Selection Sort -> TC: O(n^2) ; SC: O(1)
void selectionSort(vector<int>& arr, int n){
  for(int i = 0; i < n - 1; i++){
    int minIndex = i;
    for(int j = i + 1; j < n; j++){
      if(arr[minIndex] > arr[j])
        minIndex = j;
    }
    swap(arr[i], arr[minIndex]);
  }
}

// 3. Insertion Sort -> TC: O(n^2) ; SC: O(1)
void insertionSort(vector<int>& arr, int n){
  for(int i = 1; i < n; i++){
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key){   //fails when j is out of bound
      arr[j+1] = arr[j];
      j--;   // j will be outofbound i.e -1
    }
    arr[j+1] = key; 
    // j+1 cuz when j is outofbound i.e = -1 then -1 + 1 = 0 so arr[j+1] which is equal to arr[0] if taken arr[j] that would be equal to arr[-1]
  }
}


int main(){
    vector<int> arr = {50, 400, 3000, 2, 1};
    int n = arr.size();
    bubbleSort(arr, n);
    selectionSort(arr, n);
    insertionSort(arr, n);
    printArr(arr);
    return 0;
}
