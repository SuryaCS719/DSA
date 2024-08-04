/* 3. Subsequences of a string using recursion:
Note: Pattern is to include or to exclude characters
2^n where n = length of the string combinations of subsequences are produced.
*/
// striver:
// print subseq includ exclude recv
void subseq(int i, string str, int n, vector<string> &ans) {
  if(i == n) {
    cout << "-> ";
    for(auto it : ans)
      cout << it << " ";
    cout << endl;
    return;
  } 

  // include
  ans.push_back(string(1, str[i])); 
  subseq(i + 1, str, n, ans);
  ans.pop_back();

  // exclude
  subseq(i + 1, str, n, ans);
  
}

int main() {
  string str = "abc";
  int n = 3;
  vector<string> ans;
  subseq(0, str, n, ans);
  return 0;
}


// METHOD - 1

void findSubsequences(string str, string output, int i){
  if(i >= str.length()){
    cout << "->" << output << endl;
    return;
  }
  // exclude current character
  findSubsequences(str, output, i+1);
  // include current character
  output.push_back(str[i]);
  findSubsequences(str, output, i+1);
}

// Verion 2: include first then exclude
void findSubsequencesV2(string str, string output, int i){
  if(i >= str.length()){
    cout << "->" << output << endl;
    return;
  }
  // include current character
  output.push_back(str[i]);
  findSubsequencesV2(str, output, i+1);
  // exclude current character
  output.pop_back();
  findSubsequencesV2(str, output, i+1);
}


int main(){
  string str = "abc";
  findSubsequences(str, "", 0);
  findSubsequencesV2(str, "", 0);
}


// 7. Homework: Subsequences of a string using bit masking. // TC: 2^n * n -> O(2^n)

// METHOD - 2

#include <iostream>
#include <cmath>
using namespace std;

void subSequence(string& s){
  int noOfSubsequences = pow(2, s.size());
  for(int n = 0; n < noOfSubsequences; n++) {
    string output;
    int num = n; // convert num to binary
    int i = 0;
    while(num){
      int bit = num & 1;
      if(bit) // if bit == 1
        output.push_back(s[i]);
      i++;
      num >>= 1;
    }
    cout << output << endl;
  }
}

int main() {
  string s = "abc";
  subSequence(s);
  return 0;
}
