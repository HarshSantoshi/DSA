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


void printLevelWise(TreeNode <int>*root){
    if(root == NULL){
        return;
    }
    queue<TreeNode<int>*>p;
    p.push(root);
    while(!p.empty()){
        TreeNode<int>*curr = p.front();
        p.pop();
        cout<<curr->data<<":";
        int childcount = curr->children.size();
        if(childcount){
            cout<<curr->children[0]->data;
            p.push(curr->children[0]);
        }
        for(int i=1;i<childcount;i++){
            cout<<","<<curr->children[i]->data;
            p.push(curr->children[i]);
        }
        cout<<endl;
    }
}
int getHeight(TreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    if(root->children.size()==0){
        return 1;
    }
    
    int max_childHeight = 0;
    for(int i=0;i<root->children.size();i++){
         max_childHeight = max(max_childHeight,getHeight(root->children[i]));
    }
    return 1+ max_childHeight;
}
int main() {
    TreeNode<int>* root = TakeInputLevelwise();
    cout << getHeight(root);
}



