/* Note: There can be 2 different sizes of the output.

case 1: 
if output size is same as input then no additional carry is attached in front of the vector.

case 2: if carry exists at the end then it needs to be attached to the 0th index of vector.
i.e. if input size is n then output size will be n + 1; */

#include <iostream>
#include <vector>
using namespace std;

vector<int> find2sComplement(vector<int>& binary) {
  int n = binary.size();
  vector<int> twosComplement(n + 1);
  int m = twosComplement.size();

  // step 1. flip the bits - 1's comp
  for (int i = n - 1, k = m - 1; i >= 0; i--, k--)
    twosComplement[k] = binary[i] == 0 ? 1 : 0;
  
  // At this point i have flipped bits in my twosComplement array

  // Step 2. add 1 in twosComplement array- to get 2's comp ans
  int carry = 1;
  for(int i = m - 1; i >= 0; i--) {
    int sum = twosComplement[i] + carry;
    twosComplement[i] = sum % 2;
    carry = sum / 2;

    if(carry == 0) break; // optimization 1: no need to change anything
  }

  // now if carry exists 
  if (carry)
    twosComplement[0] = carry;
  
  // if carry does not exist then erase the 0th index of twosComplement array
  if(twosComplement[0] == 0)
      twosComplement.erase(twosComplement.begin());
  
  return twosComplement;
}


int main() {
  vector<int> binary = {1, 1, 1, 0, 1, 0, 1, 1, 0};  // case 1
  vector<int> binary = {0, 0, 0}; // case 2
  vector<int> ans = find2sComplement(binary);
  for(auto i : ans)
    cout << i;
  return 0;
}

