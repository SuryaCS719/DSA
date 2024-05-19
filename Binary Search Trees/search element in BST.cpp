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

bool searchInBST(Node* root, int target) {
  // base case
  if(root == NULL)
    return false;
  
  if(root->data == target)
      return true;

  // bool leftAns = false;
  // bool rightAns = false;
  if(root->data < target)
    // rightAns = searchInBST(root->right, target);
    return searchInBST(root->right, target);
  else
    // leftAns = searchInBST(root->left, target);
    return searchInBST(root->left, target);

  // return leftAns || rightAns;
}

int main() {

  Node* root = NULL;
  createBST(root);
  levelOrderTraversal(root);

  int targetVal;
  cout << "Enter the target value: " << endl;
  cin >> targetVal;

  while(targetVal != -1) {
    bool ans = searchInBST(root, targetVal) ;
    if(ans)
        cout << "found" << endl;
    else  
        cout << "not found" << endl;

    cout << "Enter the target value: " << endl;
    cin >> targetVal;
  }
  

  return 0;
}

/* input: 50 30 60 25 40 70 80 55 -1 

level print
50 
30 60 
20 40 55 70 
25 80 

*/
