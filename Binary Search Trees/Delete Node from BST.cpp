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

Node* maxValueBST(Node* root) {
  if(root == NULL) return NULL;

  while(root->right != NULL) {
    root = root->right;
  }
  return root;
}

Node* deleteNodeBST(Node* root, int target) {
  if(root == NULL)
      return NULL;

  if(root->data == target) {
    // delete the node -> 4 cases
    // 1. leaf node
    if(root->left == NULL && root->right == NULL) {
      delete root;
      return NULL;
    }
    // 2. left non null & right null
    else if(root->left != NULL && root->right == NULL) {
      Node* childSubTree = root->left;
      delete root;
      return childSubTree;
    }
    // 3. right non null & left null
    else if(root->left == NULL && root->right != NULL) {
      Node* childSubTree = root->right;
      delete root;
      return childSubTree;
    }
    // 4. both non null
    else {
      // i. get max value from left subtree
      Node* maxNodeValLeftSubTree = maxValueBST(root->left);
      // ii. replace the root data val with max node val
      root->data = maxNodeValLeftSubTree->data;
      // iii. delele the max node val from left subtree
      // and also attach the updated left subtree structure to root's left.
      root->left = deleteNodeBST(root->left, maxNodeValLeftSubTree->data);
      // iv. return the root
      return root;
    }
    
  }
  else if(root->data < target)
    root->right = deleteNodeBST(root->right, target);
  else
    root->left = deleteNodeBST(root->left, target);

  return root;
}



int main() {

  Node* root = NULL;
  createBST(root);
  levelOrderTraversal(root);

  int target; 
  cout << "Enter val of target: " << endl;
  cin >> target;

  while(target != -1) {
    // deleteNodeBST(root, target); -> this works too
    root = deleteNodeBST(root, target); // more clarity.
    cout << "Printing BST after deletion" << endl;
    levelOrderTraversal(root);

    cout << endl << "Enter val of target: " << endl;
    cin >> target; 
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
