// 1. Find unique element 

int uniqueEle(int arr[], int size){
    int ans = 0;
    for(int i=0; i<size; i++){
        ans = ans ^ arr[i];
        // cout << i << "th answer: " << ans << endl;
    }
    return ans;
}

int main(){
    int arr[5] = {1, 2, 2, 1, 10};
    int size = 5;
    int ans = uniqueEle(arr, size);
    cout << "final ans: " << ans;
}
