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
int sumNode(TreeNode<int>*root){
    if (root==NULL){
        return 0;
    }
    int sum = root->data;
    for(int i=0;i<root->children.size();i++){
        sum+= root->children[i]->data;
    }
    return sum;

}
TreeNode<int>*maxSumNode(TreeNode<int>*root){
    if(root==NULL){
        return NULL;
    }
    int maxSum = sumNode(root);
    TreeNode<int>*result = root;
    for(int i=0;i<root->children.size();i++){
       TreeNode<int>*temp = maxSumNode(root->children[i]);
       int max = sumNode(temp);
       if(max>maxSum){
        maxSum=max;
        result = temp;
       }
    }
    return result;
   
}


int main() {
    TreeNode<int>* root = TakeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}