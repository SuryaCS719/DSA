#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int data) {
    val = data;
    left = NULL;
    right = NULL;
  } 
};

void printLevelWise(TreeNode* root){
  // if(root == NULL) return;
  queue<TreeNode*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()) {
    TreeNode* front = q.front();
    q.pop();
    if(front == NULL) {
      cout << endl;
      if(!q.empty())
        q.push(NULL);
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

int searchInorder(int *inOrder, int target, int size) {
  for(int i = 0; i < size; i++) 
    if(inOrder[i] == target)
      return i;
  // although the element will be found at all times.
  return -1;
}

TreeNode* constructTreeFromPreAndInorderTraversal(int *preOrder, int &preOrderIndex, int *inOrder, int inOrdeStart, int inOrderEnd, int size) {
  // base case: out_of_bound conditions
  if(preOrderIndex >= size || inOrdeStart > inOrderEnd)
    return NULL;
  // solve for 1 case
  int preOrderFirstElement = preOrder[preOrderIndex];
  preOrderIndex++;
  TreeNode* root = new TreeNode(preOrderFirstElement);
  // finding root in inOrder
  int position = searchInorder(inOrder, preOrderFirstElement, size); //-> O(n)
  //recursion handles the rest
  root->left = constructTreeFromPreAndInorderTraversal(preOrder, preOrderIndex, inOrder, inOrdeStart, position - 1, size);
  root->right = constructTreeFromPreAndInorderTraversal(preOrder, preOrderIndex, inOrder, position + 1, inOrderEnd, size);
  return root;
}

int main() {
  int inOrder[] = {10, 8, 6, 2, 4, 12};
  int preOrder[] = {2, 8, 10, 6, 4, 12};
  int size = 6;
  int preOrderIndex = 0;
  int inOrdeStart = 0;
  int inOrderEnd = 5;
  TreeNode* root = constructTreeFromPreAndInorderTraversal(preOrder, preOrderIndex, inOrder, inOrdeStart, inOrderEnd, size);
  printLevelWise(root);
  return 0;
}