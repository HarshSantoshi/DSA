#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int> *TakeInputLevelWise()
{
    cout << "Enter root Data" << endl;
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *curr = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the left child of " << curr->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            curr->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter the right child of " << curr->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            curr->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
#include<stack>
int height(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1 + max(height(root->left) , height(root->right));
}

void zigZag(BinaryTreeNode<int>*root){
    if(root==NULL){
        return ;
    }
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
     BinaryTreeNode<int>*topEle;
    s1.push(root);
    for(int i=0;i<height(root);i++){
        
        if(i%2==0){
            cout<<endl;
            while(!s1.empty()){
            topEle = s1.top();
            s1.pop();
            cout<<topEle->data<<" ";
            if(topEle->left){
                s2.push(topEle->left);
            }
            if(topEle->right){
                s2.push(topEle->right);
            }
        }
        }
        else{
             cout<<endl;
             while(!s2.empty()){
            topEle = s2.top();
            s2.pop();
            cout<<topEle->data<<" ";
            if(topEle->right){
                s1.push(topEle->right);
            }
            if(topEle->left){
                s1.push(topEle->left);
            }
        }
        }
    }

}
int main() {
    BinaryTreeNode<int>* root = TakeInputLevelWise();
    zigZag(root);
}