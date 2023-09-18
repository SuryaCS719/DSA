// 4.1 Right Shift arrays element by 1

void shiftEleByOne(int arr[], int n){
    int temp = arr[n-1];
    for(int i = n-1; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = 6;
    shiftEleByOne(arr, n);
}

// 4.2 Left Shift arrays element by 1

void shiftEleByOne(int arr[], int n){
    int temp = arr[0];
    for(int i = 0; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = 6;
    shiftEleByOne(arr, n);
}
