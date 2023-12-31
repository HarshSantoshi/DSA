#include <iostream>
#include <queue>

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

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};
#include <iostream>
using namespace std;
BinaryTreeNode<int>* takeInput() {
    int rootData;
    
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
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printkdistanceNodeDown(BinaryTreeNode<int> *root, int k)
{
    // Base Case
    if (root == NULL || k < 0)  return;
 
    // If we reach a k distant node, print it
    if (k==0)
    {
        cout << root->data << endl;
        return;
    }
 
    // Recur for left and right subtrees
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}

int printkdistanceNode(BinaryTreeNode<int>* root, int target , int k)
{
    // Base Case 1: If tree is empty, return -1
    if (root == NULL) return -1;
 
    // If target is same as root.  Use the downward function
    // to print all nodes at distance k in subtree rooted with
    // target or root
    if (root->data == target)
    {
        printkdistanceNodeDown(root, k);
        return 0;
    }
 
    // Recur for left subtree
    int dl = printkdistanceNode(root->left, target, k);
 
    // Check if target node was found in left subtree
    if (dl != -1)
    {
         // If root is at distance k from target, print root
         // Note that dl is Distance of root's left child from target
         if (dl + 1 == k)
            cout << root->data << endl;
 
         // Else go to right subtree and print all k-dl-2 distant nodes
         // Note that the right child is 2 edges away from left child
         else
            printkdistanceNodeDown(root->right, k-dl-2);
 
         // Add 1 to the distance and return value for parent calls
         return 1 + dl;
    }
 
    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
    // Note that we reach here only when node was not found in left subtree
    int dr = printkdistanceNode(root->right, target, k);
    if (dr != -1)
    {
         if (dr + 1 == k)
            cout << root->data << endl;
         else
            printkdistanceNodeDown(root->left, k-dr-2);
         return 1 + dr;
    }
 
    // If target was neither present in left nor in right subtree
    return -1;
}
 void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k){

 if(root==NULL){
     return ;
 }
 
 	int ans =printkdistanceNode(root, node  ,  k);
     cout<<ans<<endl;
 
 }
 
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}