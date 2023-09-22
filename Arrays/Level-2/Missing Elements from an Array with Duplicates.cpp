// 7. Missing Elements from an Array with Duplicates

// Method 1: Negative Marking Method ; TC: O(N) SC: O(1)
void findMissing(int *arr, int n){
  // visited method
  for(int i = 0; i < n ; i++){
    int index = abs(arr[i]);
    if(arr[index - 1] > 0)
      arr[index - 1] *= -1;
  }
  // Check for positive no
  for(int i=0; i<n; i++){
      if(arr[i] > 0)
        cout << i+1 << " "; // +1 because we take index from 0th but constraint was arr[i]-> [1,N]
    }
}

// Method 2 : Using sort + swap  ; TC O(N) SC: O(1)
void findMissingUsingSort(int arr[], int n){
    int i = 0;
    while(i<n){
        int index = arr[i] - 1;
        if(arr[i] != arr[index])
            swap(arr[i], arr[index]);
        else    
            i++;
    }
    for(int i=0;i<n;i++){
        if(arr[i] != i+1)
            cout << i+1 << " ";
    }
}


int main() {
  int arr[] = {1, 3, 5, 3, 4};
  int n = sizeof(arr)/sizeof(arr[0]);
  findMissing(arr, n); 
  findMissingUsingSort(arr, n); 
  return 0;
}
