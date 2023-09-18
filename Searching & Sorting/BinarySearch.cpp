// 1. Binary Search

int binarySearch(int arr[], int n, int target){
    int start = 0;
    int end = n - 1;
    // int mid = (start+end) / 2; has been put in the loop.

    while(start <= end){
        
        int mid = (start + end) / 2;

        if(arr[mid] == target)
            return mid;
        
        else if(arr[mid] < target)
            start = mid + 1;
        
        else if(arr[mid] > target)
            end = mid - 1;
        
    }
    return -1;
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int target = 40;
    int n = sizeof(arr) / sizeof(arr[0]);

    int ansIndex = binarySearch(arr, n, target);

    if(ansIndex == -1)
        cout << "ele not found";
    else   
        cout << "ele found at index: " << ansIndex;
}
