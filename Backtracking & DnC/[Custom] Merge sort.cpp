#include <iostream>
using namespace std;

void merge(int arr[], int s, int e, int mid){
  // int mid = s + (e - s)/2;
  int lenLeft = mid - s + 1;
  int lenRight = e - mid;

  // create left and right arr dynamic allocation heap memory
  int* left_arr = new int[lenLeft];
  int* right_arr = new int[lenRight];

  int k = s;
  // copy values from original array to left_arr
  for(int i = 0; i < lenLeft; i++){
    left_arr[i] = arr[k];
    k++;
  }

  k = mid + 1; 
  // copy values from original array to right_arr
  for(int i = 0; i < lenRight; i++)
    right_arr[i] = arr[k++];

  // Actual Merge logic
  int i = 0; // leftIndex
  int j = 0; // rightIndex
  int mainArrayIndex = s; // Important. 

  while(i < lenLeft && j < lenRight){
    if(left_arr[i] < right_arr[j]){
      arr[mainArrayIndex] = left_arr[i];
      mainArrayIndex++;
      i++;
    }
    else{
      arr[mainArrayIndex] = right_arr[j];
      mainArrayIndex++;
      j++;
    }
  }

  while(i < lenLeft){
    arr[mainArrayIndex] = left_arr[i];
    mainArrayIndex++;
    i++;
  }

  while(j < lenRight){
    arr[mainArrayIndex] = right_arr[j];
    mainArrayIndex++;
    j++;
  }
  // Deallocation of Heap memory
  delete[] left_arr;
  delete[] right_arr;
}

void mergeSort(int arr[], int s, int e){
  if(s >= e) return;
  int mid = s + (e - s)/2; 
  mergeSort(arr, s, mid); //left_arr
  mergeSort(arr, mid + 1, e); //right_arr
  merge(arr, s, e, mid); // merge 2 sorted arr
}

int main() {
  int arr[] = {2, 1, 6, 9, 4, 5};
  int size = 6; 
  int s = 0;
  int e = size - 1;
  mergeSort(arr, s, e);
  for(auto it : arr)
    cout << it << " ";
  return 0;
}
