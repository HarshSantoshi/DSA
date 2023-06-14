#include<iostream>
using namespace std;
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>*left;
    BinaryTreeNode<T>*right;
    BinaryTreeNode (T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }

};
void printTree(BinaryTreeNode<int>*root){
    if(root ==NULL){
        return ;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);

}

BinaryTreeNode<int>* TakeInput(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>*left = TakeInput();
    BinaryTreeNode<int>*right = TakeInput();
    root->left = left;
    root->right = right ;
    return root;

}
int main(){
    BinaryTreeNode<int>*root = TakeInput();
    printTree(root); 
}