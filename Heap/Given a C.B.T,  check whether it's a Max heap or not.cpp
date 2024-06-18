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
    left = right = NULL;
  }
};


Node* insertNodeIntoBTLevelWise(Node* root, int data) {

  Node* newNode = new Node(data);

  if (root == NULL) {
    root = newNode;
    return root;
  }

  queue<Node*> q;
  q.push(root);

  while(!q.empty()) {
    Node* temp = q.front();
    q.pop();

    if (temp->left == NULL) {
      temp->left = newNode;
      return root;  // Insertion done
    }
    else q.push(temp->left); // Push left child for further exploration


    if (temp->right == NULL) {
        temp->right = newNode;
        return root;  // Insertion done
    }
    else q.push(temp->right);  // Push right child for further exploration

  }

  return root;
}


void levelWisePrint(Node* root) {
  if(root == NULL)
    return;

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

// check if given CBT is valid a Max Heap or not.

class NodeData {
public: 
  int maxVal;
  bool isValidMaxHeap;

  NodeData(int maxVal, bool isValidMaxHeap) {
    this->maxVal = maxVal;
    this->isValidMaxHeap = isValidMaxHeap;
  }
};


NodeData* Check_If_CBT_Is_MaxHeap(Node* root) {
  // base case for root is NULL
  if(root == NULL)
    return new NodeData(INT_MIN, true);

  // base case for leaf node as they already satisfy heap property by dft
  if(root->left == NULL && root->right == NULL)
    return new NodeData(root->data, true);

  // L R N
  NodeData* leftAns = Check_If_CBT_Is_MaxHeap(root->left); // L
  NodeData* rightAns = Check_If_CBT_Is_MaxHeap(root->right); // R

  // N : Process current_node. 
  if(leftAns->isValidMaxHeap == true && rightAns->isValidMaxHeap == true 
     && root->data > leftAns->maxVal && root->data > rightAns->maxVal)
      return new NodeData(root->data, true);

  else {
    int maximumNodeVal = max(root->data, max(leftAns->maxVal, rightAns->maxVal));
    return new NodeData(maximumNodeVal, false);
  }
}

int main() {
  Node* root = NULL;
  int data;
  cout << "enter data: ";
  cin >> data;

  while(data != -1) {
    root = insertNodeIntoBTLevelWise(root, data);
    cout << "Enter data for next node: ";
    cin >> data;
  }

  cout << "Level order traversal of the binary tree:" << endl;
  levelWisePrint(root);

  NodeData* ans = Check_If_CBT_Is_MaxHeap(root);
  if(ans->isValidMaxHeap == true)
    cout << "Given CBT is a Max Heap" << endl;
  else
    cout << "Given CBT is not a Max Heap" << endl;

}


/*

enter data: 40
Enter data for next node: 20
Enter data for next node: 10
Enter data for next node: 5
Enter data for next node: -1
Level order traversal of the binary tree:
40 
20 10 
5 
Given CBT is a Max Heap

----------------------

enter data: 50
Enter data for next node: 60
Enter data for next node: 40
Enter data for next node: 30
Enter data for next node: 20
Enter data for next node: -1
Level order traversal of the binary tree:
50 
60 40 
30 20 
Given CBT is not a Max Heap

*/
