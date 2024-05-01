#include <iostream>
using namespace std;

class Queue {
public:
  int *arr;
  int size;
  int front;
  int rear;

  Queue(int size) {
    arr = new int[size];
    this->size = size;
    front = -1;
    rear = -1;
  }

  void push(int val) {
    // check if queue is full
    if(rear == size - 1) {
      cout << "Queue overflow" << endl;
      return;
    }  
    // now check for queue empty case
    else if(front == -1 && rear == -1) {
      front++;
      rear++;
      arr[rear] = val;
    }
    else {
      rear++;
      arr[rear] = val;
    }
    
  }

  void pop() {
    // check for queue empty case
    if(front == -1 && rear == -1) {
      cout << "Queue underflow" << endl;
      return;
    }
    // now check for queue having only one element
    else if(front == rear){
      arr[front] = -1;
      front = -1;  
      rear = -1;
    }
    else {
      arr[front] = -1;
      front++;
    }

  }

  bool isEmpty() {
    if(front == -1 && rear == -1)
      return true;
    return false;
  }

  int getSize() {
    if(front == -1 && rear == -1)
      return 0;   // or rear - front;
    return rear - front + 1;
  }

  int getFront() {
    // check if front is valid or not
    if(front == -1) {
      cout << "no element in the queue therefore no front" << endl;
      return -1;
    }
    return arr[front];
  }

  int getRear() {
    if(rear == size) {
      cout << "rear is out of bound" << endl;
      return -1;
    }
    return arr[rear];
  }

  void print() {
    cout << "Queue: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
  }

};


int main() {
  Queue q(5);
  q.print();

  q.push(10);
  q.print();

  q.push(20);
  q.print();

  q.push(30);
  q.print();

  q.push(40);
  q.print();

  q.push(50);
  q.print();

  cout << "size: " << q.getSize() << endl;

  cout << "front: " << q.getFront() << endl;

  cout << "rear: " << q.getRear() << endl;
  
  q.pop();
  q.print();
  cout << "size: " << q.getSize() << endl;

  // q.push(100); // standard behaviour for queues, solution -> circular queue

  q.pop();
  q.pop();
  q.pop();
  q.print();
  cout << "front: " << q.getFront() << endl;
  cout << "rear: " << q.getRear() << endl;

  // q.pop();
  // q.print();
  // cout << "size: " << q.getSize() << endl;
  
}
