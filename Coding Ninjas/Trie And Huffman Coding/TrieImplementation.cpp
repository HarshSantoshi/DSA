#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode**children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
 };
 class Trie{
    TrieNode*root;
    public:
    Trie(){
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode* root,string word){
        //Base Case
        if(word.size()==0){
           root-> isTerminal =true;
           return;
        }
        //Small calculation
        TrieNode*child;
        int index = word[0]-'a';
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }

        //Recursion 
        insertWord(child , word.substr(1));
    }
    //For user
    void insertWord(string word){
        insertWord(root, word);
    }

    void deleteWord(TrieNode * root ,string word){
        if(word.size()==0){
            root->isTerminal=false;
            return;
        }

        TrieNode*child ;
        int index =word[0]-'a';
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return ;
        }

        deleteWord(child , word.substr(1));


        if(child->isTerminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL){
                    return ;
                }
            }
            delete child ;
            root->children[index]=NULL;
        }
    }

    void deleteWord(string word){
        deleteWord(root, word);
    }

    bool search(TrieNode*root ,string word) {
        // Write your code here
        if(word.size()==0){
            return root->isTerminal;
        }
         int index = word[0] - 'a';
   
        if(root->children[index]==NULL){
            return false;
        }       
           return search(root->children[index] , word.substr(1));  
    }
    bool search( string word){
        return search(root ,  word);
    }


 };

 int main(){
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout<<t.search("and")<<endl;
    t.deleteWord("and");
    cout<<t.search("and");
     }