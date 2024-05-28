#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


vector<int> findComplement(vector<int> binary)
{
    int n = binary.size();
    // vector<int> twosComp(n); // same size i/p and output
    vector<int> twosComp(n + 1); // output is 1 size bigger than input

    // step 1. flip the bits - 1's comp
    for (int i = n - 1, k = twosComp.size() - 1; i >= 0; i--, k--)
        twosComp[k] = binary[i] == 0 ? 1 : 0;

    // now i have flipped bits in my twosComp array

    // Step 2. add 1 - to get 2's comp
    int carry = 1;
    for (int i = twosComp.size() - 1; i >= 0; i--)
    {
        int sum = twosComp[i] + carry;
        twosComp[i] = sum % 2;
        carry = sum / 2;
        
        if(carry == 0) break; // optimization 1
    }
    if (carry) // used only when output size is bigger than input by 1
        twosComp[0] = carry;

    if(twosComp[0] == 0)
      twosComp.erase(twosComp.begin());

    return twosComp;
}


int main()
{
    // vector<int> binary = {1, 1, 1, 0, 1, 0, 1, 1, 0}; // same size i/p and output
    vector<int> binary = {0, 0, 0};
    vector<int> twosComp = findComplement(binary);
    for (int i = 0; i < twosComp.size(); i++)
        cout << twosComp[i];
    cout << endl;
    return 0;
}
