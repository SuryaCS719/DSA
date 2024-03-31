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

        // pivot == end i.e can use either of them to run the while loop.
        while(j < pivot){ 
            if(arr[j] < arr[pivot]){
                i++;
                swap(arr[i], arr[j]);
            }
            j++;
        }
        i++; 
        // now i is the correct position for pivot element
        swap(arr[i], arr[pivot]);
        
        quickSort(arr, low, i-1);
        quickSort(arr, i+1, high);
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // WON'T USE THIS. AS WE ARE IMPLEMENTING IN A DIFFERENT WAY.
    }
};



