#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>

class TreeNode{
    public:
    T data;
    vector<TreeNode<int>*>children;
    TreeNode(T data){
        this -> data = data;
    }
};

TreeNode<int>* TakeInputLevelWise(){
    cout<<"Enter root Data"<<endl;
    int rootData;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>*front= pendingNodes.front();
        pendingNodes.pop();
        int numchild;
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
bool areIdentical(TreeNode<int>*root1 , TreeNode<int>*root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 !=NULL && root2 == NULL){
        return false;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    }
    int childcount1 = root1->children.size();
    int childcount2 = root2->children.size();
    if(childcount1 != childcount2){
        return false;
    }
    for(int i=0;i<childcount1;i++){
        if(!areIdentical(root1->children[i],root2->children[i])){
            return false;
            
        }
    }
    return true;

}


int main() {
    TreeNode<int>* root1 = TakeInputLevelWise();
    TreeNode<int>* root2 = TakeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}