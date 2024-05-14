#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

TreeNode* createTree() {
  cout << "Enter the val for root: " << endl;
  int val;
  cin >> val;
  if(val == -1)  
    return NULL;
  
  TreeNode* root = new TreeNode(val);
  cout << "Enter val of left of " << val << endl;
  root->left = createTree();
  cout << "Enter val of right of " << val << endl;
  root->right = createTree();

  return root;
}

void levelwiseTraversal(TreeNode* root) {
  
  queue<TreeNode*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()) {
    TreeNode* front = q.front();
    q.pop();

    if(front == NULL) {
      cout << endl;
      if(!q.empty()) {
        q.push(NULL);
      }
    }
    else {
      cout << front->val << " "; 
      if(front->left != NULL)
          q.push(front->left);
      if(front->right != NULL)
          q.push(front->right);
        
    }
  }
}

void printLeftBoundary(TreeNode* root) {
  if(root == NULL) return;
  // upon encountering leaf node we return
  if(root->left == NULL && root->right == NULL) return;

  cout << root->val << " ";
  //below is imp condition to traverse either left or right.
  if(root->left != NULL) 
    printLeftBoundary(root->left);
  else 
    printLeftBoundary(root->right);
}

void printLeafBoundary(TreeNode* root) {
  // traverse the entire tree from left to right
  if(root == NULL) return;
  // leaf node
  if(root->left == NULL && root->right == NULL)
    cout << root->val << " ";
  // print all the leaf nodes of left and right
  printLeafBoundary(root->left);
  printLeafBoundary(root->right);
}

void printRightBoundary(TreeNode* root) {
  if(root == NULL) return;
  // upon encountering leaf node we return
  if(root->left == NULL && root->right == NULL) return;
  //below is imp condition to traverse either left or right.
  if(root->right != NULL) 
    printRightBoundary(root->right);
  else 
    printRightBoundary(root->left);
  
  cout << root->val << " ";
}

void boundaryTraversal(TreeNode* root) {
  if(root == NULL) return;
  printLeftBoundary(root);
  printLeafBoundary(root);
  // printRightBoundary(root); //-> prints root val twice.

  // without this below condition the root prints twice
  // once at the start and at the end
  // thus if root's right exist then we traverse from it.
  // else if root's right doesn't exist then
  // we traverse from root's left.
  if(root->right != NULL)
    printRightBoundary(root->right);
  else 
    printRightBoundary(root->left); 
}

void boundaryTraversal2(TreeNode* root) {
  if(root == NULL) return;
  cout << root->val << " ";
  printLeftBoundary(root->left);
  // printLeafBoundary(root); // -> wrong if there exists only single root node 
  // as it can print only root twice. once in print stmt above and other in leaf node recv call.
  // we can divide the leaf node printing into 2 parts and call on left and right.
  printLeafBoundary(root->left);
  printLeafBoundary(root->right);
  printRightBoundary(root->right);
}

int main() {
  
  TreeNode* root = createTree();
  levelwiseTraversal(root);
  
  cout << "printing values in boundary traversal in anticlock wise: " << endl;
  // boundaryTraversal(root);
  boundaryTraversal2(root);
    
  return 0;
}

// input
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
