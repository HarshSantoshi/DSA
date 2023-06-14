#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
#include<limits.h>
int maximum(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    return max(root->data , max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    return min(root->data , min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>*root){
    if(root==NULL){
        return true;
    }
    int leftMax= maximum(root->left);
    int rightMin=minimum(root->right);
    return ((root->data>leftMax)  && (root->data <= rightMin) && isBST(root->left)  && isBST(root->right));

}
int main(){
    BinaryTreeNode<int>*root = takeInput();
     cout << (isBST(root) ? "true" : "false"); 
}