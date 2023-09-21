// 12. Find the odd occuring element: (Unsorted array)
/* all elements occur even no of times except one element.
all repeated no are in form of pairs and no pair is repeating. i.e 1 number will be repeated twice and will be repeated for only 2 times.
Method 1: XOR -> O(N)
Method 2: Sort and check if there's any no occuring odd times -> O(nlogN)
Method 3: Index Logic -> O(logN)
*/

// Method 3: Index Logic:
int findOddOccuringElement(int arr[], int n){
  int s = 0;
  int e = n-1;
  while(s <= e){
    int mid = s + (e-s)/2;
    // incase of single element 
    if(s == e)
      return s;
    
    //check for mid at odd
    if(mid & 1){
      if(mid - 1 >= 0 && arr[mid] == arr[mid-1])
        s = mid + 1;
      else
        e = mid - 1;
    }
    //check for mid at even
    else{
      if(mid + 1 < n && arr[mid] == arr[mid+1])
        s = mid + 2;
      else  
        e = mid; // here we are reached the right part of the ans or the ans itself.
    }
  }
  return -1; 
}

int main() {
  // int arr[] = {10,10,2,2,3,3,1,5,5,6,6,7,7};
  int arr[] = {10,10,1,2,2,3,3,5,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  int ansIndex = findOddOccuringElement(arr, n);
  cout << arr[ansIndex];
  // cout << ansIndex;
}


// Method 1: using XOR
int findOddOccuringElement(int arr[], int n){
  int ans = 0;
  for(int i=0; i<n; i++)
    ans ^= arr[i];
  return ans;
}

int main() {
  int arr[] = {10,10,2,2,3,3,12,5,5,6,6,7,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  int ans = findOddOccuringElement(arr, n);
  cout << ans << endl;
}

// Method 2: using sort() ; check if theres any no. occuring odd amount of times.



