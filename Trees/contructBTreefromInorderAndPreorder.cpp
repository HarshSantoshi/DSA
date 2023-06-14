//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
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
    int findIndex(int ele , vector<int>&inorder , int n){
        for(int i=0;i<n;i++){
            if(inorder[i] == ele){
                return i;
            }
        }
        return -1;
    }
    TreeNode * solve(vector<int>& preorder, vector<int>& inorder , int & index  , int inorderStart , int inorderEnd , int n){
        if(index>=n || inorderStart > inorderEnd){
            return NULL;
        }
        int ele  = preorder[index++];
        TreeNode * root = new TreeNode (ele);
        int pos = findIndex(ele , inorder , n);
        root->left = solve(preorder , inorder , index , inorderStart , pos-1 , n);
        root->right = solve(preorder , inorder, index , pos+1 , inorderEnd , n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        int n = inorder.size();
        TreeNode * root = solve( preorder , inorder , preorderIndex , 0 , n-1 , n);
        return root;
    }
};