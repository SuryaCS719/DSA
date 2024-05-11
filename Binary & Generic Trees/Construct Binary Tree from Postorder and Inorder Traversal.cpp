#include <iostream>
#include <queue>
#include <map>
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
  if(root == NULL) return;
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

void createMap (int *inOrder, int size, map<int, int> &valueToIndexMap) {
  for(int i = 0; i < size; i++) {
    int elementOfInorder = inOrder[i];
    int index = i;
    valueToIndexMap[elementOfInorder] = index;
  }
}

TreeNode* constructTreeFromPostAndInorderTraversal(int *postOrder, int &postOrderIndex, int *inOrder, int inOrdeStart, int inOrderEnd, int size, 
map<int, int> &valueToIndexMap) {
  // base case: out_of_bound conditions
  if(postOrderIndex < 0 || inOrdeStart > inOrderEnd)
    return NULL;
  // solve for 1 case
  int postOrderLastElement = postOrder[postOrderIndex];
  postOrderIndex--;
  TreeNode* root = new TreeNode(postOrderLastElement);
  // finding root in inOrder
  int position = valueToIndexMap[postOrderLastElement];
  //recursion handles the rest
  root->right = constructTreeFromPostAndInorderTraversal(postOrder, postOrderIndex, inOrder, position + 1, inOrderEnd, size, valueToIndexMap);
  root->left = constructTreeFromPostAndInorderTraversal(postOrder, postOrderIndex, inOrder, inOrdeStart, position - 1, size, valueToIndexMap);
  return root;
}

int main() {
  int inOrder[] = {8, 14, 6, 2, 10, 4};
  int postOrder[] = {8, 6, 14, 4, 10, 2};
  int size = 6;
  int postOrderIndex = size - 1;
  int inOrdeStart = 0;
  int inOrderEnd = 5;

  map<int, int> valueToIndexMap;
  createMap(inOrder, size, valueToIndexMap);

  TreeNode* root = constructTreeFromPostAndInorderTraversal(postOrder, postOrderIndex, inOrder, inOrdeStart, inOrderEnd, size, valueToIndexMap);
  printLevelWise(root);
  return 0;
}