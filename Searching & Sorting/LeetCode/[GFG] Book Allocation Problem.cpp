// GFG: Allocate minimum number of pages

class Solution 
{
    public:
    
    bool isPossibleSolution(int arr[], int n, int m, int sol){
        int pageSum = 0;
        int allocationsPerStudent = 1;
        for(int i = 0; i < n; i++){
            if(arr[i] > sol)
                return false;
            if(pageSum + arr[i] > sol){
                allocationsPerStudent++;
                pageSum = arr[i];
                if(allocationsPerStudent > m)
                    return false;
            }
            else
                pageSum += arr[i];
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //Using binary search we can define the search space
        int ans = -1;
        if(M > N) return ans; // since each student must be allocated atleast 1 book
        int start = 0;
        int end = accumulate(A, A+N, 0); // (startAddr, endAddr, sumStartPoint)
        
        while(start <= end){
            int mid = start + ((end-start) >> 1);
            if(isPossibleSolution(A, N, M, mid)){
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};
