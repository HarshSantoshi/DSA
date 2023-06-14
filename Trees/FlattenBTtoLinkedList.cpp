//https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_articlehttps://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution
{
    public:
    Node*find(Node*curr){
        Node * temp =curr->left;
        while(temp->right != NULL){
            temp = temp->right;
        }
        return temp;
    }
    void Morris(Node * root , Node*LL){
        if(root==NULL){
            return ;
        }
        Node * curr = root;
        while(curr){
            if(curr->left){
               Node * prev = curr->left;
               Node * pred = find(curr);
               
               pred->right = curr->right;
               curr->right = prev;
                curr->left = NULL;
               
            }
            curr = curr->right;
            
        }
    }
    void flatten(Node *root)
    {
        //code here
        Node * linkedList = NULL;
        Morris(root , linkedList);
        return ; 
    }
};
