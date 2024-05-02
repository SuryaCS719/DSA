#include <iostream>
using namespace std;

class Deque {
  public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size) {
      arr = new int[size];
      this->size = size;
      front = -1;
      rear = -1;
    }

    void push_back(int val) {
      // check for overflow
      if(rear == size - 1){
        cout << "queue overflow" << endl;
        return;
      }
      // check for empty queue
      else if(front == -1 && rear == -1) {
        front++;
        rear++;
        arr[rear] = val;
      }
      // normal flow
      else{
        rear++;
        arr[rear] = val;
      }
    }

    void push_front(int val) {
      // check for overflow
      if(front == 0){
        cout << "queue overflow" << endl;
        return;
      }
      // check for emp case for single ele
      else if(front == -1 && rear == -1){
        front++;
        rear++;
        arr[front] = val;
      }
      // normal flow
      else{
        front--;
        arr[front] = val;
      }
    }

    void pop_front() {
      // underflow
      if(front == -1 && rear == -1){
        cout << "queue underflow" << endl;
        return;
      }
      // check for single ele case
      else if(front == rear){
        arr[front] = -1;
        front = -1;
        rear = -1;
      }
      // normal flow
      else{
        arr[front] = -1;
        front++;
      }
    }

    void pop_back() {
      // check for underflow
      if(front == -1 && rear == -1){
        cout << "queue underflow" << endl;
        return;
      }
      // check for single ele
      else if(front == rear) {
        arr[rear] = -1;
        front = -1;
        rear = -1;
      }
      // normal flow
      else {
        arr[rear] = -1;
        rear--;
      }
    }
};


int main() {
  
  return 0;
}
