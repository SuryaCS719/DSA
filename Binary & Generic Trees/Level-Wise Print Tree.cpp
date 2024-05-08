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

// Runs the while loop till size > 1
void levelOrderLevelWisePrint(Node* root) {
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  // q.size > 1 cuz last NULL will exist
  while(q.size() > 1) { // modify 1
    Node* front = q.front();
    q.pop();
    
    if(front == NULL) { // non valid case
      cout << endl;
      q.push(NULL); // modify 2
    }
    else { // valid case
      cout << front->data << " ";
      if(front->left != NULL) 
        q.push(front->left);
      if(front->right != NULL) 
        q.push(front->right);
    }
  }
}

// Runs the while loop till empty
void levelOrderLevelWisePrint2(Node* root) {
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  // q.size > 1 cuz last NULL will exist
  while(!q.empty()) { // change 1
    Node* front = q.front();
    q.pop();

    if(front == NULL) { // non valid case
      cout << endl;
      if(!q.empty()) // change 2
        q.push(NULL);
    }
    else { // valid case
      cout << front->data << " ";
      if(front->left != NULL) 
        q.push(front->left);
      if(front->right != NULL) 
        q.push(front->right);
    }
  }
}

int main() {
  
  cout << "enter node val: " << endl;
  Node* root = createTree();
  cout <<"Printing Root Node: " << root->data << endl;


  cout << endl << "levelOrder traversal: " << " ";
  levelOrder(root);

  cout << endl << "Print 1 of levelOrder traversal in Level-Wise Manner: " << endl;
  levelOrderLevelWisePrint(root);

  cout << endl << "Print 2 of levelOrder traversal in Level-Wise Manner: " << endl;
  levelOrderLevelWisePrint2(root);


  return 0;
}



// input binary tree used
// 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1   
