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

// Exponential Search aka Doubling Search, Galloping search and Struzik search.
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
1. Used on infite sized arrays or also known as unbounded arrays.
2. better than binary Search if the element to be searched is in the beginning of the array
3. time complexity slightly lesser than binary search as it applies bS on a subarray instead of whole array.
i.e BS TC is: O(logn) whereas ExpS TC is: O(log(2log^m-1)) that is also O(log((2log^M)/2)))
*/

// Continuation Topic: Unbounded binary search uses exponential search.
// Continueation Question: Find the element in an infinite sorted array. (Hint: the array is so big that we cant know what's the end element) therefore traditional binary search fails.

// Method 2 [Optimized]: Exponential Search
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

int infiniteSortedArraySearchUsingExpSearch(int arr[], int x){
    int i = 0;
    int j = 1;
    while(arr[j] <= x){
        i = j;
        j = j * 2;
    }
    return binarySearch(arr, i, j, x);
}


// Method 1: BruteForce
int infiniteSortedArraySearchUsingBruteForce(int arr[], int x){
  int i = 0;
  int ans = -1;
  while(arr[i] <= x){
    if(arr[i] == x)
      return i;
    i++;
  }
  return ans;
}

// Main func()
int main(){
  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29}; 
  int x = 1; 
  int ans = infiniteSortedArraySearchUsingBruteForce(arr, x); // Method 1: BruteForce
  int ans = infiniteSortedArraySearchUsingExpSearch(arr, x); // Method 2 [Optimized]: Exponential Search
  if(ans != -1)
    cout << ans << endl;
  else
    cout << x << " not found" << endl;
  return 0;
}
