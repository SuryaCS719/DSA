class Solution
{
  public:
  
    bool isPossibleSolution(int a[], int n, int k, long long mid){
        long long timeSum = 0;
        int count = 1;
        for(int i = 0; i < n; i++){
            if(a[i] > mid) return false;
            if(timeSum + a[i] > mid){
                count++;
                timeSum = a[i];
                if(count > k) return false;
            }
            else
                timeSum += a[i];
        }
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        // return minimum time
        long long start = 0;
        // long long end = accumulate(arr, arr + n, 0); this wont work cuz accumulate by dft works on int
        long long end = accumulate(arr, arr + n, static_cast<long long>(0));
        // long long end = 0;
        // for(int i = 0; i < n; i++){
        //     end += arr[i];
        // }
        
        long long ans = -1;
        
        while(start <= end){
            long long mid = start + (end - start)/2;
            if(isPossibleSolution(arr, n, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};
