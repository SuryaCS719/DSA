// Reversing first K elements in a Queue using Stack
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseFirstKQueue(queue<int> &q, int k) {

  if(k > n || k == 0 || k == 1) return;

  stack<int> st;
  int n = q.size();
  // step 1: push first k elements into stack
  // if we're using while loop store k val
  int m = k;
  while(!q.empty() && m) {
    st.push(q.front());
    q.pop();
    m--;
  }
  
  // if we use for loop then no need to store k value
  // for(int i = 0; i < k; i++) {
  //   st.push(q.front());
  //   q.pop();
  // }
  
  // step 2: push all k elements from stack into queue
  while(!st.empty()) {
    q.push(st.top());
    st.pop();
  }
  // step 3: pop n-k elements from queue and push it into queue again
  for(int i = 0; i < n - k; i++) {
    q.push(q.front());
    q.pop();
  }
}

int main() {
  queue<int> q;
  int k = 3;
  
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);

  reverseFirstKQueue(q, k);

  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}


