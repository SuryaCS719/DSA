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
