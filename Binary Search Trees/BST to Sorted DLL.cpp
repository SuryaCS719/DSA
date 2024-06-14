#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

Node* insertIntoBST(Node* root, int data) {
  if(root == NULL) {
    root = new Node(data);
    return root;
  }

  if(data < root->data)
    root->left = insertIntoBST(root->left, data);
  else
    root->right = insertIntoBST(root->right, data);

  return root;
}

void createTree(Node* &root) {
  cout << "Enter data: " << endl;
  int data; 
  cin >> data;

  while(data != -1) {
    root = insertIntoBST(root, data);
    cout << "Enter data: " << endl;
    cin >> data;
  }
}

void levelwiseprint(Node* root) {
  if(root == NULL)
      return;
  
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()) {
    Node* front = q.front();
    q.pop();

    if(front == NULL) {
      cout << endl;
      if(!q.empty())
        q.push(NULL);
    }
    else {
      cout << front->data << " ";
      if(front->left)
        q.push(front->left);
      if(front->right)
        q.push(front->right);
    }
  }
}

void printDLL(Node* head) {
  cout << "Printing DLL : " << endl;
  while(head) {
    cout << head->data << "<->";
    head = head->right;
  }
}

void convertBSTTOSortedDLL(Node* root, Node* &head) {
  if(root == NULL) 
    return;

    // reverse inorder: R N L
    convertBSTTOSortedDLL(root->right, head); // R

    root->right = head;
    if(head != NULL)
      head->left = root;

    head = root; // update head

    convertBSTTOSortedDLL(root->left, head); // L
}

int main() {

  Node* root = NULL;
  createTree(root);

  cout << "Level-wise print of the BST:" << endl; 
  levelwiseprint(root);
    
  Node* head = nullptr;
  convertBSTTOSortedDLL(root, head);
  printDLL(head);
  return 0;
}


/*
given BST:

    40
   /  \
  20   60
 /  \   / \
10  30 50  70

Output: 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> 60 <-> 70

input: 40 20 60 10 30 50 70 -1

*/
