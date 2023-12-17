// 5. Find missing element in a sorted array

int missingElement(int arr[], int n){
    int start = 0;
    int end = n-1;
    int currAns = -1;

    while(start <= end){
        int mid = start + (end-start)/2;
        int difference = arr[mid] - mid;

        if(difference == 1){
            start = mid + 1;
        }
        else if(difference == 2){
            currAns = mid; 
            //currAns = arr[mid];
            end = mid - 1;
        }
    }

    if(currAns + 1 == 0)
    // if(currAns == -1)
        return n + 1;

    return currAns + 1;
    // return currAns - 1;
}

int main(){
    int arr[] = {1,2,3,4,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = missingElement(arr, n);
    cout << "Missing element is " << ans;
}
