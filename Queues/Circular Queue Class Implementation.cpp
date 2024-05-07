#include <iostream>
using namespace std;

class CQueue {
public:
  int *arr;
  int size;
  int front;
  int rear;

  CQueue(int size) {
    arr = new int[size];
    this->size = size;
    front = -1;
    rear = -1;
  }

  ~CQueue() {
    delete[] arr; // Deallocate memory
   }

  void push(int val){
    // check for overflow
    if((front == 0 && rear == size - 1) || (rear == front - 1)){
      // can use mod: (rear + 1) % size == front) to check if queue is full
      // instead of rear = front - 1; but avoid mod (exp op)
      cout << "Queue Overflow" << endl;
      return;
    }
    // check for empty queue then it's inserting first ele
    else if(front == -1 && rear == -1) {
      front++;
      rear++;
      arr[front] = val;
    }
    // maintain the circular nature
    else if(rear == size - 1 && front != 0){
      rear = 0;
      arr[rear] = val;
    }
    // normal flow
    else {
      rear++;
      arr[rear] = val;
    }
  }

  void pop() {
    // check for underflow
    if(front == -1 && rear == -1) {
      cout << "Queue Underflow" << endl;
      return;
    }
    // check for single element
    else if(front == rear) {
      arr[front] = -1;
      front = -1;
      rear = -1;
    }
    // maintain circular nature
    else if(front == size - 1) {
      arr[front] = -1;
      front = 0;
    }
    // normal flow
    else {
      arr[front] = -1;
      front++;
    }
  }

  void print() {
    cout << "Front: " << front << " Rear: " << rear << endl;
    cout << "C Queue: ";
    for(int i = 0; i < size; i++)
      cout << arr[i] << " ";
    cout << endl;
  }

};

int main() {

  CQueue cq(5);
  cq.print();








  return 0;
}
