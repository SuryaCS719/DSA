// 5. Kth Shift array element 

void rotate(int arr[], int n, int k){

    vector<int> temp(k);

    for(int i = n-k, j=0; i < n; i++, j++){
        temp[j] = arr[i];
    }

    for(int i=n-1; i >= k; i--){
        arr[i] = arr[i - k];
    }

    for(int i=0; i<k; i++){
        arr[i] = temp[i];
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int k = 3;
    int n = 7;
    rotate(arr, n, k);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}






#include <iostream>
#include <vector>
using namespace std;

// shifting elements by k index to right.
void rotateR(int *arr, int n, int k) {
  // store the k elements of the array from the end
  vector<int> temp(k);
  for(int i = n - k, j = 0; i < n; i++, j++)
    temp[j] = arr[i];
  
  for(int i = n - 1; i >= k; i--)
    arr[i] = arr[i - k];
  
  for(int i = 0; i < k; i++)
    arr[i] = temp[i];

}

// shifting elements by k index to left.
// temp = 1,2,3
// output = [4, 5, 6, 7, 1, 2, 3]
void rotateL(int *arr, int n, int k) {
  // store the k elements of the array from the end
  vector<int> temp(k);
  for(int i = 0; i < k; i++)
    temp[i] = arr[i];
  
  for(int i = 0; i <= k; i++) {
    arr[i] = arr[i + k];
  }

  for(int i = n - k, j = 0; i < n; i++, j++)
    arr[i] = temp[j];

}

int main() {
  int arr[] = {1,2,3,4,5,6,7};
  int size = 7;
  int k = 3;
  rotateL(arr, size, k);
  for(auto i : arr)
    cout << i << " ";
  return 0;
}
