// Permutations of a string ; Backtracking

// Note: passing string as reference thus we use backtracking or else it'll give the wrong ans

#include <iostream>
using namespace std;

void printPermutationRE(string& str, int index){
  if(index >= str.size()){
    cout << str << endl;
    return;
  }

  for(int j = index; j < str.size(); j++){
    swap(str[j], str[index]);
    // RE
    printPermutationRE(str, index + 1);
    // Backtracking
    swap(str[j], str[index]); 
  }
}

int main() {
  string str = "abc";
  printPermutationRE(str, 0);
  return 0;
}
