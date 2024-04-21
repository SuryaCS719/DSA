#include <iostream>
using namespace std;

//----------------- Class - 2: Learning Node_Creation & Insertion & Deletion of Doubly LL

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node() {
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }

        Node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
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
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Insertions:

void insertAtHead(Node* &head, Node* &tail, int data) {
    // LL is empty
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode; // or head = head->prev;
    }
}


void insertAtTail(Node* &head, Node* &tail, int data) {
    // LL is empty
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode; // or tail = tail->next;
    }
}


void insertAtPosition(Node* &head, Node* &tail, int data, int pos) {
    
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else {
        
        int len = getLength(head);

        if(pos == 1)
            insertAtHead(head, tail, data);

        else if(pos > len)
            insertAtTail(head, tail, data);
        
        else { 
            // insert at middle
            Node* newNode = new Node(data);

            Node* prevNode = NULL;
            Node* currNode = head;

            while(pos != 1) {
                pos--;
                prevNode = currNode;
                currNode = currNode->next;
            }

            prevNode->next = newNode;
            newNode->prev = prevNode;

            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
}


// Deletions:

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
        head = head->next; // or head = temp->next; 
        head->prev = NULL;

        temp->next = NULL;
        delete temp;
    }

    else if(pos == len) {
        // delete tail node
        Node* prevNode = tail->prev;

        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;

        tail = prevNode;
    }

    else {
        // delete node in middle 
        
        Node* prevNode = NULL;
        Node* currNode = head;
        Node* nextNode = head->next; // my version

        while(pos != 1) { // my version
            pos--;
            prevNode = currNode;
            currNode = nextNode;
            nextNode = nextNode->next;
        }

        // Simplier way: we can use standard while loop containing only prevNode and currNode like singly LL
        // and after the while loop ends we use the following:

        // Node* prevNode = NULL; 
        // Node* currNode = head;
        // while(pos != 1){
        //     pos--;
        //     prevNode = currNode;
        //     currNode = currNode->next;
        // }
        // Node* nextNode = currNode->next;

        prevNode->next = nextNode;

        currNode->prev = NULL;

        currNode->next = NULL;

        nextNode->prev = prevNode;
        
        delete currNode;
    }
}


int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    printLL(head);


    // insertAtTail(head, tail, 500);

    // insertAtPosition(head, tail, 650, 3);

    deleteNode(head, tail, 3);
    // deleteNode(head, tail, 1);
    // deleteNode(head, tail, 2);
    // deleteNode(head, tail, 1);
    // cout << "len of LL: " << getLength(head) << endl;
    // deleteNode(head, tail, 1);

    printLL(head);


    return 0;
}