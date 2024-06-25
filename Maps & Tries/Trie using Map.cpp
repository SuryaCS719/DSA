// Valid for smaller and uppercase words.
// more elegant way is to use map to store the children of trie than using pointer to array.


#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
  char data;
  unordered_map<char, TrieNode*> children;
  bool isTerminal;

  TrieNode(char ch) {
    this->data = ch;
    this->isTerminal = false;
  }
};

void insertWord(TrieNode* root, string word) {
  cout << "Inserting word: " << word << endl;
  TrieNode* current = root;

  for(char &ch : word) {
    // If the character exists, traverse on it.
    if(current->children.find(ch) != current->children.end()) {
      current = current->children[ch]; // Move to the next node
    }
    else {
        // If the character does not exist, create a new TrieNode
        // and then point existing root to the newNode
        // and then finally traverse on the newNode
        TrieNode* newNode = new TrieNode(ch);
        current->children[ch] = newNode;
        current = current->children[ch];
    }
  }
  // Mark the last node as terminal
  current->isTerminal = true;
}

/* more simpler way of insertion:
void insertWord(TrieNode* root, string word) {
  TrieNode* current = root;

  for (char ch : word) {
    if (current->children.find(ch) == current->children.end()) {
      TrieNode* newNode = new TrieNode(ch);
      current->children[ch] = newNode;
    }
    current = current->children[ch]; // Move to the next node
  }
  current->isTerminal = true; // Mark the last node as terminal
} */



void deleteWord(TrieNode* root, string word) {
  TrieNode* current = root;
  for(char &ch : word) {
    // If the character exist then we traverse till its end if feasible then mark it as false.
    if(current->children.find(ch) != current->children.end()) {
      current = current->children[ch];
    }
    else{
      // If the character does not exist then we return, nothing to delete.
      cout << "Word not found to delete." << endl;
      return; 
    }
  }
  
  current->isTerminal = false;
}


bool searchWord(TrieNode* root, string word) {
  TrieNode* current = root;
  for(char &ch : word) {
    // If the character exist then we traverse on it.
    if(current->children.find(ch) != current->children.end())
      current = current->children[ch]; // Move to the next node
    else return false; // character not found, thus stop searching.
  }
  // Check if the last node is marked as terminal
  return current->isTerminal;
}




int main() {
  TrieNode* root = new TrieNode('-');

  insertWord(root, "code");
  insertWord(root, "coder");
  insertWord(root, "codehelp");
  insertWord(root, "SUPREMACY");

  deleteWord(root, "codey");
  deleteWord(root, "coder");

  string search_a_word;
  cout << "Enter a word to search in the existing trie: ";
  cin >> search_a_word;

  while(search_a_word != "-1") {

    if(searchWord(root, search_a_word))
      cout << search_a_word << " is found" << endl;
    else cout << search_a_word << " is not found" << endl;

    cout << "Enter a word to search in the existing trie: ";
    cin >> search_a_word;
  }

}



/*
/tmp/iQ42SfNxYU.o
Inserting word: code
Inserting word: coder
Inserting word: codehelp
Inserting word: SUPREMACY
Word not found to delete.
Enter a word to search in the existing trie: code
code is found
Enter a word to search in the existing trie: coder
coder is not found
Enter a word to search in the existing trie: codey
codey is not found
Enter a word to search in the existing trie: supremacy
supremacy is not found
Enter a word to search in the existing trie: SUPREMACY
SUPREMACY is found
Enter a word to search in the existing trie: coder
coder is not found
Enter a word to search in the existing trie: code
code is found
Enter a word to search in the existing trie: -1


=== Code Execution Successful ===

*/





