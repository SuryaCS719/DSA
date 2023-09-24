#include <iostream>
#include <vector>
using namespace std;

// Print vector function
void printArr(vector<int>& arr){
    for(int i=0;i<arr.size(); i++)
        cout<< arr[i] << " ";
}

// 1. Bubble Sort -> TC: O(n^2) ; SC: O(1)
void bubbleSort(vector<int>& arr){
  int n = arr.size();
  // int k = n - 1;
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < n - i - 1; j++){ // can use k 
      if(arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);
    }
    // k--;
  }
}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1};
    bubbleSort(arr);
    printArr(arr);
    return 0;
}
