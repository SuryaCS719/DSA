#include <iostream>
#include <stack>
using namespace std;

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

int main() {
  stack<int> st;
  st.push(30);
  st.push(30);
  st.push(30);
  int target = 25;
  insertInSortedStack(st, target);

  // print stack
  while (!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }
  return 0;
}