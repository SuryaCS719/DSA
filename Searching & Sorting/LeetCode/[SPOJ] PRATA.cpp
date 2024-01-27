// mycode:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<int> &arr, int P, int mid){
  int currP_Count = 0; // initial cooked prata count is 0
  int noOfCooks = arr[0];
  for(int i = 1; i < arr.size(); i++){
    int R = arr[i];
    int j = 1;
    int timeTaken = 0;

    while(true){
      if(timeTaken + j * R <= mid){
        currP_Count++;
        timeTaken += j * R;
        j++;  
      }
      else
        break;
    }
    if(currP_Count >= P)
      return true;
  }
  return false;
}

int minTimeToCompleteOrder(vector<int> &arr, int P){
  int start = 0;
  int highestCookRank = *max_element(arr.begin(), arr.end());
  int end = highestCookRank * (P * (P + 1) / 2);
  int ans = -1;
  while(start <= end){
    int mid = start + (end - start)/2;
    if(isPossibleSolution(arr, P, mid)){
      ans = mid;
      end = mid - 1;
    }
    else
      start = mid + 1;
  }
  return ans;
}

int main() {
  int T; cin >> T;
  while(T--){
    int P; cin >> P;
    vector<int> arr;
    int L; cin >> L;
    arr.push_back(L);
    for(int i = 0; i < L; i++){
      int rank; cin >> rank;
      arr.push_back(rank);
    }
    cout << minTimeToCompleteOrder(arr, P) << endl;
  }
  return 0;
}

// CodeHelp code ; input difference slightly
