#include <iostream>
using namespace std;

// Binary Search
int binarySearch(int arr[], int start, int end, int x){
  while(start <= end){
    int mid = start + (end - start)/2;
    if(arr[mid] == x)
      return mid;
    else if(arr[mid] > x)
      end = mid - 1;
    else
      start = mid + 1;
  }
  return -1;
}

// Exponential Search
int exponentialSearch(int arr[], int n, int x){
  if(arr[0] == x) return 0;
  int i = 1;
  while(i < n && arr[i] <= x)
    i = i * 2; // expSearch
  return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int main() {
  int arr[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
  int x = 13;
  int n = sizeof(arr)/sizeof(int); // instead of int can also use arr[0]
  int ans = exponentialSearch(arr, n, x);
  cout << ans << endl;
  return 0;
}

/* Application:
1. Used on infite sized arrays
2. better than binary Search if the element to be searched is in the beginning of the array
2. time complexity slightly lesser than binary search as it applies bS on sub   array instead of whole array.
*/
