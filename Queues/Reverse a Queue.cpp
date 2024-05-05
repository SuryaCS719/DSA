// Approach 2 - Using Recursion
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Reversing Using Recursion
void reverseQueue(queue<int> &q) {
  // base case
  if (q.empty())
    return;
  int element = q.front();
  q.pop();
  reverseQueue(q);
  q.push(element);
}

int main() {
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);

  reverseQueue(q);

  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}

// Approach 1 - Using stack

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q) {
  stack<int> st;

  while(!q.empty()) {
    st.push(q.front());
    q.pop();
  }

  while(!st.empty()){
    q.push(st.top());
    st.pop();
  }
  
}

int main() {
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);

  reverseQueue(q);

  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}
