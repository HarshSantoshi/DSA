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

pair<int,int > getMinAndMax(BinaryTreeNode<int>*root){
if(root==NULL){
pair<int,int>ans;
ans.first=INT_MIN;
ans.second=INT_MAX;
return ans;

}
pair<int,int> leftAns = getMinAndMax(root->left);
pair<int,int> rightAns = getMinAndMax(root->right);
pair<int,int> ans ;
ans.first= max(root->data , max(leftAns.first , rightAns.first));
ans.second= min(root->data , min(leftAns.second , rightAns.second));
return ans;

}

int main() {
    BinaryTreeNode<int>* root = TakeInputLevelWise();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}