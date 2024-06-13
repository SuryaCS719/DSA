#include <iostream>
#include <queue>
#include <limits.h>
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

void levelorderTraversal(Node* root) {
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


class NodeData {
public:
  int size;
  int minVal;
  int maxVal;
  bool isValidBST;

  // Default constructor
  NodeData() {
    size = 0;
    minVal = INT_MAX;
    maxVal = INT_MIN;
    isValidBST = false;
  }

  // Default constructor can be written like this as well
  // NodeData() : size(0), minVal(INT_MAX), maxVal(INT_MIN), isValidBST(false) {}

  // Parameterized constructor
  NodeData(int size, int minVal, int maxVal, bool isValidBST) {
    this->size = size;
    this->minVal = minVal;
    this->maxVal = maxVal;
    this->isValidBST = isValidBST;
  }
};

NodeData findLargestBST(Node*root, int& ans) {
  if(root == NULL)
    return NodeData(0, INT_MAX, INT_MIN, true);

  NodeData leftAns = findLargestBST(root->left, ans); // go left
  NodeData rightAns = findLargestBST(root->right, ans); // go right
 
  /* NodeData currentAns(leftAns.size + rightAns.size + 1, 
                    min(root->data, leftAns.minVal), 
                    max(root->data, rightAns.maxVal), 
                    false); // false cuz default assumption, currAns is not a valid BST till proven. */
 
  // now process the current node
  NodeData currentAns;

  currentAns.size = leftAns.size + rightAns.size + 1;
  currentAns.minVal = min(root->data, leftAns.minVal);
  currentAns.maxVal = max(root->data, rightAns.maxVal);

  // Conditions to check if the current subtree rooted at 'root' is a valid BST:
  // 1. Both the left and right subtrees are valid BSTs.
  // 2. The current node's value is greater than the maximum value in the left subtree (leftAns.maxVal).
  // 3. The current node's value is less than the minimum value in the right subtree (rightAns.minVal).
  // If all conditions are true, then the currentAns is a valid BST and update 'ans' with the size of this BST.

  if(leftAns.isValidBST && rightAns.isValidBST && (root->data > leftAns.maxVal && root->data < rightAns.minVal))
    currentAns.isValidBST = true;
  else currentAns.isValidBST = false; // optional else stmt not needed cuz dft curAns.isValidBST is false anyway.

  if(currentAns.isValidBST)
    ans = max(ans, currentAns.size);
  
  return currentAns;
}

int main() {

  cout << "enter node val: " << endl;
  Node* root = createTree();

  cout << "Printing the tree: " << endl;
  levelorderTraversal(root);

  int ans = 0;
  findLargestBST(root, ans);
  cout << "largest BST's size: " << ans << endl;


  return 0;
}
