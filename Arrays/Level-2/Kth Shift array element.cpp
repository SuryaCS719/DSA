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
