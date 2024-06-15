#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};


void printDLL(Node *head) {
  cout << "Printing DLL : " << endl;
  while (head) {
    cout << head->data << "<->";
    head = head->right;
  }
  cout << endl;
}

void levelwiseprint(Node *root) {
  if (root == NULL)
    return;

  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    Node *front = q.front();
    q.pop();

    if (front == NULL) {
      cout << endl;
      if (!q.empty())
        q.push(NULL);
    } else {
      cout << front->data << " ";
      if (front->left)
        q.push(front->left);
      if (front->right)
        q.push(front->right);
    }
  }
}


Node* convertSortedDLLToBST(Node* &head, int n) {
  // basecase
  if(head == NULL || n <= 0)
      return NULL;

  // L N R
  Node* leftSubtree = convertSortedDLLToBST(head, n/2);

  Node* root = head;  
  root->left = leftSubtree;
  head = head->right; // update head

  Node* rightSubtree = convertSortedDLLToBST(head, n - n/2 - 1); 
  root->right = rightSubtree;

  return root;
}


int main() {

  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);

  first->right = second;
  second->left = first;
  second->right = third;
  third->left = second;

  Node* head = first;
  int sizeOfDLL = 3;

  printDLL(head);


  Node* root = convertSortedDLLToBST(head, sizeOfDLL);
  
  cout << "Level-wise print of the BST:" << endl;
  levelwiseprint(root);
  
}

/*
input DLL: 
10 <-> 20 <-> 30
^ -> head


output BST:
      20
    /    \
  10      30
 /  \    /  \
x    x  x    x

*/


// BRUTEFORCE


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void printDLL(Node *head) {
    cout << "Printing DLL : " << endl;
    while (head) {
        cout << head->data << "<->";
        head = head->right;
    }
    cout << "NULL" << endl;
}

void levelwiseprint(Node *root) {
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node *front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        } else {
            cout << front->data << " ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
}

void collectNodes(Node* head, vector<int>& nodes) {
    while (head) {
        nodes.push_back(head->data);
        head = head->right;
    }
}

Node* sortedArrayToBST(const vector<int>& nodes, int start, int end) {
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    Node* root = new Node(nodes[mid]);

    root->left = sortedArrayToBST(nodes, start, mid - 1);
    root->right = sortedArrayToBST(nodes, mid + 1, end);

    return root;
}

Node* convertSortedDLLToBST(Node* head) {
    vector<int> nodes;
    collectNodes(head, nodes);

    return sortedArrayToBST(nodes, 0, nodes.size() - 1);
}

int main() {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->right = second;
    second->left = first;
    second->right = third;
    third->left = second;

    Node* head = first;

    printDLL(head);

    Node* root = convertSortedDLLToBST(head);

    cout << "Level-wise print of the BST:" << endl;
    levelwiseprint(root);

    return 0;
}

