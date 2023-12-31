
#include <string>
#include<bits/stdc++.h>
#include <vector>
class TrieNode {
public:
  char data;
  TrieNode **children;
  bool isTerminal;

  TrieNode(char data) {
    this->data = data;
    children = new TrieNode *[26];
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    isTerminal = false;
  }
};

class Trie {
  TrieNode *root;

public:
  int count;

  Trie() {
    this->count = 0;
    root = new TrieNode('\0');
  }

  bool insertWord(TrieNode *root, string word) {
    // Base case
    if (word.size() == 0) {
      if (!root->isTerminal) {
        root->isTerminal = true;
        return true;
      } else {
        return false;
      }
    }

    // Small Calculation
    int index = word[0] - 'a';
    TrieNode *child;
    if (root->children[index] != NULL) {
      child = root->children[index];
    } else {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    // Recursive call
    return insertWord(child, word.substr(1));
  }

  // For user
  void insertWord(string word) {
    if (insertWord(root, word)) {
      this->count++;
    }
  }
  bool search(TrieNode *root, string word) {
    // Write your code here
    if (word.size() == 0) {
      return true;
    }
    if (root->children[word[0] - 'a'] == NULL)
      return false;

    return search(root->children[word[0] - 'a'], word.substr(1));
  }
  bool search(string word) { return search(root, word); }
  bool patternMatching(vector<string> vect, string pattern) {
    // Complete this function
    // Return true or false
    for (int i = 0; i < vect.size(); i++) {
      while (vect[i].size() != 0) {
        insertWord(vect[i]);
        vect[i] = vect[i].substr(1);
      }
    }
    return search(pattern);
  }
};