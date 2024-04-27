#include <iostream>
#include <stack>
using namespace std;

// sort a stack -> O(N^2)

void insertInSortedStack(stack<int> &st, int &target) {
  // base case
  if (st.empty() || target >= st.top()) {
    st.push(target);
    return;
  }

  int temp = st.top();
  st.pop();
  insertInSortedStack(st, target);
  st.push(temp);
}

void sortStack(stack<int> &st) {
  // base case
  if (st.empty())
    return;
  // solve for 1 case
  int element = st.top();
  st.pop();
  sortStack(st);
  insertInSortedStack(st, element); // backtrack
}

int main() {
  stack<int> st;
  st.push(10);
  st.push(5);
  st.push(12);
  st.push(8);
  st.push(9);

  sortStack(st);
  // print stack
  while (!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }
  return 0;
}