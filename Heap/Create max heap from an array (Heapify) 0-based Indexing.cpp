#include <iostream>
using namespace std;

// Heapify using recursion (0-based indexing):
void heapify(int *arr, int n, int index) {
  int left_child_index = 2 * index + 1; // Adjusted for 0-based indexing
  int right_child_index = 2 * index + 2; // Adjusted for 0-based indexing
  int largestElementIndex = index;

  // Find the largest element index among index, left child, and right child
  if (left_child_index < n && arr[left_child_index] > arr[largestElementIndex])
    largestElementIndex = left_child_index;

  if (right_child_index < n && arr[right_child_index] > arr[largestElementIndex])
    largestElementIndex = right_child_index;

  if (largestElementIndex != index) {
    swap(arr[index], arr[largestElementIndex]);
    heapify(arr, n, largestElementIndex); // Recursive heapify call
  }
}

// Creating a heap from 'n' size array - TC: O(n)
void buildHeapFromArray(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) // Adjusted for 0-based indexing
    heapify(arr, n, i);
}

int main() {
  int arr[] = {10, 20, 5, 11, 6}; // Adjusted for 0-based indexing
  int n = sizeof(arr) / sizeof(arr[0]); // Adjusted to calculate number of elements

  cout << "Array: " << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  buildHeapFromArray(arr, n);

  cout << endl << "Max Heap: " << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}
