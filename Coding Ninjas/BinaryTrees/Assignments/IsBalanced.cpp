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

int height(BinaryTreeNode<int>* root){
if(root==nullptr) return 0;
int lh=height(root->left);
int rh=height(root->right);
if(lh==-1 || rh == -1)
return -1;
if(abs(lh-rh)<=1)
return 1 + max(lh,rh);
else
return -1;
}
bool isBalanced(BinaryTreeNode<int>* root) {
return height(root)==-1?false:true;
}

int main() {
    BinaryTreeNode<int>* root = TakeInputLevelWise();
    cout << (isBalanced(root) ? "true" : "false");
}

