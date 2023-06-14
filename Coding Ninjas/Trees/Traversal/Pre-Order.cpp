#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*>children;
    TreeNode(T data){
        this->data =data;
    }
};

TreeNode<int>* TakeInputLevelwise(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
    TreeNode<int>*front =pendingNodes.front();
    pendingNodes.pop();

    int numchild;
    cout<<"Enter number of children of "<<front->data<<endl;
    cin>>numchild;
    for(int i=0;i<numchild;i++){
        int childData;
        cout<<"Enter the "<<i<<"th child of "<<front->data<<endl;
        cin>>childData;
        TreeNode<int>*child = new TreeNode<int>(childData);
        front->children.push_back(child);
        pendingNodes.push(child);

    }
   
    }
     return root;
}


void PrintLevelWise(TreeNode<int>*root){
    if(root==NULL){
        return;
    }
    queue<TreeNode<int>*>p;
    p.push(root);
    while(!p.empty()){
        TreeNode<int>*curr = p.front();
        p.pop();
        cout<<curr->data<<":";
        int numchild = curr->children.size();
        if(numchild){
            cout<<curr->children[0]->data;
            p.push(curr->children[0]);
        }
        for(int i=1;i<numchild;i++){
            cout<<","<<curr->children[i]->data;
            p.push(curr->children[i]);
        }
        cout<<endl;
    }
    cout<<endl;

}

void preorder(TreeNode<int>*root){
    //edge case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}
int main(){
    TreeNode<int>*root=TakeInputLevelwise();
   PrintLevelWise(root);
   preorder(root);
}

