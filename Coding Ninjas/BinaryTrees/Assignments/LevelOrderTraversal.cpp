#include <iostream>
#include <queue>
#include<limits.h>
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
void PrintLevelWise(BinaryTreeNode<int>*root){
    if(root ==NULL){
        return ;
    }
    queue<BinaryTreeNode<int>*>pendingNodes ;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> *front= pendingNodes.front();
        pendingNodes.pop();
        if(front==NULL){
            if(pendingNodes.empty()){
                cout<<endl;
                break;
            }
            cout<<endl;
            pendingNodes.push(NULL);
        }
        else{
            cout<<front->data<<" ";
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
             if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
        }
    }

}
int main() {
    BinaryTreeNode<int>* root = TakeInputLevelWise();
    PrintLevelWise(root);
}