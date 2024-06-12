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
    left = right = nullptr;
  }
};

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

Node* bstFromInorderArray(int inorder[], int start, int end) {
  // base case
  if(start > end)
    return nullptr;
  // solve for 1 case
  int mid = (start + end) / 2;
  int midElement = inorder[mid];
  Node* root = new Node(midElement);

  // recv handles the rest
  root->left = bstFromInorderArray(inorder, start, mid - 1);
  root->right = bstFromInorderArray(inorder, mid + 1, end);

  return root;
}

int main() {
  int inorder[] = {10, 20, 30, 40, 50, 60, 70};
  int size = 7;
  int start = 0;
  int end = size - 1;
  
  Node* root = bstFromInorderArray(inorder, start, end);
  levelOrderTraversal(root);

  return 0;
}
