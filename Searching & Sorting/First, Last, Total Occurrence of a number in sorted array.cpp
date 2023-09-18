// 2.1 Find first occurence of a no. in a sorted array

int firstOccurence(int arr[], int n, int target){
    int start = 0; 
    int end = n-1; 
    int ans = -1;

    while(start <= end){
        
        // Best practice: int mid = start + (end-start) / 2;
        int mid = (start + end)/2;

        if(arr[mid] < target)
            start = mid+1;
        else if(arr[mid] > target)
            end = mid - 1;

        else if(arr[mid] == target){
            ans = mid;
            end = mid - 1; 
        }
    }
    return ans;
}

int main(){
    int arr[] = {10, 20, 30, 30, 30, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 30;
    int ans = firstOccurence(arr, n, target);

    if(ans==-1)
        cout << "ele not found";
    else
        cout << "first occurence of " << target << " is at " << ans; 
}

// 2.2 Find last occurence of a no. in a sorted array

int lastOccurence(int arr[], int n, int target){
    int start = 0; 
    int end = n-1; 
    int ans = -1;

    while(start <= end){
        
        int mid = start + (end - start) / 2;

        if(arr[mid] < target)
            start = mid+1;
        else if(arr[mid] > target)
            end = mid - 1;

        else if(arr[mid] == target){
            ans = mid;
            start = mid + 1; // Only change
        }
    }
    return ans;
}

int main(){
    int arr[] = {10, 20, 30, 30, 30, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 30;
    int ans = lastOccurence(arr, n, target);

    if(ans==-1)
        cout << "ele not found";
    else
        cout << "last occurence of " << target << " is at " << ans; 
}



// 2.3 Find total occurence of a no. in a sorted array

int totalOccurence(int arr[], int n, int target){
    int first = firstOccurence(arr, n, target);
    int last = lastOccurence(arr, n, target);

    // Incase of target is not present
    if(first == -1 && last == -1) // simply can use first == -1
        return -1;
    
    int totalOccurence = last - first + 1;
    return totalOccurence;
}

int main(){
    int arr[] = {10, 20, 30, 30, 30, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 30;
    int ans = totalOccurence(arr, n, target);

    if(ans==-1)
        cout << "ele not found";
    else
        cout << "total occurence of " << target << " is at " << ans; 
}
