#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};


Node <int>* constructLinkedlist(BinaryTreeNode<int>*root){
    
    
    if(root ==NULL){
        Node <int>*head = NULL;
        return NULL;  
    }
    
    Node<int>*head = constructLinkedlist(root->left);
    Node<int>*rootN = new Node<int>(root->data);
    Node<int>*rhead = constructLinkedlist(root->right);
    rootN->next=rhead;
    Node<int>*temp =head;
    while(temp!=NULL){
        temp=temp->next;
    }
    Node<int>*ltail= temp;
    ltail->next = rootN;
    return head;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedlist(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}