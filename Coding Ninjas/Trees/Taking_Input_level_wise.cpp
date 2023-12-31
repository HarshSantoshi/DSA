#include<iostream>
#include <vector>
#include<queue>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode <T>*>children;
    TreeNode(T data){
        this -> data = data;
    }
};

TreeNode <int>* TakeInputLevelwise(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    TreeNode<int>*root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() !=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
    int numchild;
    cout<<"Enter number of childen of "<<front->data<<endl;
    cin>>numchild;
    for(int i=0;i<numchild;i++){
        int childData;
        cout<<"Enter "<<i<< "th child of "<<front->data<<endl;
        cin>>childData;
        TreeNode<int>*child = new TreeNode<int>(childData);
        front->children.push_back(child);
        pendingNodes.push(child);
    }
    }
    return root;
}


void printTree(TreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
int main(){

   TreeNode<int>*root = TakeInputLevelwise();
    printTree(root);
}