#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode * left;
    BinaryTreeNode * right;

    BinaryTreeNode(int d){
        this->data = d;
        this->left =NULL;
        this->right =NULL;
    }

};
void printTree(BinaryTreeNode*root){
    if (root==NULL){
        return ;
    }
    queue<BinaryTreeNode*> p;
    p.push(root);
    p.push(NULL);
    
    while(!p.empty()){
        BinaryTreeNode*temp = p.front();
        p.pop();
        if(temp==NULL){
            cout<<endl;
            if(!p.empty()){
                p.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
               p.push(temp->left);
            }
            if(temp->right!=NULL){
                p.push(temp->right);
            }
        }
       
    }

}

void ReversalOrderTraversal(BinaryTreeNode*root){
    queue<BinaryTreeNode*>q;
    stack<BinaryTreeNode*>s;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode*temp =q.front();
        q.pop();
        s.push(temp);
        if(temp==NULL){
            s.push(NULL);
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
             if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
        
    }
    while(!s.empty()){
        BinaryTreeNode*temp = s.top();
        if(temp== NULL){
            s.pop(); 
            cout<<endl;
        }
        else{ cout<<temp->data<<" ";
         s.pop();}
    }

}

BinaryTreeNode* BuildTree(BinaryTreeNode*root){
   
    cout<<"Enter Data"<<endl;
    int data;
    cin>>data;
    root= new BinaryTreeNode(data);
    if(data==-1){
        return NULL;
    }
    
        cout<<"Enter left child of "<<root->data<<endl;
       root->left = BuildTree(root->left);
        cout<<"Enter right child of "<<root->data<<endl;
       root->right = BuildTree(root->right);
    
    return root;
}

int main(){
BinaryTreeNode*root = NULL;
root=BuildTree(root);
//printTree(root);
ReversalOrderTraversal(root);
}