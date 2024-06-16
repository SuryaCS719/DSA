#include <iostream>
using namespace std;


void heapifyMinHeap(int arr[], int size, int index) {
  int left_child_index = 2 * index;
  int right_child_index = 2 * index + 1;
  int smallestElementIndex = index;

  if(left_child_index <= size && arr[left_child_index] < arr[smallestElementIndex])
    smallestElementIndex = left_child_index;

  if(right_child_index <= size && arr[right_child_index] < arr[smallestElementIndex])
    smallestElementIndex = right_child_index;
  
  if(smallestElementIndex != index) {
    swap(arr[index], arr[smallestElementIndex]);
    heapifyMinHeap(arr, size, smallestElementIndex);
  }
}

void buildMinHeapFromArray(int arr[], int size) {
  for(int i = size / 2; i >= 1; i--)
    heapifyMinHeap(arr, size, i);
}

void heapSort(int arr[], int size) {
  while(size > 1) {
    swap(arr[1], arr[size]);
    size--;
    heapifyMinHeap(arr, size, 1);
  }
}

int main() {
  int arr[] = {-1, 20, 10, 15, 5, 2, 1};
  int n = 6;

  cout << "Printing Original array: " << endl;
  for(int i = 1; i <= n; i++)
    cout << arr[i] << " ";
  
  buildMinHeapFromArray(arr, n);
  cout << endl << "Printing Heapified minHeap: " << endl;
  for(int i = 1; i <= n; i++)
    cout << arr[i] << " ";
  
  heapSort(arr, n);
  cout << endl << "Sorted array using Heap sort: " << endl;
  for(int i = 1; i <= n; i++)
    cout << arr[i] << " ";

  return 0;
}


/*

Printing Original array: 
20 10 15 5 2 1 
Printing Heapified minHeap: 
1 2 15 5 10 20 
Sorted array using Heap sort: 
20 15 10 5 2 1 

*/
