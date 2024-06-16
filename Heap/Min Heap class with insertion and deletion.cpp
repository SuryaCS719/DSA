#include <iostream>
#include <limits.h>
using namespace std;


// Min Heap implementation 1-based indexing:

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

  void insertIntoMinHeap(int val) {
    if(size == capacity) {
      cout << "Heap Overflow" << endl;
      return;
    }

    size++;
    int index = size;
    arr[index] = val;

    while(index > 1) {
      int parentIndex = index / 2;
      if(arr[parentIndex] > arr[index]) {
        swap(arr[parentIndex], arr[index]);
        index = parentIndex;
      }
    }
  }

  int deleteFromMinHeap() {
    if(size == 0) {
      cout << "Heap underflow" << endl;
      return INT_MIN;
    }

    int ans = arr[1];

    arr[1] = arr[size];  // can use either: swap(arr[1], arr[size]);
    size--;

    // now heapify
    int index = 1;
    while(index < size) {
      int left_child_index = 2 * index;
      int right_child_index = 2 * index + 1;
      int smallestElementIndex = index;

      if(left_child_index <= size && arr[left_child_index] < arr[smallestElementIndex])
        smallestElementIndex = left_child_index;
      
      if(right_child_index <= size && arr[right_child_index] < arr[smallestElementIndex])
        smallestElementIndex = right_child_index;
      
      if(index == smallestElementIndex)
        break;
      else {
        swap(arr[index], arr[smallestElementIndex]);
        index = smallestElementIndex;
      }
    }

    return ans;
  }


  void printHeap() {
    // ignore 0th index as this is a 1-based index Min Heap
    for(int i = 1; i <= size; i++)
      cout << arr[i] << " ";
  }

};

int main() {

  Heap h(10);
  h.insertIntoMinHeap(20);
  h.insertIntoMinHeap(15);
  h.insertIntoMinHeap(10);
  h.insertIntoMinHeap(5);
  h.insertIntoMinHeap(2);
  h.insertIntoMinHeap(1);

  cout << "Printing MinHeap: " << endl;
  h.printHeap();

  int ans = h.deleteFromMinHeap();
  cout << endl << "deleted from minHeap: " << ans << endl;

  cout << "Printing MinHeap after deletion: " << endl;
  h.printHeap();
  
  return 0;
}


/*
inserted into: Min Heap: 
            20
           /   \
          15   10
         / \   /
        5   2  1

Formation: 1, 5, 2, 20, 10, 15
             1
           /  \
          5    2
         / \   /
        20  10 15

*/
