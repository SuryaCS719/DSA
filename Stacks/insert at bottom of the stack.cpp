#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int &target) {
  // base case
  if (st.empty()) {
    st.push(target);
    return;
  }
  // solve for 1 case
  int temp = st.top();
  st.pop();
  insertAtBottom(st, target);
  st.push(temp); // backtrack
}

int main() {
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  int target = 400;
  insertAtBottom(st, target);
  // print stack
  while (!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }
  return 0;
}