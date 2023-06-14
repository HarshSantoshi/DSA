
//https://leetcode.com/problems/binary-tree-inorder-traversal/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int>ans;
    //     inorder(root,ans);
    //     return ans;
    // }
    // private:
    // void inorder(TreeNode*root , vector<int>&ans){
    //     if(root==NULL){
    //         return ;
    //     }
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);
    //     return ;
    // }
    TreeNode * find(TreeNode * root){
        TreeNode * temp =root;
        temp= temp->left;
        while(temp->right!=NULL && temp->right!=root){
            temp =temp->right;
        }
        return temp;
    }
    vector<int>MorrisTraversal(TreeNode*root){
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        TreeNode * curr = root;
        while(curr!=NULL){
            if(curr->left){
                TreeNode * pred = find(curr);
                if(pred->right == NULL){
                    pred->right = curr;
                    curr=curr->left;
                }
                else{
                    ans.push_back(curr->val);
                    pred->right = NULL;
                    curr=curr->right;
                }
            }
            else{
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans ;
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int>ans = MorrisTraversal(root);
        return ans;
    }
};