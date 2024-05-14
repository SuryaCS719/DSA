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

void preorderTraversal(TreeNode* root) {
  if(root == NULL)
    return;
  cout << root->val << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void inorderTraversal(TreeNode* root) {
  if(root == NULL)
    return;
  
  inorderTraversal(root->left);
  cout << root->val << " ";
  inorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
  if(root == NULL)
    return;
  
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->val << " ";
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

void printLeftView(TreeNode* root, int level, vector<int>& leftview) {
  if(root == NULL)
      return;

  int sizeOfLeftView = leftview.size();
  if(level == sizeOfLeftView) 
    leftview.push_back(root->val);

  printLeftView(root->left, level+1, leftview);
  printLeftView(root->right, level+1, leftview);
}

void printRightView(TreeNode* root, int level, vector<int>& rightview) {
  if(root == NULL)
      return;

  int sizeOfRightView = rightview.size();
  if(level == sizeOfRightView) 
    rightview.push_back(root->val);

  printRightView(root->right, level+1, rightview);
  printRightView(root->left, level+1, rightview);
}



void leftViewUsinglevelwiseTraversal(TreeNode* root) {
  if(root == NULL)
      return;
  queue<TreeNode*> q;
  q.push(root);
  cout << root->val << " ";
  q.push(NULL);

  while(!q.empty()) {
    TreeNode* front = q.front();
    q.pop();

    if(front == NULL) {
      cout << endl;
      if(!q.empty()) {
        TreeNode* leftViewNode = q.front();
        cout << leftViewNode->val << " "; 
        q.push(NULL);
      }
    }
    else {
      if(front->left != NULL)
          q.push(front->left);
      if(front->right != NULL)
          q.push(front->right);

    }
  }
}

void rightViewUsinglevelwiseTraversal(TreeNode* root) {
  if(root == NULL)
      return;
  queue<TreeNode*> q;
  q.push(root);
  cout << root->val << " ";
  q.push(NULL);

  while(!q.empty()) {
    TreeNode* front = q.front();
    q.pop();

    if(front == NULL) {
      cout << endl;
      if(!q.empty()) {
        TreeNode* rightViewNode = q.back();
        cout << rightViewNode->val << " "; 
        q.push(NULL);
      }
    }
    else {
      if(front->left != NULL)
          q.push(front->left);
      if(front->right != NULL)
          q.push(front->right);

    }
  }
}

int main() {
  
  TreeNode* root = createTree();
  levelwiseTraversal(root);
  
  // cout << endl;
  // leftViewUsinglevelwiseTraversal(root);

  // cout << endl;
  // rightViewUsinglevelwiseTraversal(root);

  vector<int> leftview;
  vector<int> rightview;

  cout << endl << "printing leftview: ";
  printLeftView(root, 0, leftview);
  for(int i : leftview)
    cout << i << " ";
  
  cout << endl << "printing rightview: "; 
  printRightView(root, 0, rightview);
  for(auto i : rightview)
      cout << i << " ";
    
  return 0;
}

// input
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
