// Method 2: Hashing ; TC: O(n) SC: O(n) -> n entries in the hash table
class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        unordered_map<int, int> hash;
        // the value of hash is 0 by default
        for(int i=0; i<n; i++)
            hash[arr[i]]++;
            
        for(int i=0; i<n; i++){
            if(hash[arr[i]] > 1)
                return i+1;
        }
        return -1;
    }
};

// HW: Make your own Hash table 

// Method 1: TC: O(n^2) SC: O(1)
class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i] == arr[j])
                    return i+1;
            }
        }
        return -1;
    }
};
