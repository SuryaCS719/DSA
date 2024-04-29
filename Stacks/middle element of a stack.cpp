// Approach 1: Using system stack via recursion

// Using VOID type of function
#include <iostream>
#include <stack>
using namespace std;

void getMiddleElementHelper(stack<int> &st, int &pos, int &ans) {
  // base case
  if(pos == 1) {
    ans = st.top();
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


// Using INT type of function
#include <iostream>
#include <stack>
using namespace std;

int getMiddleElementHelper(stack<int> &st, int &pos) {
  // base case
  if(pos == 1) {
    return st.top();
  }
  // solve for 1 case
  pos--;
  int temp = st.top();
  st.pop();
  int result = getMiddleElementHelper(st, pos); 
  st.push(temp); // backtrack
  return result;
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

  return getMiddleElementHelper(st, pos);

}

int main() {
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);
  st.push(60);

  int mid = getMiddleElement(st);
  cout << "Middle element is: " << mid << endl;

  return 0;
}




// Approach 2: Using user defined stack 

#include <iostream>
#include <stack>
using namespace std;

int getMiddleElement(stack<int> &st) {
  stack<int> st2;
  int pos = 0;
  int size = st.size();
  // check for odd or even sized stack
  if(size & 1)
      pos = size / 2 + 1;
  else pos = size / 2;

  while(pos > 1) {
    pos--;
    int TOS_st = st.top();
    st.pop();
    st2.push(TOS_st);
  }
  // atp pos == 1 i.e. TOS of st is the middle element 
  int ans = st.top();
  
  // now inserting the popped elements from st to st2 back again
  while(!st2.empty()) {
    // int TOS_st2 = st2.top();
    st.push(st2.top());
    st2.pop();
  }

  return ans;
}

int main() {
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);
  // st.push(60);

  if(st.empty()){
    cout << "stack underflow";
    return 0;
  }

  int mid = getMiddleElement(st);
  cout << "Middle element is: " << mid << endl;
  
  return 0;
}


