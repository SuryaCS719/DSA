void countZeroOne(int arr[], int n){
    int zeroCount = 0;
    int oneCount = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==0)
            zeroCount++;
        else if(arr[i]==1) 
            oneCount++;
    }
    cout << "Zero Count: " << zeroCount << endl;
    cout << "One Count: " << oneCount << endl;
}

int main(){
    int arr[] = {0,0,0,1,1,0,1,0,1,0,1,1,1};
    int size = 13;
    countZeroOne(arr, size); 
}
