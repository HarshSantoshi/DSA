#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*>children;
    TreeNode(T data){
    this ->data = data;
}
};

TreeNode<int>* TakeInputLevelWise(){
    int rootData;
    cout<<"Enter Root data"<<endl;
    cin>>rootData;
    TreeNode<int>*root = new TreeNode <int>(rootData);
    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();
        int numchild ;
        cout<<"Enter number of children of "<<front->data<<endl;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            int childData;
            cout<<"Enter the "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>*child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
        
    }
    return root;

}

void postOrder(TreeNode<int>*root){
    if(root==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postOrder(root->children[i]);
    }  
      cout<<root->data<<" ";
}

int main(){
    TreeNode<int>*root =TakeInputLevelWise();
    postOrder(root);
    }
