/* 3. Subsequences of a string
Note: Pattern is to include or to exclude characters
2^n where n = length of the string combinations of subsequences are produced.
*/

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
