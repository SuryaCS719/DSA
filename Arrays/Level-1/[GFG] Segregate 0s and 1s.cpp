// using if else 
class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        // code here
        int l = 0;
        int h = n - 1;
        while(l < h){
            if(arr[l] == 0)
                l++;
            else if(arr[h] == 1)
                h--;
            else
                swap(arr[l++], arr[h--]);
        }
    }
};


// using while loop
class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        // code here
        int l = 0;
        int h = n - 1;
        while(l < h){
            while(arr[l] == 0 && l < h)
                l++;
            while(arr[h] == 1 && l < h)
                h--;
            swap(arr[l++], arr[h--]);
        }
    }
};
