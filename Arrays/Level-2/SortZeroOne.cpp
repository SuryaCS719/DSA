// 3. Sort 0's and 1's 

void sortZeroOne(int arr[], int n){
    int zeroCount = 0;
    int oneCount = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0)
            zeroCount++;
        if(arr[i]==1)
            oneCount++;
    }   
    // // using for loop
    // int i;
    // for(i=0; i<zeroCount; i++){
    //     arr[i] = 0;
    // }
    // for(int j = i; j<n; j++){
    //     arr[j] = 1;
    // }

    // // using while loop
    int index = 0;
    while(zeroCount--){
        arr[index++] = 0;
        // index++;
        // zeroCount--;
    }
    while(oneCount--){
        arr[index++] = 1;
        // index++;
        // oneCount--;
    }   
}

int main(){
    int arr[] = {0,1,0,0,1};
    int n = 5;
    sortZeroOne(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

}
