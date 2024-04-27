#include <iostream>
#include <stack>
using namespace std;

void getMiddleElementHelper(stack<int> &st, int &pos, int &ans) {
  // base case
  if(pos == 1) {
    cout << "Deleting: " << st.top() << endl;
    st.pop();
    return;
  }
  // solve for 1 case
  pos--;
  int temp = st.top();
  st.pop();
  getMiddleElementHelper(st, pos, ans); 
  st.push(temp); // backtrack
}

int getMiddleElement(stack<int> &st) {
  // check if stack is empty
  if(st.empty())
      return -1;

  int pos = 0;
  int size = st.size();
  // check for odd size stack
  if(size & 1)
      pos = size / 2 + 1;
  else pos = size / 2;

  int ans = -1; 
  getMiddleElementHelper(st, pos, ans);
  return ans;

}

int main() {
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);

  int mid = getMiddleElement(st);
  cout << "Middle element is: " << mid << endl;

  return 0;
}