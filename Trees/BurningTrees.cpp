// https://practice.geeksforgeeks.org/problems/burning-tree/1?track=amazon-trees
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void findParent(Node * root , Node * parent ,map<Node* , Node*>&NodeToParent){
        if(root==NULL){
            return ;
        }
        NodeToParent[root] = parent;
        findParent(root->left , root , NodeToParent);
        findParent(root->right , root , NodeToParent);
        
    }
    Node * findTarget(Node * root , int target){
        if(root==NULL){
            return NULL;
        }
        if(root->data == target){
            return root;
        }
        Node * leftAns = findTarget(root->left , target);
        Node * rightAns = findTarget(root->right , target);
        if(leftAns != NULL && rightAns == NULL){
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }
        else if(leftAns != NULL && rightAns != NULL){
            return root;
        }
        else{
            return NULL;
        }
        
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node * , Node * > NodeToParent;
        findParent(root ,NULL, NodeToParent);
        Node * targetNode =findTarget(root , target);
        queue<Node * >q;
        q.push(targetNode);
        map<Node* , bool>vis;
        vis[targetNode] = true;
        int time =0;
        
        bool pushed = false;
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                 Node * curr = q.front();
                 q.pop();
                if(curr->left && vis[curr->left]==false){
                    q.push(curr->left);
                    pushed = true;
                    vis[curr->left] = true;
                    
                }
                if(curr->right && vis[curr->right] == false){
                    q.push(curr->right);
                    pushed = true;
                    vis[curr->right] = true;
                    
                }
                if(NodeToParent[curr]!=NULL && vis[NodeToParent[curr]]==false){
                    q.push(NodeToParent[curr]);
                    pushed  =true;
                    vis[NodeToParent[curr]]= true;
                    
                }
                size--;
            }
            if(pushed==true){
                
                time++;
               
                pushed = false;
            }
        }
        return time;
    }
};
