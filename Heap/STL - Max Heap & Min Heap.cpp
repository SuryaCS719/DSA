#include <iostream>
#include <queue>
using namespace std;

// Using STL to create Max Heap.

int main() {
  priority_queue<int> pq;
  // insertion into pq
  pq.push(10);
  pq.push(20);
  pq.push(40);

  // max element in max heap is on top
  cout << "Max element in max heap: " << pq.top() << endl;

  // deletion in heap can be done only root such as everything else.
  pq.pop();
  cout << "Max element in max heap: " << pq.top() << endl;

  cout << "Size: " << pq.size() << endl;

  if(pq.empty())
    cout << "empty" << endl;
  else
    cout << "non empty" << endl;

  return 0;
}

/* Output:
Max element in max heap: 40
Max element in max heap: 20
Size: 2
non empty
*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Using STL to create Min Heap.

int main() {
  // Define a min heap priority queue
  priority_queue<int, vector<int>, greater<int>> pq;
  // insertion into pq
  pq.push(40);
  pq.push(20);
  pq.push(10);

  // max element in min heap is on top
  cout << "min element in min heap: " << pq.top() << endl;

  // deletion in heap can be done only root such as everything else.
  pq.pop();
  cout << "Min element in min heap: " << pq.top() << endl;

  cout << "Size: " << pq.size() << endl;

  if(pq.empty())
    cout << "empty" << endl;
  else
    cout << "non empty" << endl;

  return 0;
}


/*Output: 
min element in min heap: 10
Min element in min heap: 20
Size: 2
non empty
*/
