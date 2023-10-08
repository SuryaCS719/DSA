#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> v = {10,20,20,20,30,50};
  auto it = lower_bound(v.begin(), v.end(), 20); // fetches the element that is being searched
  cout << *it << endl; // it stores the address which we cannot print but to prin the value stored in the addr use *
  cout << "Lowerbound index of 20: " << it - v.begin() << endl;  // to get index of the searched element
  auto it2 = upper_bound(v.begin(), v.end(), 20); // fetches the element next to the element that is being searched
  cout << *it2 << endl; // prints the element next to the searched element
  cout << "Upperbound index of 20: " << it2 - v.begin() - 1 << endl; // thus we use -1 to get the actual upperbound

  // upperbound intuition is weird but atleast this why incase if we need to find total occurences we usually do 
  // last - first - 1; whereas here we can simply do last - first to get the total count.
  auto first = it - v.begin();
  auto last = it2 - v.begin();
  cout << "Total occurences of 20: " << last - first << endl;
  //Can write it this way as well.
  cout << "Total occurences of 20: " << (it2 - v.begin()) - (it - v.begin()) << endl;
  return 0;
}


/* Output:

20
Lowerbound index of 20: 1
30
Upperbound index of 20: 3
Total occurences of 20: 3
Total occurences of 20: 3
*/
