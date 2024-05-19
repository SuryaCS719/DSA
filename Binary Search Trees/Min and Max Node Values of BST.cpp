#include <iostream>
#include <climits>
#include <queue>
using namespace std;


class Node {
public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    this->data = val;
    left = NULL;
    right = NULL;
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


void createBST(Node* &root) {
  cout << "Enter data: " << endl;
  int data;
  cin >> data;

  while(data != -1) {
    root = insertIntoBST(root, data);
    cout << "Enter data: " << endl;
    cin >> data;
  }
}

void levelOrderTraversal(Node* root) {
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

int minValueInBST(Node* root) {
  if(root == NULL)
      return INT_MIN;
  
  Node* temp = root;
  while(temp->left != NULL)
    temp = temp->left;
  
  return temp->data;
}

Node* maxValueInBST(Node* root) {
  if(root == NULL)
      return NULL;
  
  while(root->right != NULL)
    root = root->right;

  return root;
}

int main() {

  Node* root = NULL;
  createBST(root);
  levelOrderTraversal(root);

  cout << endl << "Min val: " << minValueInBST(root);

  Node* maxNodeVal = maxValueInBST(root);
  if(maxNodeVal)
    cout << endl << "Max val: " << maxNodeVal->data;
  else
    cout << endl << "No nodes present in BST";

  

  return 0;
}

/* input: 50 30 60 25 40 70 80 55 -1 

level print
50 
30 60 
20 40 55 70 
25 80 

*/
