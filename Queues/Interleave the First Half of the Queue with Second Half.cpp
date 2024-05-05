// Handled the odd length case as well.
// incase of odd length: parition assumed is n/2 + 1 AND n/2 cuz then only interleaving makes sense. 

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Reversing first K elements in a Queue using Recursion
void interleaveQueue(queue<int> &first) {
  queue<int> second;
  int size = first.size();
  // incase if the given queue is odd length
  // then divide in this manner: n/2 + 1 AND n/2
  // so that interleaving makes sense
  // n/2 + 1 AND n/2 divide->ex: 10 20 30 40 50 -> 10 40 20 50 30 (makes sense for interleaving)
  // n/2 and n/2+1 ex: 10 20 30 40 50 -> 10 30 20 40 50 (40 and 50 are together so doesnt make sense)
  if(size & 1) {
    // step 1: push first half of queue onto Second Queue;
    // size / 2 + 1 cuz we want this second q to be bigger
    // there is always a bigger list in case of odd length
    for(int i = 0; i < size / 2 + 1; i++) {
      second.push(first.front());
      first.pop();
    }
    // Step 2: Merge both the halves
    // into the original queue - first
    for(int i = 0; i < size / 2; i++) {
      // push and pop first ele of second queue onto first q.
      first.push(second.front());
      second.pop();
      // now push and pop first ele of first queue onto first q.
      first.push(first.front());
      first.pop();
    }
    // now we do an extra iteration to push the front ele of second in first q and then pop from second.
    first.push(second.front());
    second.pop();
  }

  else {
    // step 1: push first half of queue onto Second Queue;
    for(int i = 0; i < size / 2; i++) {
      second.push(first.front());
      first.pop();
    }
    // Step 2: Merge both the halves
    // into the original queue - first
    for(int i = 0; i < size / 2; i++) {
      // push and pop first ele of second queue onto first q.
      first.push(second.front());
      second.pop();
      // now push and pop first ele of first queue onto first q.
      first.push(first.front());
      first.pop();
    } 
  } 

}

int main() {
  queue<int> q;
  
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  // q.push(60);

  interleaveQueue(q);

  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}
