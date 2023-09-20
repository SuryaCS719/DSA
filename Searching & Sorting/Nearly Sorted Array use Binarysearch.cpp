// 11. Binary Search on nearly sorted array

int searchNearlySorted(int arr[], int n, int target){
    int s = 0;
    int e = n - 1;
    
    // s <= e -> even lenght of arrays when start and end point to same element. test case below 
    while(s <= e){
        int mid = s + (e-s)/2;

        if(mid - 1 >= 0 && arr[mid - 1] == target)
            return mid-1;
        
        if(arr[mid] == target)
            return mid;
        
        if(mid + 1 < n && arr[mid + 1] == target)
            return mid+1;
        
        if(target > arr[mid])
            s = mid + 2;
        
        else    
            e = mid - 2;
    }
    return -1;
}


int main(){
    // int arr[] = {20,10,30,50,40,70,60};
    int arr[] = {10,20,30,40,50,60};   // s <= e test case
    int n = sizeof(arr)/sizeof(arr[0]);
    // int target = 60;
    int target = 10; // s <= e test case

    int targetIndex = searchNearlySorted(arr, n, target);
    if(targetIndex == -1){
        cout << "Element not found";
    }
    else{
        cout << "Element found at " << targetIndex;
    }
}
