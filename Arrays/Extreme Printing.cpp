// 4. Extreme Printing

void reverse(int arr[], int n){
    int low = 0;
    int high = n-1;
    while(low <= high){
        if(low == high){
            cout << arr[low];
            break;
        }
        cout << arr[low++] << " ";
        cout << arr[high--] << " ";
        // low++;high--;
    }
}

int main(){
    int arr[] = {20, 4, 15, 2, 6, 8, 11};
    int size = 7;
    reverse(arr, size); 
}
