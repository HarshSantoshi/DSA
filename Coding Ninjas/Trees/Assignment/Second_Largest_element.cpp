#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
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
template<typename T>
class SecondLargestNode{
    public:
    TreeNode<T>*largest =NULL;
    TreeNode<T>*secondLargest =NULL;
    SecondLargestNode(TreeNode<int>* first , TreeNode<int>* second){
        this->largest = first;
        this->secondLargest= second;
    }
    
};
SecondLargestNode<int>* getSecondLargestNodeHelper(TreeNode<int>*root){
    if(root==NULL){
        return new SecondLargestNode<int>(NULL,NULL);
    }
    SecondLargestNode<int>*ans  =new SecondLargestNode<int>(root,NULL);
    for(int i=0;i<root->children.size();i++){
        SecondLargestNode<int>*childAns= getSecondLargestNodeHelper(root->children[i]);
        if(childAns->largest->data > ans->largest->data){
            if(childAns->secondLargest==NULL){
                ans->secondLargest = ans->largest;
                ans->largest=childAns->largest;
            }
            else{
                if(childAns->secondLargest->data > ans->largest->data){
                    ans->secondLargest = childAns->secondLargest;
                    ans->largest = childAns->largest;
                }
                else{
                    ans->secondLargest=ans->largest;
                    ans->largest = childAns->largest;
                }
            }
        }
        else{
            if(ans->largest->data != childAns->largest->data && (ans->secondLargest==NULL || childAns->largest->data > ans->secondLargest->data)){
                ans->secondLargest=childAns->largest;
            }
        }
    }
    return ans;

}

TreeNode<int>* getSecondLargestNode(TreeNode<int>*root){
    return getSecondLargestNodeHelper(root)->secondLargest;
}
int main() {
    TreeNode<int>* root = TakeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}