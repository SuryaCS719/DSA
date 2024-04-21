#include <iostream>
using namespace std;

//----------------- Class - 1: Learning Node_Creation & Insertion & Deletion of Singly LL

class Node {
    public:
        int data;
        Node* next;

        Node() {
            this->data = 0;
            this->next = NULL;
           
        }

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }

        ~Node() { // dtor is called whenever deallocation of memory in heap occurs
            cout << "dtor called for: " << this->data << endl;
        }
};

void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}


// This is called Engineering Approach.

//--------- Insertion(s):

void insertAtHead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}


void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}


void insertAtPosition(Node* &head, Node* &tail, int data, int pos) {
    
    // assuming position value exists from [1, len + 1]
    int len = getLength(head);

    if(pos == 1){
        insertAtHead(head, tail, data);
    }

    else if(pos > len){
        insertAtTail(head, tail, data);
    }

    else{
        // Step 1: to create the data node
        Node* newNode = new Node(data);

        // Step 2: to traverse the LL and find the correct pos
        Node* prev = NULL;
        Node* curr = head;

        while(pos != 1) {
            pos--;
            prev = curr;
            curr = curr->next;
        }
        
        // Step 3: rearrange the links
        prev->next = newNode;
        newNode->next = curr;
        
    }

}




//--------- Deletion(s):

void deleteNode(Node* &head, Node* &tail, int pos) {

    //check if its empty list
    if(head == NULL) {
        cout << "cannot delete, as the LL is empty" << endl;
        return;
    }

    // check if for single element case
    if(head == tail) {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    int len = getLength(head);

    if(pos == 1) {
        // delete head node
        Node* temp = head;
        head = temp->next; // or head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else if(pos == len) {
        // delete tail node

        // step 1 to find prev
        Node* prev = head;
        while(prev->next != tail) {
            prev = prev->next;
        }

        // step 2 remove the links
        prev->next = NULL;

        delete tail;      

        tail = prev;
    }
    else {
        // delete node in the middle of LL

        // step 1 set prev and curr pointers
        Node* prev = NULL;
        Node* curr = head;

        while(pos != 1) {
            prev = curr;
            curr = curr->next;
            pos--;
        }

        // step 2 objective is to delete curr node
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

}


// homework to implement deleteNode using int data parameter instead int pos
// void deleteNode(Node* &head, Node* &tail, int data) // deleting using data instead pos




int main() {

    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;

    Node* head = NULL;
    Node* tail = NULL;


    insertAtHead(head, tail, 20);
    // insertAtHead(head, tail, 15);
    // insertAtHead(head, tail, 10);
    // insertAtHead(head, tail, 5);
    // insertAtTail(head, tail, 25);


    // cout << getLength(head) << endl; 


    printLL(head);

    // insertAtPosition(head, tail, 450, 2);

    deleteNode(head, tail, 1);

    // printLL(head);

    return 0;
}



