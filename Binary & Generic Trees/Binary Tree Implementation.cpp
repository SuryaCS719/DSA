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
    left = NULL;
    right = NULL;
  }
};

Node* createTree() {
  int data;
  cin >> data;

  if(data == -1) 
    return NULL;

  Node* root = new Node(data); // root node
  root->left = createTree(); // left subtree
  root->right = createTree(); // right subtree
  
  return root;
}

void preOrder(Node* root) {
  // base case
  if(root == NULL)
    return;
  // N->L->R
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node* root) {
  // base case
  if(root == NULL)
    return;
  // L->N->R
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void postOrder(Node* root) {
  // base case
  if(root == NULL)
    return;
  // L->R->N
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

void levelOrder(Node* root) {
  queue<Node*> q;
  q.push(root);

  while(!q.empty()) {
    Node* front = q.front();
    q.pop();
    cout << front->data << " ";
    if(front->left != NULL) 
      q.push(front->left);
    if(front->right != NULL) 
      q.push(front->right);
  }
}

int main() {
  
  cout << "enter node val: " << endl;
  Node* root = createTree();
  cout <<"Printing Root Node: " << root->data << endl;

  cout << "Preorder traversal: " << " ";
  preOrder(root);

  cout << endl << "inOrder traversal: " << " ";
  inOrder(root);

  cout << endl << "postOrder traversal: " << " ";
  postOrder(root);

  cout << endl << "levelOrder traversal: " << " ";
  levelOrder(root);

  return 0;
}



// input binary tree used
// 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1   

// output
// enter node val: 
// 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1   
// Printing Root Node: 10
// Preorder traversal:  10 20 40 30 50 60 
// inOrder traversal:  40 20 10 50 30 60 
// postOrder traversal:  40 20 50 60 30 10 
// levelOrder traversal:  10 20 30 40 50 60  
