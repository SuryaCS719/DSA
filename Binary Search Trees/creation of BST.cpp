#include <iostream>
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

// void levelOrderTraversal(Node* root) {
//   queue<Node*> q;
//   q.push(root);
//   q.push(NULL);

//   while(!q.empty()) {
//     Node* front = q.front();
//     q.pop();
    
//     if(front == NULL) {
//       cout << endl;
//       if(!q.empty())
//         q.push(NULL);
//     }
//     else {
//       cout << front->data << " ";
//       if(front->left)
//         q.push(front->left);
//       if(front->right)
//           q.push(front->right);
//     }
//   }
// }

// void preorder(Node* root) {
//   if(root == NULL)
//       return;
  
//   cout << root->data << " ";
//   preorder(root->left);
//   preorder(root->right);
// }

// void inorder(Node* root) {
//   if(root == NULL)
//       return;
  
//   inorder(root->left);
//   cout << root->data << " ";
//   inorder(root->right);
// }

// void postorder(Node* root) {
//   if(root == NULL)
//       return;
  
//   postorder(root->left);
//   postorder(root->right);
//   cout << root->data << " ";
// }

int main() {

  Node* root = NULL;
  createBST(root);
  levelOrderTraversal(root);

  cout << endl << "Preorder: "; 
  preorder(root);

  cout << endl << "Inorder: ";
  inorder(root);

  cout << endl << "Postorder: ";
  postorder(root);

  return 0;
}

/* input: 50 30 60 25 40 70 80 55 -1 

level print
50 
30 60 
20 40 55 70 
25 80 

Preorder: 50 30 25 40 60 55 70 80 
Inorder: 25 30 40 50 55 60 70 80 
Postorder: 25 40 30 55 80 70 60 50  


Observation:

Inorder of BST is always sorted in increasing order.
reason:    


*/
