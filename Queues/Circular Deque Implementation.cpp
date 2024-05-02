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
      if((front == 0 && rear == size - 1) || (rear = front - 1)){
        cout << "queue overflow" << endl;
        return;
      }
      // check for empty queue
      else if(front == -1 && rear == -1) {
        front++;
        rear++;
        arr[rear] = val;
      }
      // maintain a circular nature
      else if(rear == size - 1 && front != 0) {
        rear = 0;
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
      if((front == 0 && rear == size - 1) || (rear = front - 1)){
        cout << "queue overflow" << endl;
        return;
      }
      // check for emp case for single ele
      else if(front == -1 && rear == -1){
        front++;
        rear++;
        arr[front] = val;
      }
      // maintain a circular nature
      else if(front == 0 && rear != size - 1) {
        front = size - 1;
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
      // maintain a circular nature
      else if(front == size -1) {
        arr[front] = -1;
        front = 0
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
      // maintain a circular nature
      else if(rear == 0) {
        arr[rear] = -1;
        rear = size - 1;
      }
      // normal flow
      else {
        arr[rear] = -1;
        rear--;
      }
    }
};
