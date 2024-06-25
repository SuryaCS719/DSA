// this Trie program is only valid for smallcase letters from a - z and as well as uppercase A-Z.
// This Trie program is implemented via an pointer to an array for the children nodes and also includes insertion, deletion and searching.


#include <iostream>
using namespace std;

class TrieNode {
public:
  char data;
  TrieNode *children[52]; // change 1
  bool isTerminal;

  TrieNode(char ch) {
    this->data = ch;
    
    for (int i = 0; i < 52; i++) // iterate till 52
      children[i] = NULL;
      
    this->isTerminal = false;
  }
};

void insertWord(TrieNode* root, string word) {
  cout << "insearting word: " << word << endl; // prints the inserted words
  // base case
  if(word.length() == 0) {
    root->isTerminal = true;
    cout << endl;
    return;
  } 
  
  char ch = word[0]; // change 2
  int index;
  if(ch >= 'a' && ch <= 'z')
    index = ch - 'a'; // at this index, child is either present or not
  else if(ch >= 'A' && ch <= 'Z')
    index = ch - 'A' + 26;  // ex: ch = A -> A - A = 0 + 26 = 26.
  else return; // invalid character. 

  TrieNode* child;
  // if child is present
  if(root->children[index] != NULL) 
    child = root->children[index];
  
  else {
    // child is not present
    child = new TrieNode(ch);
    root->children[index] = child;
  }
  // recursion  
  insertWord(child, word.substr(1)); 
}


bool searchWord(TrieNode* root, string word) {
  // base case
  if(word.length() == 0)
    return root->isTerminal;

  char ch = word[0]; // change 2
  int index;
  if(ch >= 'a' && ch <= 'z')
    index = ch - 'a'; // at this index, child is either present or not
  else if(ch >= 'A' && ch <= 'Z')
    index = ch - 'A' + 26;  // ex: ch = A -> A - A = 0 + 26 = 26.
  else return false; // invalid character. 

  TrieNode* child;

  if(root->children[index] != NULL) // if present.
      child = root->children[index];
  else 
      return false; // if not present.
    
  return searchWord(child, word.substr(1)); 
}

void deleteWord(TrieNode* root, string word) {
  // base case
  if(word.length() == 0) {
    root->isTerminal = false;
    return;
  }

  char ch = word[0]; // change 2
  int index;
  if(ch >= 'a' && ch <= 'z')
    index = ch - 'a'; // at this index, child is either present or not
  else if(ch >= 'A' && ch <= 'Z')
    index = ch - 'A' + 26;  // ex: ch = A -> A - A = 0 + 26 = 26.
  else {
    cout << "Invalid character in the word to delete" << endl;
    return;
  }


  TrieNode* child;

  if(root->children[index] != NULL)
      child = root->children[index];
  else {
    cout << "word not found to delete" << endl;
    return;
  }

  deleteWord(child, word.substr(1));
}

int main() {

  TrieNode* root = new TrieNode('-');

  // insertWord(root, "coding");
  // insertWord(root, "codehelp");
  insertWord(root, "code");
  insertWord(root, "coder");


  insertWord(root, "ABCDE");
  insertWord(root, "ZELP");
  insertWord(root, "YELP");

  // deleteWord(root, "code");

  string search_a_word;
  cout << "Enter the word to search: "; 
  cin >> search_a_word;
  
  while(search_a_word != "-1") {
    if(searchWord(root, search_a_word))
        cout << search_a_word << " is found" << endl;
    else
        cout << search_a_word << " is not found" << endl;

    cout << "Enter the word to search: "; 
    cin >> search_a_word;
  }
  
  return 0;
}

