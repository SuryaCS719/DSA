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

}



// Using Void

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
    left = right = NULL;
  }
};


void insertNodeIntoBTLevelWise(Node* &root, int data) {

  Node* newNode = new Node(data);

  if (root == NULL) {
    root = newNode;
    return;
  }

  queue<Node*> q;
  q.push(root);

  while(!q.empty()) {
    Node* temp = q.front();
    q.pop();

    if (temp->left == NULL) {
      temp->left = newNode;
      return;  // Insertion done
    }
    else q.push(temp->left); // Push left child for further exploration


    if (temp->right == NULL) {
        temp->right = newNode;
        return;  // Insertion done
    }
    else q.push(temp->right);  // Push right child for further exploration

  }
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

int main() {
  Node* root = NULL;
  int data;
  cout << "enter data: ";
  cin >> data;


  while(data != -1) {
    
    insertNodeIntoBTLevelWise(root, data);
    cout << "Enter data for next node: ";
    cin >> data;
  }

  cout << "Level order traversal of the binary tree:" << endl;
  levelWisePrint(root);

}

