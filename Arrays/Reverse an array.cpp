// 3. Reverse an Array:

// 2 Pointer
void reverse(int arr[], int n){
    int low = 0;
    int high = n-1;

    //using for loop as a while loop - alternate
    // for(low=0; low<high; low++, high--){
    //     swap(arr[low++], arr[high--]);
    // }

    // using while loop
    while(low < high){
        swap(arr[low++], arr[high--]);
    }

    // print array
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {20, 4, 15, 2, 6, 8, 11};
    int size = 7;
    reverse(arr, size); 
}

// reverse array using TEMP variable

void reverse(int arr[], int n){
    int low = 0;
    int high = n-1;
    while(low < high){
        int temp = arr[low];
        arr[low++] = arr[high];
        arr[high--] = temp;
        // low++;
        // high--;
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {20, 4, 15, 2, 6, 8, 11};
    int size = 7;
    reverse(arr, size); 
}
