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
        this->data = data;
    }

};

TreeNode<int>* TakeInputLevelWise(){
    cout<<"Enter root data"<<endl;
    int rootData;
    cin>>rootData;
    TreeNode<int>*root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>*front = pendingNodes.front();
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

bool isPresent(TreeNode<int>*root, int x){
    if(root==NULL){
        return false;
    }
    if(x==root->data){
        return true;
    }
    for(int i=0;i<root->children.size();i++){
      if(isPresent(root->children[i],x)){
      return true;}
    }
    return false;
}
int main() {
    TreeNode<int>* root = TakeInputLevelWise();
    int x;
    cin >> x;
    cout << (isPresent(root, x) ? "true" : "false");
}