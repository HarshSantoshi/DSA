#include <iostream>
#include <queue>
#include<limits.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
template <typename T>
class Node{
    public:
    T data;
    Node <T>*next;
    Node(T data){
        this ->data = data;
       this-> next=NULL;
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


BinaryTreeNode<int> *TakeInputLevelWise()
{
    cout << "Enter root Data" << endl;
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *curr = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the left child of " << curr->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            curr->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter the right child of " << curr->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            curr->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void print(Node<int>*head){
    Node<int>* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<endl;
}

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root){
     vector<Node<int>*>v;
    if(root==NULL){
        v.push_back(NULL);
        return v;
    }
    queue<BinaryTreeNode<int>*>q ;
    q.push(root);
    q.push(NULL);
    Node<int>*head = NULL;
    Node<int>*tail = NULL;
    while(q.size()!=0){
        BinaryTreeNode<int>*front = q.front();
        q.pop();
        if(front==NULL){
            tail->next = NULL;
            if(q.size()==0){
                break;
            }
            q.push(NULL);
            head =NULL;
            tail==NULL;
        }
        else{
            Node<int>* n = new Node<int>(front->data);
            if(head==NULL){
                head=n;
                tail=n;
                v.push_back(head);
            }
            else{
                tail->next=n;
                tail=n;
            }
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}

int main(){
    BinaryTreeNode<int> *root = TakeInputLevelWise();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);
    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}

