#include <iostream>
using namespace std;

class Stack {
    public:
        int* arr;
        int size;
        int top;

        Stack(int size){
            arr = new int[size];
            this->size = size;
            this->top = -1;
        }

        void push(int data){
            // check for stack overflow 
            if(top == size - 1){
                cout << "Stack overflow" << endl;
                return;
            }
            else{
                top++;
                arr[top] = data;
            }
        }

        void pop(){
            // check for stack underflow
            if(top == -1){
                cout << "Stack underflow" << endl;
                return;
            }
            // optional:  arr[top] = 0;
            else top--;
        }

        bool isEmpty(){
            if(top == -1) return true;
            return false;
        }

        int getTop(){
            // check for stack underflow
            if(top == -1){
                cout << "Stack is empty -> ";
                return -1;
            }
            else return arr[top]; // to get top ele val
        }

        int getSize(){
            return top + 1;
        }

        void print(){
            cout << "Top: " << top << endl;
            cout << "Top element: " << getTop() << endl;
            cout << "Stack: ";
            for(int i = 0; i < getSize(); i++)
                cout << arr[i] << " ";
            cout << endl << endl;
        }
};


int main() {

    // creation (static)
    Stack st(3);
    // push
    st.push(10);
    // st.print();

    st.push(20);
    // st.print();

    st.push(30);
    // st.print();

    // st.push(40); // stack overflow

    // cout << st.getSize();
    
    // cout << st.getTop();

    // st.pop();
    // st.print();

    // st.pop();
    // st.print();

    // st.pop();
    // st.print();



    // st.pop();
    // st.pop();
    // st.pop();
    // if(st.isEmpty())
    //     cout << "stack is empty";
    // else cout << "stack is not empty";

}