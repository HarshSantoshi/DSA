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

TreeNode<int>* getNextLargerElement(TreeNode<int>*root, int n){
    if(root == NULL){
        return NULL;
    }
    TreeNode<int>*result =NULL;
    if(root->children.size()==0){
        if(root->data >n){
            return root;
        }
        else{
            return NULL;
        }
    }
    if(root->data>n){
        result = root;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>*temp = getNextLargerElement(root->children[i],n);
        if(temp ==NULL){
continue;}
        if(result ==NULL ||result->data>temp->data ){
            result = temp;
        }

    }
    return result;
}

int main() {
    TreeNode<int>* root = TakeInputLevelWise();
     int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}