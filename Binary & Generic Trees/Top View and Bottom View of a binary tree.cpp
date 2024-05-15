#include <iostream>
#include <queue>
#include <map>
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

void printTopView(TreeNode* root) {
  if(root == NULL) return;
  // horizontal distance mapping.
  map<int, int> hdToNode;
  queue<pair<TreeNode*, int>> q;
  q.push(make_pair(root, 0));

  while(!q.empty()) {
    pair<TreeNode*, int> temp = q.front();
    q.pop();

    TreeNode* elementNode = temp.first;
    int hd = temp.second;

    // if(!(hdToNode[hd])) // -> this works too
    if(hdToNode.find(hd) == hdToNode.end())  // better practice
      hdToNode[hd] = elementNode->val;
    
    if(elementNode->left != NULL)
      q.push({elementNode->left, hd - 1});
    if(elementNode->right != NULL)
      q.push(make_pair(elementNode->right, hd + 1));
  }
  
  cout << "Printing top view " << endl;
    for(auto it : hdToNode)
      cout << it.second << " ";
}

void printBottomView(TreeNode* root) {
  if(root == NULL) return;
  // horizontal distance mapping.
  map<int, int> hdToNode;
  queue<pair<TreeNode*, int>> q;
  q.push(make_pair(root, 0));

  while(!q.empty()) {
    pair<TreeNode*, int> temp = q.front();
    q.pop();

    TreeNode* elementNode = temp.first;
    int hd = temp.second;

    // need to overwrite the values so that deeper nodes can replace the prev nodes.
    hdToNode[hd] = elementNode->val;
    
    if(elementNode->left != NULL)
      q.push({elementNode->left, hd - 1});
    if(elementNode->right != NULL)
      q.push(make_pair(elementNode->right, hd + 1));
  }
  
  cout << endl << "Printing bottom view " << endl;
    for(auto it : hdToNode)
      cout << it.second << " ";
}


int main() {
  
  TreeNode* root = createTree();
  levelwiseTraversal(root);

  printTopView(root);
  printBottomView(root);
  
 
    
  return 0;
}

// input
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
