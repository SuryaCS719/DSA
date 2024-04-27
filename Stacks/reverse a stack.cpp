#include <iostream>
#include <stack>
using namespace std;

// Approach 2: using recursion to reverse a stack -> O(N^2)

#include <iostream>
#include <stack>
using namespace std;

// Approach 2: using recursion to reverse a stack -> O(N^2)

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

void reverseStack(stack<int> &st) {
  // base case
  if (st.empty())
    return;
  // solve for 1 case
  int element = st.top();
  st.pop();
  reverseStack(st);

  // At this point, insert the element at the bottom of the stack
  insertAtBottom(st, element); // backtrack
}

int main() {
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);

  reverseStack(st);

  while (!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }

  return 0;
}


// Approach 1 easy: insert elements to new stack and print new stack

int main() {
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  stack<int> st_rev;

  // pushing old stack element to new stack
  while (!st.empty()) {
    st_rev.push(st.top());
    st.pop();
  }
  // print rev stack
  while (!st_rev.empty()) {
    cout << st_rev.top() << endl;
    st_rev.pop();
  }
}
