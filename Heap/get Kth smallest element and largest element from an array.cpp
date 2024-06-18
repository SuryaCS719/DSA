// Approach 1: Sort the array and return k-1th indexed element.


// Approach 2: Use Min Heap to get kth smallest element and Max heap to get kth largest element.
// like pop the elements till k == 1 and return whatever element is on top when k == 1. that's our answer:
// TC: O(N) SC: O(N)

#include <iostream>
#include <queue>
using namespace std;


int KthSmallestElement(int arr[], int n, int k) {
  // Use a min heap and pop elements till k == 1, whatever is on top is the ans.
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 0; i < n; i++)
    pq.push(arr[i]);
  
  while(k != 1) {
    pq.pop();
    k--;
  }

  return pq.top();
}

int KthLargestElement(int arr[], int n, int k) {
  // Use a max heap and pop elements till k == 1, whatever is on top is the ans.
  priority_queue<int> pq;
  for(int i = 0; i < n; i++)
    pq.push(arr[i]);
  
  while(k != 1) {
    pq.pop();
    k--;
  }

  return pq.top();
}

int main() {

  // int arr[] = {1, 2, 3, 4};
  // int n = 4;
  // int k = 3;

  int arr[] = {5, 7, 8, 12, 2, 9};
  int n = 6;
  int k = 3;
  
  int ans1 = KthSmallestElement(arr, n, k);
  cout << "Kth smallest element: " << ans1 << endl;

  int ans2 = KthLargestElement(arr, n, k);
  cout << "Kth largest element: " << ans2 << endl;

  // Kth smallest element is: 7
  // Kth largest element is: 8
  
}

// approach 3: We try to reduce the space complexity to O(K) by using a maxHeap to find kth smallest element and a minHeap to find Kth largest element.
// the Heap consists of K elements at every stage so thus Space complexity is O(K).
// SC: O(K) TC: O(N logK).

#include <iostream>
#include <queue>
using namespace std;

int getKthSmallestElement(int arr[], int n, int k) {
  priority_queue<int> pq;
  // Processing first k elements
  for(int i = 0; i < k; i++)
      pq.push(arr[i]);

  // Processing remaining elements
  for(int i = k; i < n; i++) {  
    if(arr[i] < pq.top()) {
      pq.pop();
      pq.push(arr[i]);
    }
  }
  return pq.top();
}


int getKthLargestElement(int arr[], int n, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
  // Processing first k elements
  for(int i = 0; i < k; i++)
      pq.push(arr[i]);

  // Processing remaining elements
  for(int i = k; i < n; i++) {   
    if(arr[i] > pq.top()) {
      pq.pop();
      pq.push(arr[i]);
    }
  }
  return pq.top();
}


int main() {
  int arr[] = {5, 7, 8, 12, 2, 9};
  int n = 6;
  int k = 3;
  
  int ans1 = getKthSmallestElement(arr, n, k);
  cout << "Kth smallest element is: " << ans1 << endl;
  
  int ans2 = getKthLargestElement(arr, n, k);
  cout << "Kth largest element is: " << ans2 << endl;
   
}

// Kth smallest element is: 7
// Kth largest element is: 8
