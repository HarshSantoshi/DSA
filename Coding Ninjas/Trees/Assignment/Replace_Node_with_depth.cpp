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
void replaceWithDepthValueHelper(TreeNode<int>*root , int value){
    if(root==NULL){
        return ;
    }
    root->data = value;
    for(int i=0;i<root->children.size();i++){
        replaceWithDepthValueHelper(root->children[i],value+1);
    }


}
void replaceWithDepthValue(TreeNode<int>*root){
    replaceWithDepthValueHelper(root,0);

}
void  PrintTreeLevelWise(TreeNode<int>*root){
     queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode<int>* first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        for (int i = 0; i < first->children.size(); i++) {
            q.push(first->children[i]);
        }
    }
}

int main() {
    TreeNode<int>* root = TakeInputLevelWise();
    replaceWithDepthValue(root);
    PrintTreeLevelWise(root);
}