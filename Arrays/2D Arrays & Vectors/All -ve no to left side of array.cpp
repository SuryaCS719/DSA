// 1.1 Arrange -ve no and +ve no

void arrange(int arr[], int n){
    int j = 0;
    for(int i=0; i<n; i++){
        if(arr[i] < 0){
            swap(arr[i], arr[j]);
            j++;
        }
        // else if(arr[i] >= 0) // Not needed
        //     continue;
    }
}

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {23, -7, 12, -10, -11, 40, 60};
    int n = 7;
    arrange(arr, n);
    printArr(arr, n);
}


// 1.2 Move All -ve number to the left side of an array
// using dutchNationalFlagAlgo TC: O(n) ; SC: O(1) 

void dutchNationalFlagAlgo(int *arr, int n){
    int low=0, high=n-1;
    while(low<high){
        if(arr[low] < 0)
            low++;
        else if(arr[high] > 0)
            high--;
        else    
            swap(arr[low], arr[high]);
    }
}

int main(){
    int arr[] = {0,1,2,-3,4,-5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    // sort(arr, arr + n); method 1 ; TC O(nlogn) ; SC O(n)
    dutchNationalFlagAlgo(arr, n); 

    for(int i = 0; i<n; i++){
        cout << arr[i] << " "; 
    }
}
