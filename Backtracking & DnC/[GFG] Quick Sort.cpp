class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low >= high)
            return;
        int pivot = high;
        int i = low - 1;
        int j = low;
        
        while(j < pivot){
            if(arr[j] < arr[pivot]){
                i++;
                swap(arr[i], arr[j]);
            }
            j++;
        }
        i++; // after this stmt, i is the right position for the pivot element
        swap(arr[i], arr[pivot]);
        
        quickSort(arr, low, i-1);
        quickSort(arr, i+1, high);
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       // WON'T USE THIS. AS WE ARE IMPLEMENTING IN A DIFFERENT WAY.
    }
};
