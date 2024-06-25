// this Trie program is only valid for smallcase letters from a - z.
// This Trie program is implemented via an pointer to an array for the children nodes and also includes insertion, deletion and searching.

#include <iostream>
using namespace std;

class TrieNode {
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char ch) {
    this->data = ch;
    
    for (int i = 0; i < 26; i++)
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

  char ch = word[0];
  int index = ch - 'a'; // at this index, child is either present or not

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

  char ch = word[0];
  int index = ch - 'a';
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

  char ch = word[0];
  int index = ch - 'a';
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

  insertWord(root, "coding");
  insertWord(root, "code");
  insertWord(root, "codehelp");
  insertWord(root, "coder");

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

/*

insearting word: coding
insearting word: oding
insearting word: ding
insearting word: ing
insearting word: ng
insearting word: g
insearting word: 

insearting word: code
insearting word: ode
insearting word: de
insearting word: e
insearting word: 

insearting word: codehelp
insearting word: odehelp
insearting word: dehelp
insearting word: ehelp
insearting word: help
insearting word: elp
insearting word: lp
insearting word: p
insearting word: 

insearting word: coder
insearting word: oder
insearting word: der
insearting word: er
insearting word: r
insearting word: 

Enter the word to search: coder
coder is found
Enter the word to search: codey
codey is not found
Enter the word to search: -1


*/
