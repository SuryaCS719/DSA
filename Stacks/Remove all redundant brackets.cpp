#include <iostream>
#include <stack>
using namespace std;

bool checkRedundant(string &str) {
  stack<char> st;
  for(int i = 0; i < str.length(); i++) {
    char ch = str[i];
    // push the char into stack if its a opening bracket or an operator
    if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        st.push(ch);
    else if(ch == ')') {
      int operatorCount = 0;
      while(!st.empty() && st.top() != '(') {
        int topOfStack = st.top();
        if(topOfStack == '+' || topOfStack == '-' || topOfStack == '*' || topOfStack == '/')
          operatorCount++;
        st.pop();
      }
      // now we reach here only if TOS is an opening bracket
      // not because of stack is empty cuz given str is a valid expression acc to the question
      st.pop(); // popping the opening bracket cuz it's not needed anymore, we got the opCount

      if(operatorCount == 0) return true; // RB exists
    }
  }
  // after traversing all chars if it reaches here, then there exist no RB.
  // cuz if RB existed then it wudve been found out in the above opCount==0 return true stmt
  return false; 
}

int main() {
  string str = "((a+b) * (c+d))";   // RB NOT Present
  // string str = "(((a+b) * (c+d)))"; // // RB Present
  bool ans = checkRedundant(str);
  if(ans) cout << "RB present";
  else cout << "RB NOT present";
}
