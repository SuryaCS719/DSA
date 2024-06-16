#include <iostream>
using namespace std;

// Heapify using recursion:
void heapify(int *arr, int n, int index) {
  int left_child_index = 2 * index;
  int right_child_index = 2 * index + 1;
  int largestElementIndex = index;
  // now find what is the largestElementIndex
  if(left_child_index <= n && arr[left_child_index] > arr[largestElementIndex])
    largestElementIndex = left_child_index;
  
  if(right_child_index <= n && arr[right_child_index] > arr[largestElementIndex])
    largestElementIndex = right_child_index;

  if(largestElementIndex != index) {
    swap(arr[index], arr[largestElementIndex]);
    index = largestElementIndex;
    heapify(arr, n, index); // or we can pass largestElementIndex directly instead of index.
  }
}

// Creating an heap from 'n' size array - TC: O(n)
void buildHeapfromArray(int arr[], int n) {
  for(int i = n / 2; i >= 1; i--) 
    heapify(arr, n, i);
}


int main() {
  // Original array (1-based indexing)
  int arr[] = {-1, 10, 20, 5, 11, 6};  // Note: arr[0] is unused in 1-based indexing
  int n = 5; // Number of elements considered in the heap (1-based indexing)

  cout << "Array: " << endl;
  for(int i = 1; i <= n; i++) 
    cout << arr[i] << " ";

  buildHeapfromArray(arr, n);

  cout << endl << "Max Heap: " << endl;
  for(int i = 1; i <= n; i++) 
    cout << arr[i] << " ";

  return 0;
}
