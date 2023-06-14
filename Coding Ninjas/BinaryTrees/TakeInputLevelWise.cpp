#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<int>*left ;
    BinaryTreeNode<int>*right ;
    BinaryTreeNode(T data){
        this ->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right ;
    }

};

BinaryTreeNode<int>* TakeInputLevelWise(){
    cout<<"Enter root Data"<<endl;
    int rootData;
    cin>>rootData;
    if(rootData ==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>*curr= pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the left child of "<<curr->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int>*child = new BinaryTreeNode<int>(leftChildData);
             curr->left = child;
             pendingNodes.push(child);
        }
        cout<<"Enter the right child of "<<curr->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>*child = new BinaryTreeNode<int>(rightChildData);
             curr->right = child;
             pendingNodes.push(child);
        }
       
    }
    return root;
}

void printTree(BinaryTreeNode<int>*root){
    if(root ==NULL){
        return ;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);

}

int main(){
    BinaryTreeNode<int>*root = TakeInputLevelWise();
    printTree(root);
}