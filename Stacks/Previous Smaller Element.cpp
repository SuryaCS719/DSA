#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void previousSmallerElement(int *arr, int size, vector<int> &ans) {
  stack<int> st;
  st.push(-1); // wkt last ele's nextsmallerele is always -1
  // now to traverse from msb to lsb for next smaller element
  // for(int i = size - 1; i >=0; i--) {

  // now to traverse from lsb to msb for previous smaller element
  for(int i = 0; i < size; i++) {
    int curr = arr[i];
    // find the answer for current element
    while(st.top() >= curr)
        st.pop();
    // store the answer
    ans[i] = st.top();
    // push curr into stack cause it might be an another for another element in the left
    st.push(curr);
  }
}

int main() {
  int arr[5] = {8, 4, 6, 2, 3};
  int size = 5;
  vector<int> ans(size);
  previousSmallerElement(arr, size, ans);
  for(auto it : ans)
      cout << it << " ";

  return 0;
}
