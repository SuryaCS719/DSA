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
