// 2. Minimum number in an array:

void minNo(int arr[], int n){
    int minimum = INT_MAX;
    for(int i=0; i<n; i++){
        minimum = min(arr[i], minimum);
    }
    cout << "Minimum ele in arr: " << minimum;
}

Maximum number in an array

void maxNo(int arr[], int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>maxi)
            maxi = arr[i];
    }
    cout << "Maximum ele in arr: " << maxi;
}

int main(){
    int arr[] = {20, 4, 15, 2, 6, 8, 11};
    int size = 7;
    // minNo(arr, size); 
    maxNo(arr, size);
}
