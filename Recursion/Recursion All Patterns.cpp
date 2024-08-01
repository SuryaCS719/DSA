
// print subseq includ exclude recv
void subseq(int i, int *arr, int n, vector<int> &ans) {
  if(i == n) {
    cout << "-> ";
    for(auto it : ans)
      cout << it << " ";
    cout << endl;
    return;
  } 

  // include
  ans.push_back(arr[i]);
  subseq(i + 1, arr, n, ans);
  ans.pop_back();

  // exclude
  subseq(i + 1, arr, n, ans);
  
}

int main() {
  int arr[] = {3, 2, 1};
  int n = 3;
  vector<int> ans;
  subseq(0, arr, n, ans);
  return 0;
}

// -------------------------------------------------------------------------------------
// print only subseq with sum == k

void subseq(int i, int *arr, int n, vector<int> &ans, int sum, int s) {
  if(i == n) {
    if(s == sum) {
      cout << "-> ";
      for(auto it : ans)
        cout << it << " ";
      cout << endl;
    }
    return;
  }

  // include
  ans.push_back(arr[i]);
  s += arr[i];
  subseq(i + 1, arr, n, ans, sum, s);
  ans.pop_back();
  s -= arr[i];

  // exclude
  subseq(i + 1, arr, n, ans, sum, s);
  
}

int main() {
  int arr[] = {3, 2, 1};
  int n = 3;
  vector<int> ans;
  subseq(0, arr, n, ans);
  return 0;
}


// -------------------------------------------------------------------------------------

//print only one subseq when subseq s == sum, avoids future recv calls

bool subseq(int i, int *arr, int n, vector<int> &ans, int sum, int s) {
  if(i == n) {
    if(s == sum) {
      cout << "-> ";
      for(auto it : ans)
        cout << it << " ";
      cout << endl;
      return true;
    }
    return false;
  }

  // include
  ans.push_back(arr[i]);
  s += arr[i];

  if(subseq(i + 1, arr, n, ans, sum, s))
    return true;


  ans.pop_back();
  s -= arr[i];

  // exclude
  if(subseq(i + 1, arr, n, ans, sum, s))
    return true;
  
  return false;
}

int main() {
  int arr[] = {1, 2, 1};
  int n = 3;
  int sum = 2;
  vector<int> ans;
  int s = 0;
  subseq(0, arr, n, ans, sum, s);
  return 0;
}

// -------------------------------------------------------------------------------------

//count only subseq when subseq's s == sum

int subseq(int i, int *arr, int n, vector<int> &ans, int sum, int s) {
  if(i == n) {
    if(s == sum)
      return 1;
    return 0;
  }

  // include
  s += arr[i];
  int left = subseq(i + 1, arr, n, ans, sum, s);
  s -= arr[i];

  // exclude
  int right = subseq(i + 1, arr, n, ans, sum, s);

  return left + right;
}

int main() {
  int arr[] = {1, 2, 1};
  int n = 3;
  int sum = 2;
  vector<int> ans;
  int s = 0;
  cout << subseq(0, arr, n, ans, sum, s);
  return 0;
}
