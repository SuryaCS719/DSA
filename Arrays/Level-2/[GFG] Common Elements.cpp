/*
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure.
*/

// Method 1: Using Set data structure ; TC: O(n1+n2+n3) SC: O(n) 
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> ans;
            set<int> set;
            int i=0, j=0, k=0;
            while(i<n1 && j<n2 && k<n3){
                
                if(A[i] == B[j] && B[j] == C[k]){
                    // ans.push_back(A[i]);
                    set.insert(A[i]);
                    i++, j++, k++;
                }
                else if(A[i] < B[j])
                    i++;
                else if(B[j] < C[k])
                    j++;
                // else if (C[k] < A[i])
                else
                    k++;
            }
            for(auto i: set)
                ans.push_back(i);
            return ans;
        }
};

// Method 2: W/out using Set data structure, we need to remove duplicate elements from the sorted array
class Solution
{
    public: 
    
        int removeDuplicates(int arr[] , int n){
            int j = 0;
            int i = 1;
            
            while(i < n){
                if(arr[j] == arr[i]) i++;
                else arr[++j] = arr[i++];
            }
            return j+1;
        }
        
        vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            // To remove duplicate elements from the arr A, B, C
            n1 = removeDuplicates(A, n1);
            n2 = removeDuplicates(B, n2);
            n3 = removeDuplicates(C, n3);
            
            vector<int> ans;
            int i=0, j=0, k=0;
            while(i<n1 && j<n2 && k<n3){
                
                if(A[i] == B[j] && B[j] == C[k]){
                    ans.push_back(A[i]);
                    i++, j++, k++;
                }
                else if(A[i] < B[j])
                    i++;
                else if(B[j] < C[k])
                    j++;
                // else if(C[k] < A[i])
                else
                    k++;
            }
            return ans;
        }
};
