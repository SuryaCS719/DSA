// this is applicable for Max Heap 1-based indexing:


#include <iostream>
#include <limits.h>
using namespace std;

class Heap {
public:
  int *arr; 
  int capacity;
  int size;

  Heap(int capacity) {
    this->arr = new int[capacity];
    this->capacity = capacity;
    this->size = 0;
  }

// max heap 1-based indexing
void insertIntoMaxHeap(int val) {
  if(size == capacity) {
    cout << "Heap Overflow" << endl;
    return;
  }
  
  size++;
  int index = size;
  arr[index] = val;

  while(index > 1) {
    int parentIndex = index / 2;
    if(arr[index] > arr[parentIndex]) {
      swap(arr[index], arr[parentIndex]);
      index = parentIndex;
    }
    else
      break;
  }
}

void printHeap() {
  // ignore 0th index as this is a 1-based index Max Heap
  for(int i = 1; i <= size; i++)
    cout << arr[i] << " ";
}

int deleteInMaxHeap() {
  if (size == 0) {
    cout << "Heap Underflow" << endl;
    return INT_MIN;
  }

  int ans = arr[1]; // // Store the maximum element to be returned later
  // 1. replace root node w/ last node in the heap
  arr[1] = arr[size];
  // 2. delete the original last node in heap
  size--; // Decrease the size of the heap after extracting an element.
        // The element still exists in memory; we have logically removed it
        // from the heap structure to maintain proper heap properties.

  // 3. Now perform heapify so that the root node is at it's correct pos in the heap
  int index = 1;
  while(index < size) { // index <= size, not required cuz we dont need to heapify the last_element
    int left_child_index = 2 * index;
    int right_child_index = 2 * index + 1;
    // lets find out whats thelargestElementIndex
    int largestElementIndex = index;
    // check for left child
    if(left_child_index <= size && arr[left_child_index] > arr[largestElementIndex])
      largestElementIndex = left_child_index;
    // check for right child
    if(right_child_index <= size && arr[right_child_index] > arr[largestElementIndex])
      largestElementIndex = right_child_index;
    
    // now the largestElementIndex is at largest element among the currRoot, it's left and it's right child.

    if(index == largestElementIndex) // no change, the node replaced initially was at the correct pos
      break;

    swap(arr[index], arr[largestElementIndex]);
    index = largestElementIndex;  // this continues the process for the rest of the heap if need be.
  }

  return ans;
}

};

int main() {
  Heap h(10);

  h.insertIntoMaxHeap(10);
  h.insertIntoMaxHeap(20);
  h.insertIntoMaxHeap(5);
  h.insertIntoMaxHeap(11);
  h.insertIntoMaxHeap(6);

  cout << "Printing maxHeap: " << endl;
  h.printHeap();

  int ans = h.deleteInMaxHeap();
  cout << endl << "deleted from maxHeap: " << ans << endl;

  cout << "Printing maxHeap after deletion: " << endl;
  h.printHeap();

  return 0;
}

/*

input: 10 20 5 11 6
output: 20 11 5 10 6 // after insertion

  Max Heap:

        20
      /  \
      11   5
    /  \
    10   6

*/
